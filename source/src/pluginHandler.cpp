#include "pluginHandler.hh"

PluginHandler::PluginHandler() { loadPlugins(); }
PluginHandler::~PluginHandler() {
  //TODO make core dump
  // for (auto &plg : _plugins) {
  //
  //   dlclose(plg.second);
  // }
}

void PluginHandler::loadPlugins() {
  // std::ofstream coordFile;
  // coordFile.open("coords.txt");
  //
  //
  // std::unique_ptr<DronePose> drone(new DronePose);

  // TODO change to find names in the plugins folder
  std::vector<const char *> plugins;
  plugins.push_back("libInterp4Fly.so");
  plugins.push_back("libInterp4Rotate.so");
  plugins.push_back("libInterp4Turn.so");

  for (auto &pluginName : plugins) {
    void *lib = dlopen(pluginName, RTLD_LAZY);

    if (!lib) {
      std::string errorComunicate;
      errorComunicate += "Biblioteka nieznana: [";
      errorComunicate += pluginName;
      errorComunicate += "]";
      throw errorComunicate;
    }

    void *function;
    const char *functionName = "CreateCmd";
    function = dlsym(lib, functionName);
    if (!function) {
      std::string errorComunicate;
      errorComunicate += "Nie znaleziono polecenia: [";
      errorComunicate += functionName;
      errorComunicate += "]";
      throw errorComunicate;
    }

    Interp4Command *(*commandCreate)(void);
    commandCreate = *reinterpret_cast<Interp4Command *(**)(void)>(&function);

    Interp4Command *command = commandCreate();

    _plugins[command->GetCmdName()] = command;
  }
}

Interp4Command *PluginHandler::getPluginByName(std::string name) {
  auto result = _plugins.find(name);

  if (result != _plugins.end()) {
    return result->second;
  }
  return nullptr;
}
