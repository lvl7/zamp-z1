#ifndef PLUGIN_HANDLER_HH
#define PLUGIN_HANDLER_HH

#include <map>
#include <string>
#include <vector>
#include <dlfcn.h>

#include "Interp4Command.hh"

/**
 * \brief Klasa obsługuje zbiór wtyczek
 *
 * Przechowuje oraz zarządza wtyczkami.
 */
class PluginHandler {
private:
  /**
   * \brief wektor map wtyczek
   *
   * mapa wtyczek (patrz \link Interp4Command \endlink). Kluczem jest
   * nazwa komendy.
   */
  std::map<std::string, Interp4Command* > _plugins;

public:
  /**
   * \brief Konstruktor.
   *
   * Wypełnia \link _plugins \endlink wtyczkami (patrz \link loadPlugins() \endlink ).
   */
  PluginHandler();

  /**
   * Destruktor
   *
   * Zwalnia wszystkie pluginy
   */
  ~PluginHandler();

  /**
   * \brief Zwraca wskaźnik na plugin o nazwie \link name \endlink
   *
   *
   * \param[in]  name  - nazwa pluginu
   * \return     wskaźnik na plugin (patrz \link Interp4Command \endlink)
   * \return     nullptr jeśli nie znaleziono pluginu o nazwie \link name \endlink
   */
  Interp4Command * getPluginByName(std::string name);

private:
  /**
   * \brief Wczytuje wtyczki
   *
   * Wczytuje wtyczi i wypełnia nimi \link _plugins \endlink
   *
   * \throws string - komunikat w przypadku błędnej nazwy wtyczki
   */
  void loadPlugins();

};



#endif // PLUGIN_HANDLER_HH
