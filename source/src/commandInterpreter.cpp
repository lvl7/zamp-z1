#include "commandInterpreter.hh"

CommandInterpreter::CommandInterpreter(Visualizer *visualizer):
  _visualizer(visualizer)
    {
      std::unique_ptr<PluginHandler> pluginHandler(new PluginHandler());
      _pluginHandler = std::move(pluginHandler);

      std::unique_ptr<DronePose> dronePose(new DronePose());
      _dronePose = std::move(dronePose);
    }


void CommandInterpreter::interprete(std::istringstream *commandFile){



  std::istringstream &str(*commandFile);
  std::string command;

  Interp4Command * plugin;

  while(str >> command){

    plugin = _pluginHandler->getPluginByName(command);

    if(!plugin){
      std::string errorComunicate = "Brak wtyczki obsługującej polecenie: [";
      errorComunicate += command;
      errorComunicate += "]";
      throw errorComunicate;
    }

    plugin->ReadParams(str);
    plugin->ExecCmd( _dronePose.get(), nullptr);
  }
};

PluginHandler * CommandInterpreter::getPluginHandler(){
  return _pluginHandler.get();
}
