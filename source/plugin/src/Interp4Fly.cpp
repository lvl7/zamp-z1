#include "Interp4Fly.hh"
#include <iostream>

using std::cout;
using std::endl;

extern "C" {
Interp4Command *CreateCmd(void);
}

Interp4Command *CreateCmd(void) { return Interp4Fly::CreateCmd(); }

Interp4Fly::Interp4Fly() {}

void Interp4Fly::PrintCmd() const {
  cout << GetCmdName() << " " << _speedHorizontal_mPs << " "
       << _speedVertical_mPs << " " << _distance_m << endl;
}

const char *Interp4Fly::GetCmdName() const { return "Fly"; }

bool Interp4Fly::ExecCmd(DronePose *pRobPose, Visualization *pVis) const {
  double dx, dy, dz, dL;
  dx = _speedHorizontal_mPs * TIME_INTERVAL_MS/1000 * cos(pRobPose->GetAngle_deg() * PI_MATH_CONST / 180);
  dy = _speedHorizontal_mPs * TIME_INTERVAL_MS/1000 * sin(pRobPose->GetAngle_deg() * PI_MATH_CONST / 180);
  dz = _speedVertical_mPs * TIME_INTERVAL_MS/1000;

  dL = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));

  double flyedDistance =0;
  while(flyedDistance < _distance_m){
    flyedDistance += dL;
    pRobPose->AddDeltaPos_m(dx, dy, dz);
  }
  pRobPose->AddDeltaPos_m(dx, dy, dz);


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
  setField(param, _distance_m, "dist");


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
