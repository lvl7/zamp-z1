#include "DronePose.hh"

DronePose::DronePose() : _coordinateWektor3_m(0, 0, 0), _angle_deg(0) {
  _outFile.open("coords.txt");
}

DronePose::~DronePose(){
  _outFile.close();
}

void DronePose::SetPos_m(double x_m, double y_m, double z_m) {
  _coordinateWektor3_m.x() = x_m;
  _coordinateWektor3_m.y() = y_m;
  _coordinateWektor3_m.z() = z_m;
  AfterUpdate();
}

void DronePose::SetPos_m_deg(double x_m, double y_m, double z_m,
                             double ang_deg) {
  _coordinateWektor3_m.x() = x_m;
  _coordinateWektor3_m.y() = y_m;
  _coordinateWektor3_m.z() = z_m;
  _angle_deg = ang_deg;
  AfterUpdate();
}

void DronePose::SetPos_m(const Wektor3D &rWsp_m) {
  _coordinateWektor3_m = rWsp_m;
  AfterUpdate();
}

void DronePose::SetAngle_deg(double angle_deg) { _angle_deg = angle_deg; }

void DronePose::AddAngle_deg(double angleDelta_deg) {
  _angle_deg += angleDelta_deg;
  AfterUpdate();
}

const Wektor3D &DronePose::GetPos_m() const { return _coordinateWektor3_m; }

double DronePose::GetAngle_deg() { return _angle_deg; }

void DronePose::AddDeltaPos_m(double xDelta_m, double yDelta_m,
                              double zDelta_m) {

  _coordinateWektor3_m.x() += xDelta_m;
  _coordinateWektor3_m.y() += yDelta_m;
  _coordinateWektor3_m.z() += zDelta_m;

  AfterUpdate();
}

void DronePose::AddDeltaPos_m_deg(double xDelta_m, double yDelta_m,
                                  double zDelta_m, double angleDelta_deg) {

  _coordinateWektor3_m.x() += xDelta_m;
  _coordinateWektor3_m.y() += yDelta_m;
  _coordinateWektor3_m.z() += zDelta_m;
  _angle_deg += angleDelta_deg;
  AfterUpdate();
}

void DronePose::AfterUpdate() {

  _outFile << _coordinateWektor3_m.x() << "\t" << _coordinateWektor3_m.y()
           << "\t" << _coordinateWektor3_m.z() << "\t" << _angle_deg
           << std::endl;
}
