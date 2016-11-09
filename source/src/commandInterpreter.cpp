#include "commandInterpreter.hh"

CommandInterpreter::CommandInterpreter(std::iostream *commandFile,
                                       PluginHandler *pluginHandler)
    : _commandFile(commandFile), _pluginHandler(pluginHandler) {}


void CommandInterpreter::interprete(){

};
