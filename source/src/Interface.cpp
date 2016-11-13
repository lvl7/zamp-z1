#include "Interface.hh"

Interface::Interface(std::istream &istream, std::ostream &ostream)
    : _istream(istream), _ostream(ostream) {

  std::unique_ptr<Io> io(new Io());
  _io = std::move(io);

  std::unique_ptr<CommandInterpreter> commandInterpreter(
      new CommandInterpreter());

      _commandInterpreter = std::move(commandInterpreter);


  // std::unique_ptr<CommandInterpreter> commandInterpreter(new
  // CommandInterpreter());
  initMainMenu();
}

void Interface::initMainMenu() {
  mainMenuFeatures.push_back(std::make_pair(
      "w", "wczytaj plik z sekwencją instrukcji dla drona o podanej nazwie"));
  mainMenuFeatures.push_back(std::make_pair("g", "wykonaj program"));
  mainMenuFeatures.push_back(std::make_pair("k", "zakończ program"));
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
  case 'k':
    end = true;
    break;
  case 'g':
    try{
      _commandInterpreter->interprete(_commandFile);
      std::cout << "Wygenerowano plik ze wspórzędnymi" << std::endl;
    }
    catch(std::string s){
      std::cerr << s << std::endl;
      end = true;
    }

    break;
  default:
    std::string errorComunicate = "Nieobsługiwane polecenie [";
    errorComunicate += commandKey[0];
    errorComunicate += "]";

    throw errorComunicate;
  }

  if(!end){
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
