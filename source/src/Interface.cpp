#include "Interface.hh"

Interface::Interface(std::istream &istream, std::ostream &ostream)
    : _istream(istream), _ostream(ostream) {


      mainMenuFeatures.push_back(std::make_pair("w", "wczytanie nazwy pliku sekwencji instrukcji dla drona."));
    }

void Interface::printMainMenu() { std::cout << "/* message */" << std::endl; }
