#include "Interface.hh"

Interface::Interface(std::istream &istream, std::ostream &ostream, Io *io)
    : _istream(istream), _ostream(ostream), _io(io) {

  initMainMenu();
}

void Interface::initMainMenu() {
  mainMenuFeatures.push_back(std::make_pair(
      "w", "wczytaj plik z sekwencą instrukcji dla drona o podanej nazwie"));
  mainMenuFeatures.push_back(std::make_pair("g", "wykonaj program"));
  mainMenuFeatures.push_back(std::make_pair("k", "zakończ program"));
}

void Interface::printMainMenu() {
  for (auto &commend : mainMenuFeatures) {
    _ostream << " " << commend.first << "  -  " << commend.second << std::endl;
  }
}

void Interface::getCommandAndExecute() {
  std::string commandKey;

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
    _ostream << "chose k" << std::endl;
    break;
  case 'g':
    _ostream << "chose g" << std::endl;
    break;
  default:
    std::string errorComunicate = "Nieobsługiwane polecenie [";
    errorComunicate += commandKey[0];
    errorComunicate += "]";

    throw errorComunicate;
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
}
