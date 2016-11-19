#ifndef COMMAND_INTERPRETER_HH
#define COMMAND_INTERPRETER_HH

#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "commandInterpreter.hh"
#include "pluginHandler.hh"
#include "visualizer.hh"

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


  /**
   * \brief Wskaźnik do zarządcy przechowującego współrzędne drona.
   *
   * Definiowany w konstruktorze.
   */
    std::unique_ptr<DronePose> _dronePose;

    /**
     * \brief Wskaźnik do obiektu zarządzającego wizualizacją
     *
     * Przychodzi jako parametr w konstruktorze.
     */
    Visualizer *_visualizer;

public:
  /**
   * \brief Konstruktor.
   *
   * Przypisuje pola podane w argumentach funkcji do pól klasy.
   *
   */
  CommandInterpreter(Visualizer *_visualizer);

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
