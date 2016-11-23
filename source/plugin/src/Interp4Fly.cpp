#include "Interp4Fly.hh"
#include <iostream>

extern "C" {
Interp4Command *CreateCmd(void);
}

Interp4Command *CreateCmd(void) { return Interp4Fly::CreateCmd(); }

Interp4Fly::Interp4Fly()
    : _velocityHorizontal_mPs(0.0), _velocityVertical_mPs(0.0),
      _distance_m(0.0) {}

void Interp4Fly::PrintCmd() const {
  std::cout << GetCmdName() << " " << _velocityHorizontal_mPs << " "
            << _velocityVertical_mPs << " " << _distance_m << std::endl;
}

const char *Interp4Fly::GetCmdName() const { return "Fly"; }

bool Interp4Fly::ExecCmd(DronePose *pRobPose, Visualizer *visualizer) const {
  double dx, dy, dz, dL;
  dx = _velocityHorizontal_mPs * TIME_INTERVAL_MS / 1000.0 *
       cos(pRobPose->GetAngle_deg() * PI_MATH_CONST / 180.0);
  dy = _velocityHorizontal_mPs * TIME_INTERVAL_MS / 1000.0 *
       sin(pRobPose->GetAngle_deg() * PI_MATH_CONST / 180.0);
  dz = _velocityVertical_mPs * TIME_INTERVAL_MS / 1000.0;

  dL = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));

  double flyedDistance = 0;
  while (flyedDistance < _distance_m) {
    flyedDistance += dL;
    pRobPose->AddDeltaPos_m(dx, dy, dz);
    usleep(TIME_INTERVAL_MS * 1000);
    visualizer->Draw(pRobPose);
  }
  pRobPose->AddDeltaPos_m(dx, dy, dz);
  usleep(TIME_INTERVAL_MS * 1000);
  visualizer->Draw(pRobPose);

  return true;
}

bool Interp4Fly::ReadParams(std::istringstream &istream) {

  std::string param;

  // TODO make the fieldNames static!
  istream >> param;
  setField(param, _velocityHorizontal_mPs, "hor_velocity", NULL);

  istream >> param;
  setField(param, _velocityVertical_mPs, "ver_velocity", NULL);

  istream >> param;
  setField(param, _distance_m, "dist", NULL);

  if ((_velocityHorizontal_mPs == 0 && _velocityVertical_mPs == 0) &&
      _distance_m != 0) {
    throw makeErrorComunicate(
        param, "distance",
        "Gdy prędkości są równe 0, dystans również musi być 0.");
  } else if ((_velocityHorizontal_mPs == !0 || _velocityVertical_mPs != 0) &&
             _distance_m <= 0) {

    throw makeErrorComunicate(param, "distance", "Dystans musi być dodatni.");
  }

  return true;
}

// TODO change to unique_ptr
/*!
 *
 */
Interp4Command *Interp4Fly::CreateCmd() { return new Interp4Fly(); }

// TODO conver to static string
// TODO update ReadParams
/*!
 *
 */
void Interp4Fly::PrintSyntax(std::ostream &ostr) const {
  ostr << "   Fly  hor_velocity[m/s]  ver_velocity[m/s]  dist[m]" << std::endl;
}
