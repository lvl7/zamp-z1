#include "DronePose.hh"

DronePose::DronePose() : _coordinateWektor3_m(0, 0, 0), _angle_deg(0) {}

void DronePose::SetPos_m(double x_m, double y_m, double z_m) {
  _coordinateWektor3_m.x() = x_m;
  _coordinateWektor3_m.y() = y_m;
  _coordinateWektor3_m.z() = z_m;
  AfterUpdate();
}

void DronePose::SetPos_m(const Wektor3D &rWsp_m) {
  _coordinateWektor3_m = rWsp_m;
  AfterUpdate();
}

void DronePose::SetAngle_deg(double angle_deg) { _angle_deg = angle_deg; }

const Wektor3D &DronePose::GetPos_m() const { return _coordinateWektor3_m; }

double DronePose::GetAngle_deg() { return _angle_deg; }

void DronePose::AddDeltaPos_m(double xDelta_m, double yDelta_m,
                              double zDelta_m) {

  _coordinateWektor3_m.x() += xDelta_m;
  _coordinateWektor3_m.y() += yDelta_m;
  _coordinateWektor3_m.z() += zDelta_m;

  AfterUpdate();
}

void DronePose::AfterUpdate() {
  std::cout << _coordinateWektor3_m.x() << "\t" << _coordinateWektor3_m.y()
            << "\t" << _coordinateWektor3_m.z() << std::endl;
}