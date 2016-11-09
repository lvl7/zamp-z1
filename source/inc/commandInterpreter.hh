#ifndef COMMAND_INTERPRETER_HH
#define COMMAND_INTERPRETER_HH

#include <iostream>



#include "commandInterpreter.hh"
#include "pluginHandler.hh"

/**
 * \brief Klasa do zarządzania plikiem z komendami sterującymi dronem
 *
 * Odczytuje plik linia po linii i wywołuje odpowiednie pluginy.
 */
class CommandInterpreter {

  /**
   * \brief Przechowuje strumien wejściowy pliku z komendami
   *
   * Określony poprzez \link Io::openCommandsFile(const char *fileName);
   * \endlink
   */
  std::istream *_commandFile;

  /**
   * \brief Wskaznik do zarządcy pluginami.
   *
   * Definiowany w konstruktorze.
   */
  PluginHandler *_pluginHandler;

public:
  /**
   * \brief Konstruktor.
   *
   * Przypisuje pola podane w argumentach funkcji do pól klasy.
   *
   * \param[in] commandFile - strumien na plik wejściowy z komendami sterującymi
   * dronem
   * \param[out] pluginHandler - do wywoływania wtyczek
   */
  CommandInterpreter(std::iostream *commandFile, PluginHandler *pluginHandler);

  /**
   *  \biref Rozpoczyna przetwarzanie komend.
   *
   *  Interpretuje komendy zawrte w pliku na które wskazuje \link _commandFile
   * \endlink
   */
  void interprete();

};

#endif // COMMAND_INTERPRETER_HH
