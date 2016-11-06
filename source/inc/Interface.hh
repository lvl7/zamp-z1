#ifndef INTERFACE_HH
#define INTERFACE_HH

#include <iostream>
#include <limits>
#include <utility>
#include <vector>

#include "io.hh"

// TODO opis
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
  Io *_io;

public:
  /**
   * \brief Konstruktor.
   *
   * Ustawia strumienie przez które będą pobierane polecenia i wysyłane menu.
   * Defiuniuje menu główne. Domyślnymi parametrami są strumienie standardowe
   *
   * \param[in] istream - srumień z którego będą pobierane polecenia
   * \param[out] ostream - srumień na który będzie wyświetlane menu
   * \param[int/out] io - wskaźnik na klasę odpowiedzialną za pobieranie i
   * zapisywanie do plików
   */
  Interface(std::istream &istream = std::cin, std::ostream &ostream = std::cout,
            Io *io = NULL);

  /**
   * \brief Zawiera możliwe do wyboru opcje.
   *
   *  Dodaje do zbioru opcji opcje. Klucz oraz treść.
   */
  void initMainMenu();
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
};

#endif // INTERFACE_HH
