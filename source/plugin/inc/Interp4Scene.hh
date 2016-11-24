#ifndef INTERP_4_SCENE_HH
#define INTERP_4_SCENE_HH

#ifndef __GNUG__
#pragma interface
#pragma implementation
#endif

#include "Interp4Command.hh"
#include <cmath>
#include <sstream>
#include <memory>
#include <utility>

#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>

#include "xmlparser4scene.hh"



// TODO
/*!
 * \brief Zapewnia funkcje pozwalające na wczytanie sceny
 *
 *
 */
class Interp4Scene : public Interp4Command {
private:
  // /**
  //  * \brief parser dla plików xml modelujących scene
  //  */
  // std::unique_ptr<XMLParser4Scene> _xmlParser;

  /**
   * \brief nazwa pliku xml w którym zdefiniowane są nieruchome na scenie
   */
  std::string _scenePath_xml;

public:
  // TODO
  /*!
     * \brief
     */
  Interp4Scene();
  // TODO
  /*!
     * \brief
     */
  virtual void PrintCmd() const;
  // TODO
  /*!
     * \brief
     */
  virtual void PrintSyntax(std::ostream &ostr) const;
  // TODO
  /*!
     * \brief
     */
  virtual const char *GetCmdName() const;

  /**
   * \brief Interpretuje plik ze sceną
   *
   * Parsuje plik xml zawierający opis sceny za pomoca biblioteki Xercesc.
   *
   */
  virtual bool ExecCmd(DronePose *pRobPose, Visualizer *pVis) const;
  // TODO
  /*!
     * \brief
     */
  virtual bool ReadParams(std::istringstream &Strm_CmdsList);
  // TODO
  /*!
     * \brief
     */
  virtual void PrintParams() {}
  // TODO
  /*!
     * \brief
     *
     *  Ta metoda nie musi być zdefiniowna w klasie bazowej.
     */
  static Interp4Command *CreateCmd();
};

#endif // INTERP_4_SCENE_HH
