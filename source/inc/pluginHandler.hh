#ifndef PLUGIN_HANDLER_HH
#define PLUGIN_HANDLER_HH

#include <dlfcn.h>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "Interp4Command.hh"

/**
 * \brief Klasa obsługuje zbiór wtyczek
 *
 * Przechowuje oraz zarządza wtyczkami.
 */
class PluginHandler {
private:
  /**
   * \brief Wektor map wtyczek.
   *
   * Mapa par wtyczek (patrz \link Interp4Command \endlink) ze wskaźnikiem na
   * definicje metod wczytanych przez dlopen w funkcji \link loadPlugins()
   * \endlink. Kluczem nazwa komendy.
   */
  std::map<std::string, std::pair<Interp4Command *, void *>> _plugins;

public:
  /**
   * \brief Konstruktor.
   *
   * Wypełnia \link _plugins \endlink wtyczkami (patrz \link loadPlugins()
   * \endlink ).
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
   * \return     nullptr jeśli nie znaleziono pluginu o nazwie \link name
   * \endlink
   */
  Interp4Command *getPluginByName(std::string name);

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
