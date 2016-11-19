#ifndef COMMAND_INTERPRETER_HH
#define COMMAND_INTERPRETER_HH

#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "commandInterpreter.hh"
#include "pluginHandler.hh"

/**
 * \brief Klasa do zarządzania plikiem z komendami sterującymi dronem
 *
 * Odczytuje plik linia po linii i wywołuje odpowiednie pluginy.
 */
class CommandInterpreter {
  /**
   * \brief Wskaznik do zarządcy pluginami.
   *
   * Definiowany w konstruktorze.
   */
  std::unique_ptr<PluginHandler> _pluginHandler;

public:
  /**
   * \brief Konstruktor.
   *
   * Przypisuje pola podane w argumentach funkcji do pól klasy.
   *
   */
  CommandInterpreter();

  /**
   *  \biref Rozpoczyna przetwarzanie komend.
   *
   *  Interpretuje komendy zawrte w pliku na które wskazuje \link _commandFile
   * \endlink
   *
   * \param[in] commandFile - strumien na plik wejściowy z komendami sterującymi
   * dronem
   */
  void interprete(std::istringstream *commandFile);

  PluginHandler * getPluginHandler();
};

#endif // COMMAND_INTERPRETER_HH
