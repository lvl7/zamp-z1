#include "Interp4Fly.hh"
#include <iostream>

using std::cout;
using std::endl;

extern "C" {
Interp4Command *CreateCmd(void);
}

// TODO
/*!
 * \brief
 *
 *
 */
Interp4Command *CreateCmd(void) { return Interp4Fly::CreateCmd(); }

// TODO
/*!
 *
 */
Interp4Fly::Interp4Fly() {}

// TODO
/*!
 *
 */
void Interp4Fly::PrintCmd() const {
  /*
 *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
 */
  cout << GetCmdName() << " " << _speedHorizontal_mPs << " "
       << _speedVertical_mPs << " " << _distanceRemain_m << endl;
}

// TODO
/*!
 *
 */
const char *Interp4Fly::GetCmdName() const { return "Fly"; }

// TODO
/*!
 *
 */
bool Interp4Fly::ExecCmd(DronPose *pRobPose, Visualization *pVis) const {
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}

bool Interp4Fly::ReadParams(std::istream &istream) {

  std::string param;

  //TODO make the fieldNames static!
  istream >> param;
  setField(param, _speedHorizontal_mPs, "hor_speed");
  istream >> param;
  setField(param, _speedVertical_mPs, "ver_speed");
  istream >> param;
  setField(param, _distanceRemain_m, "dist");


  return true;
}

// TODO
/*!
 *
 */
Interp4Command *Interp4Fly::CreateCmd() { return new Interp4Fly(); }

// TODO conver to static string
// TODO update ReadParams
/*!
 *
 */
void Interp4Fly::PrintSyntax() const {
  cout << "   Fly  hor_speed[m/s]  ver_speed[m/s]  dist[m]" << endl;
}

// TODO move to Interp4Command
std::string Interp4Fly::makeErrorComunicate(std::string &errorParam,
                                            const char *filedName) {
  std::string errorComunicate = "Bad parameter: [ ";
  errorComunicate += errorParam;
  errorComunicate += " ] for ";
  errorComunicate += filedName;

  return errorComunicate;
}

// TODO move to Interp4Command
void Interp4Fly::setField(std::string &param, double &filed,
                          const char *fieldName) {
  try {
    filed = std::stod(param, NULL);
  } catch (...) {
    // TODO hor_speed should be static string, filed of class
    throw makeErrorComunicate(param, fieldName);
  }
}
