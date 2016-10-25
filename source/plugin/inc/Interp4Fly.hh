#ifndef COMMAND4MOVE_HH
#define COMMAND4MOVE_HH

#ifndef __GNUG__
#pragma interface
#pragma implementation
#endif

#include "Interp4Command.hh"
#include <cmath>

#define PI_MATH_CONST 3.14159265359

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
  double _speedHorizontal_mPs;

  /**
   * \brief Prędkość werykalna. W metrach na sekundę
   */
  double _speedVertical_mPs;

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
  virtual bool ReadParams(std::istream &Strm_CmdsList);
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

private:
  /**
   * \brief make error comunicate for Interp4Fly::ReadParams(std::istream
   * &istream)
   * @param  errorParam the user's gived bad param
   * @param  paramName  a name of a field that tryied to be fielld
   * @return            the error comunicate
   */
  std::string makeErrorComunicate(std::string &errorParam,
                                           const char *filedName);


/**
 * \brief try set filed.
 *
 * Try set the param to field.
 * @throw const char * message Look Interp4Fly::makeErrorComunicate(std::string &errorParam, const char *filedName)
 *
 * @param param     the trying set value
 * @param filed     reference to a class's filed
 * @param fieldName name of the field
 */
  void setField(std::string & param, double & filed, const char * fieldName);

};

#endif
