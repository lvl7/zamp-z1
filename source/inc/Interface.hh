#ifndef INTERFACE_HH
#define INTERFACE_HH

#include <iostream>
#include <limits>
#include <utility>
#include <vector>

#include <cstdlib>
#include <memory>
#include <readline/history.h>
#include <readline/readline.h>
#include <sstream>

#include "commandInterpreter.hh"
#include "io.hh"
#include "visualizer.hh"


/**
 * \brief Klasa definiująca interface programu.
 *
 * Zapewnia interakcje z użytkownikiem. Wyświetla menu, wczytuje odpowiedzi.
 * Wywołuje odpowiednie metody by spełnić polecenia wydane przez użytkownika.
 */
class Interface {
private:
  /**
   * \brief Definiuje skąd będą pobierane odpowiedzi.
   *
   * Określany przez konstruktor.
   */
  std::istream &_istream;

  /**
   * \brief Definiuje na jaki strumień menu będzie wyświetlane.
   *
   * Określany przez konstruktor.
   */
  std::ostream &_ostream;

  /**
   * \brief Przechowuje strumien wejściowy pliku z komendami
   *
   * Określony poprzez \link Io::openCommandsFile(const char *fileName);
   * \endlink
   */
  std::istringstream *_commandFile;

  /**
   * \brief Przechowuje dostępne polecenia w menu głównym
   *
   * Tablica par składających się z klucza odpowiedzi oraz opisu polecenia.
   */
  std::vector<std::pair<std::string, std::string>> mainMenuFeatures;

  /**
   * \brief zarządza plikami
   *
   * Wskaźnik do klasy \link Io \endlink.
   */
  std::unique_ptr<Io> _io;

  /**
   * \biref Wskaźnik do interpretora pliku zawierającego komendy sterowania
   * dronem
   *
   * Definiowany w konstruktorze.
   */
  std::unique_ptr<CommandInterpreter> _commandInterpreter;

  /**
   * \biref Wskaźnik na obiekt odpowiedzialny za wizualizację przelotu drona
   *
   * Definiowany w konstruktorze.
   */
  std::unique_ptr<Visualizer> _visualizer;

public:
  /**
   * \brief Konstruktor.
   *
   * Ustawia strumienie przez które będą pobierane polecenia i wysyłane menu.
   * Defiuniuje menu główne. Domyślnymi parametrami są strumienie standardowe
   *
   * \param[in] istream - srumień z którego będą pobierane polecenia
   * \param[out] ostream - srumień na który będzie wyświetlane menu
   */
  Interface(std::istream &istream = std::cin,
            std::ostream &ostream = std::cout);
  /**
   * \brief Drukuje menu z dostepnymi opcjami
   *
   * Dostępne opcje zdefiniowane są w initMainMenu().
   */
  void printMainMenu();

  /**
   * \biref Pobiera od użytkownika odpowiedz.
   *
   * Pobiera od użytkownika klucz do polecenia z menu głównego oraz wykonuje
   * polecenie.
   *
   * \throws string - Kiedy podana przez użytkownika komenda jest pusta
   * \throws string - Kiedy polecenie jest nieznane
   */
  void getCommandAndExecute();

private:
  /**
   * \brief Zawiera możliwe do wyboru opcje.
   *
   *  Dodaje do zbioru opcji opcje. Klucz oraz treść.
   */
  void initMainMenu();

  /**
   * \brief Wypisuje komunikat z prośbą o podanie nazwy pliku oraz go otwiera.
   *
   * Wypisuje komunikat oraz otwiera plik za pomocą klasy \link Io \endlink
   */
  void readCommandFile();

  /**
   * \brief Pokazuje dostepne komendy.
   *
   * Wyswietla wszystkie pluginy załączone w \link _commandInterpreter \endlink wraz
   * z ich argumentami wywolania.
   */
  void showAvailableCommands();
};

#endif // INTERFACE_HH
