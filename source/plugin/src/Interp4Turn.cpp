#include "Interp4Turn.hh"

#include <iostream>

extern "C" {
Interp4Command *CreateCmd(void);
}

Interp4Command *CreateCmd(void) { return Interp4Turn::CreateCmd(); }

Interp4Turn::Interp4Turn() : _velocity_mPs(0.0), _arc_m(0.0), _radius_m(0.0) {}

void Interp4Turn::PrintCmd() const {
  std::cout << GetCmdName() << " " << _velocity_mPs << " " << _arc_m << " "
            << _radius_m << std::endl;
}

// TODO move filed names to static strings
void Interp4Turn::PrintSyntax() const {
  std::cout << "   Turn  velocity[m/s]  arc[m/s]  radius[m]" << std::endl;
}

const char *Interp4Turn::GetCmdName() const { return "Turn"; }

bool Interp4Turn::ExecCmd(DronePose *pRobPose, Visualization *pVis) const {
  Wektor3D *center = new Wektor3D();

  if (_radius_m > 0) { // lecimy w lewo
    center->x() = pRobPose->GetPos_m().x() +
                  _radius_m * cos((pRobPose->GetAngle_deg() + 90) *
                                  PI_MATH_CONST / 180.0);
    center->y() = pRobPose->GetPos_m().y() +
                  _radius_m * sin((pRobPose->GetAngle_deg() + 90) *
                                  PI_MATH_CONST / 180.0);
  } else { // lecimy w prawo
    center->x() = pRobPose->GetPos_m().x() -
                  _radius_m * cos((pRobPose->GetAngle_deg() - 90) *
                                  PI_MATH_CONST / 180.0);
    center->y() = pRobPose->GetPos_m().y() -
                  _radius_m * sin((pRobPose->GetAngle_deg() - 90) *
                                  PI_MATH_CONST / 180.0);
  }
  double deltaArc_m = _velocity_mPs * TIME_INTERVAL_MS / 1000.0;
  double ang_rad = deltaArc_m / _radius_m;
  double angArcTarget_rad = _arc_m / _radius_m;
  double currentAng_rad = 0;

  double newX, newY;
  double oldZ = pRobPose->GetPos_m().z();
  double newAngle;

  while (true) {
    currentAng_rad += ang_rad;

    if (_radius_m < 0 && currentAng_rad < angArcTarget_rad){
      break;
    }
    else if (_radius_m > 0 && currentAng_rad > angArcTarget_rad){
      break;
    }

    newAngle =
        pRobPose->GetAngle_deg() + (ang_rad * 180 / (float)PI_MATH_CONST);

    newX = center->x() + _radius_m * cos((newAngle - 90) * PI_MATH_CONST / 180);
    newY = center->y() + _radius_m * sin((newAngle - 90) * PI_MATH_CONST / 180);

    pRobPose->SetPos_m_deg(newX, newY, oldZ, newAngle);

  }

  delete center;
  return true;
}

bool Interp4Turn::ReadParams(std::istream &istream) {

  std::string param;

  // TODO make the fieldNames static!
  istream >> param;
  setField(param, _velocity_mPs, "velocity",
           "Podaj dodatnią liczbę zmiennoprzecinkową.");
  if (_velocity_mPs <= 0) {
    throw makeErrorComunicate(param, "hor_velocity",
                              "Prędkość musi być dodatnia.");
  }

  istream >> param;
  setField(param, _arc_m, "arc", "Podaj liczbę zmiennoprzecinkową.");
  if (_arc_m <= 0) {
    throw makeErrorComunicate(param, "arc", "Długość łuku musi być dodatnia.");
  }

  istream >> param;
  setField(param, _radius_m, "radius", "Podaj liczbę zmiennoprzecinkową.");
  if (_radius_m == 0) {
    throw makeErrorComunicate(param, "arc", "Promień nie może być równy 0.0.");
  }

  return true;
}

// TODO change to unique_ptr
/*!
 *
 */
Interp4Command *Interp4Turn::CreateCmd() { return new Interp4Turn(); }

// TODO conver to static string
// TODO update ReadParams
/*!
 *
 */
