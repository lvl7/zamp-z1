#include "commandInterpreter.hh"

CommandInterpreter::CommandInterpreter()
    {
      std::unique_ptr<PluginHandler> pluginHandler(new PluginHandler());
      _pluginHandler = std::move(pluginHandler);
    }


void CommandInterpreter::interprete(std::istringstream *commandFile){

//TODO ----
  DronePose *pRobPose = new DronePose();
//TODO ====

  std::istringstream &str(*commandFile);
  std::string command;

  Interp4Command * plugin;

  while(str >> command){
    plugin = _pluginHandler->getPluginByName(command);
    plugin->ReadParams(str);
    plugin->ExecCmd( pRobPose, nullptr);
  }
};
