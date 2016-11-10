#ifndef INTERP_4_FLY_HH
#define INTERP_4_FLY_HH

#ifndef __GNUG__
#pragma interface
#pragma implementation
#endif

#include "Interp4Command.hh"
#include <cmath>
#include <sstream>


// TODO
/*!
 * \file
 * \brief Definicja klasy Interp4Fly
 *
 * Plik zawiera definicję klasy Interp4Fly ...
 */

// TODO
/*!
 * \brief Modeluje polecenie dla robota mobilnego, które wymusza jego ruch do
 * przodu
 *
 *  Klasa modeluje ...
 */
class Interp4Fly : public Interp4Command {

  /**
   * \brief Prędkość horyzontalna. W metrach na sekundę
   */
  double _velocityHorizontal_mPs;

  /**
   * \brief Prędkość werykalna. W metrach na sekundę
   */
  double _velocityVertical_mPs;

  /**
   * \brief Zadany do przelecenia dystans w metrach
   */
  double _distance_m;

public:
  // TODO
  /*!
     * \brief
     */
  Interp4Fly();
  // TODO
  /*!
     * \brief
     */
  virtual void PrintCmd() const;
  // TODO
  /*!
     * \brief
     */
  virtual void PrintSyntax() const;
  // TODO
  /*!
     * \brief
     */
  virtual const char *GetCmdName() const;
  // TODO
  /*!
     * \brief
     */
  virtual bool ExecCmd(DronePose *pRobPose, Visualization *pVis) const;
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

#endif //INTERP_4_FLY_HH
