#include "Interp4Rotate.hh"

#include <iostream>

extern "C" {
Interp4Command *CreateCmd(void);
}

Interp4Command *CreateCmd(void) { return Interp4Rotate::CreateCmd(); }

Interp4Rotate::Interp4Rotate()
    : _velocity_angular_degPs(0.0), _angle_deg(0.0) {}

void Interp4Rotate::PrintCmd() const {
  std::cout << GetCmdName() << " " << _velocity_angular_degPs << " "
            << _angle_deg << std::endl;
}

// TODO move filed names to static strings
void Interp4Rotate::PrintSyntax() const {
  std::cout << "   Rotate  angular_velocity[deg/s]  angle[deg]" << std::endl;
}

const char *Interp4Rotate::GetCmdName() const { return "Rotate"; }

bool Interp4Rotate::ExecCmd(DronePose *pRobPose, Visualization *pVis) const {
  double dAng_deg;

  dAng_deg = _velocity_angular_degPs * TIME_INTERVAL_MS / 1000.0;

  double actualRotated = 0;
  while (actualRotated < _angle_deg) {
    if(_velocity_angular_degPs < 0){
      actualRotated -= dAng_deg;
    } else {
      actualRotated += dAng_deg;
    }

    pRobPose->AddAngle_deg(dAng_deg);
  }

  return true;
}

bool Interp4Rotate::ReadParams(std::istringstream &istream) {

  std::string param;

  // TODO make the fieldNames static!
  istream >> param;
  setField(param, _velocity_angular_degPs, "angular_velocity",
           "Podaj dodatnią liczbę zmiennoprzecinkową.");
  if (_velocity_angular_degPs == 0) {
    throw makeErrorComunicate(param, "angular_velocity",
                              "Prędkość kątowa musi być różna od 0.0.");
  }

  istream >> param;
  setField(param, _angle_deg, "_angle_deg", "Podaj liczbę zmiennoprzecinkową.");
  if (_angle_deg <= 0) {
    throw makeErrorComunicate(param, "_angle_deg", "Kąt musi być dodatni.");
  }

  return true;
}

// TODO change to unique_ptr
/*!
 *
 */
Interp4Command *Interp4Rotate::CreateCmd() { return new Interp4Rotate(); }

// TODO conver to static string
// TODO update ReadParams
/*!
 *
 */
