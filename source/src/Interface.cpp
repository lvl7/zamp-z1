#include "Interface.hh"

#include <limits>

Interface::Interface(std::istream &istream, std::ostream &ostream)
    : _istream(istream), _ostream(ostream) {

      initMainMenu();
}

void Interface::initMainMenu(){
  mainMenuFeatures.push_back(std::make_pair(
      "w", "wczytanie nazwy pliku sekwencji instrukcji dla drona"));
  mainMenuFeatures.push_back(std::make_pair(
      "k", "zakończ program"));
}

void Interface::printMainMenu() {
  for (auto &commend : mainMenuFeatures) {
      _ostream << " "
               << commend.first
               << "  -  "
               << commend.second
               << std::endl;
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
    _ostream << "chose W" << std::endl;
    break;
  case 'k':
    _ostream << "chose k" << std::endl;
    break;
  default:
    std::string errorComunicate = "Nieobsługiwane polecenie [";
    errorComunicate += commandKey[0];
    errorComunicate += "]";

    throw errorComunicate;
  }
}
