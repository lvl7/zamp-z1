#include "Interface.hh"

Interface::Interface(std::istream &istream, std::ostream &ostream)
    : _istream(istream), _ostream(ostream) {

  std::unique_ptr<Io> io(new Io());
  _io = std::move(io);

  std::unique_ptr<Visualizer> visualizer(new Visualizer());
  _visualizer = std::move(visualizer);

  std::unique_ptr<CommandInterpreter> commandInterpreter(
      new CommandInterpreter(_visualizer.get()));

  _commandInterpreter = std::move(commandInterpreter);

  initMainMenu();
}

void Interface::initMainMenu() {
  mainMenuFeatures.push_back(std::make_pair(
      "w", "wczytaj plik z sekwencją instrukcji dla drona o podanej nazwie"));
  mainMenuFeatures.push_back(std::make_pair("g", "wykonaj program"));
  mainMenuFeatures.push_back(std::make_pair("p", "wyświetl dostępne komendy"));
  mainMenuFeatures.push_back(std::make_pair("q", "zakończ program"));
}

void Interface::printMainMenu() {
  _ostream << std::endl;
  for (auto &commend : mainMenuFeatures) {
    _ostream << " " << commend.first << "  -  " << commend.second << std::endl;
  }
}

void Interface::getCommandAndExecute() {
  std::string commandKey;

  bool end = false;

  _ostream << "Twój wybór (? - menu): ";

  _istream >> commandKey;
  if (commandKey.length() == 0) {
    throw "Puste polecenie!";
  }

  // TODO change commands to class with execute method.
  switch (commandKey[0]) {
  case 'w':
    readCommandFile();
    break;
  case 'q':
    end = true;
    break;
  case 'p':
    showAvailableCommands();
    break;
  case 'g':
    try {
      _commandInterpreter->interprete(_commandFile);
    } catch (std::string s) {
      std::cerr << s << std::endl;
      end = true;
    }

    break;
  default:
    _ostream << std::endl;

    std::string errorComunicate = "Nieobsługiwane polecenie [";
    errorComunicate += commandKey[0];
    errorComunicate += "]";
    _ostream << errorComunicate;

    _ostream << std::endl;
  }

  if (!end) {
    printMainMenu();
    getCommandAndExecute();
  }
}

void Interface::readCommandFile() {
  _ostream << "Podaj nazwę pliku: ";

  rl_bind_key('\t', rl_complete);

  char *fileName;

  fileName = readline(nullptr);

  std::istringstream response;
  response.str(fileName);
  free(fileName);

  std::string responseString;
  response >> responseString;

  // TODO cach wrong name
  _commandFile = _io->openCommandsFile(responseString.c_str());

  _ostream << "Wczytano pomyślnie." << std::endl;
}

void Interface::showAvailableCommands() {
  for (auto plugin : *_commandInterpreter->getPluginHandler()->getPlugins()) {
    plugin.second.first->PrintSyntax(_ostream);
  }
}
