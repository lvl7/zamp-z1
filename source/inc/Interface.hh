#ifndef INTERFACE_HH
#define INTERFACE_HH

#include <iostream>
#include <utility>
#include <vector>

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
   *  \brief Przechowuje dostępne polecenia w menu głównym
   *
   * Tablica par składających się z klucza odpowiedzi oraz opisu polecenia.
   */
  std::vector<std::pair<std::string, std::string>> mainMenuFeatures;

public:
  /**
   * \brief Konstruktor.
   *
   * Ustawia strumienie przez które będą pobierane polecenia i wysyłane menu.
   * Defiuniuje menu główne. Domyślnymi parametrami są strumienie standardowe
   *
   * @param[in] istream - srumień z którego będą pobierane polecenia
   * @param[out] ostream - srumień na który będzie wyświetlane menu
   */
  Interface(std::istream &istream = std::cin, std::ostream& ostream = std::cout);

  /**
   * \brief Drukuje menu z dostepnymi opcjami
   *
   */
  void printMainMenu();
};

#endif // INTERFACE_HH
