#ifndef INTERP_4_TUNR_HH
#define INTERP_4_TUNR_HH

#ifndef __GNUG__
#pragma interface
#pragma implementation
#endif

#include <cmath>

#include "Interp4Command.hh"
#include "Wektor3D.hh"


/*!
 * \brief Modeluje polecenie dla robota mobilnego, które wymusza jego ruch po
 * okregu o zadanym promieniu oraz prędkości.
 *
 * Nalezy ustawić prędkość, promień okręgu oraz dystans.
 * Co do promienia:
  * Wartość dodatnia oznacza iż dron skręca w prawo
  * Wartość ujemna oznacza iż dron skręca w lewo
  * Nie może być zerowy
 */
class Interp4Turn : public Interp4Command {
private:
  /**
   * \brief Prędkość drona. W metrach na sekundę
   *
   * Nie może być ujemna
   */
  double _velocity_mPs;

  /**
   * \biref Długoś łuku w metrach
   *
   * Musi być dodatnia
   */
  double _arc_m;

  /**
   * \brief Promień łuku w metrach
   *
   * Wartość dodatnia oznacza iż dron skręca w prawo
   * Wartość ujemna oznacza iż dron skręca w lewo
   * Nie może być zerowy
   */
  double _radius_m;

public:
  // TODO
  /*!
     * \brief
     */
  Interp4Turn();

  // TODO
  /*!
     * \brief
     */
  virtual void PrintCmd() const;
  // TODO
  /*!
     * \brief
     */
  virtual void PrintSyntax(std::ostream & ostr) const;
  // TODO
  /*!
     * \brief
     */
  virtual const char *GetCmdName() const;
  // TODO
  /*!
     * \brief
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

#endif // INTERP_4_TUNR_HH
