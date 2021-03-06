#ifndef INTERP_4_ROTATE_HH
#define INTERP_4_ROTATE_HH

#ifndef __GNUG__
#pragma interface
#pragma implementation
#endif

#include <cmath>
#include <unistd.h>

#include "Interp4Command.hh"

/*!
 * \brief Modeluje polecenie dla robota mobilnego, które wymusza jego ruch obrotowy.
 *
 * Nalezy ustawić kąt obrotu oraz prędkość.
 * Wartość kąta dodatnia wartość oznacza obrót w lewo.
 * Wartosć kąta ujemna wartość oznacza obrót w prawo.
 *
 */
class Interp4Rotate : public Interp4Command {
private:
  /**
   * \brief Prędkość obrotowa droga w osi Z. W stopniach na sekundę.
   *
   * Dodatnia wartość oznacza obrót w lewo.
   * Ujemna wartość oznacza obrót w prawo.
   *
   * Nie może być zerowa
   */
  double _velocity_angular_degPs;

  /**
   * \biref Kąt o jaki ma się obrucić dron w stopniach
   *
   * Musi być dodatnia
   */
  double _angle_deg;
public:
  // TODO
  /*!
     * \brief
     */
  Interp4Rotate();

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

#endif // INTERP_4_ROTATE_HH
