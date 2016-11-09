#ifndef IO_HH
#define IO_HH

#include <fstream>
/**
 * \brief klasa odpowiedzialna za komunikacje z plikami
 *
 * W tej klasie zostają otwierane oraz zamykane pliki.
 */
class Io {
private:
  /**
   * \brief Strumień z pliku z poleceniami sterowania dronem.
   *
   * Zawiera komendy takie jak no Fly (patrz klasy dziedziczące \link
   * Interp4Command \endlink )
   */
  std::ifstream _commandsStream;

public:
  /**
   * \brief Konstruktor klasy Io
   *
   * Konstruktor klasy Io
   */
  Io();

  /**
   * \brief Destruktor. Zamyka wszystkei otwarte strumienie
   *
   * Zamyka wszsytkie otwarte strumienie
   */
  ~Io();

  /**
   * \brief Otwiera plik z poleceniami dla drona.
   *
   * \param[in] fileName - nazwa otwieranego pliku
   *
   * \return wskaźnik do otwartego strumienia
   */
  std::istream * openCommandsFile(const char *fileName);

  /**
   * \brief Zwraca strumień do pluku otwartego przez \link openCommandsFile(const char *fileName) \endlink.
   *
   * \return wskaźnik do otwartego strumienia
   */
  std::istream * getCommandsStream();

};



#endif // IO_HH
