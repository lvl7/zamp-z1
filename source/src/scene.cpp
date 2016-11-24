#include "scene.hh"

Wektor3D Scene::RotateXY(double sn, double cn, const Wektor3D &rPnt,
                         const Wektor3D &rScale) {
  return Wektor3D(rScale.x() * (rPnt.x() * cn - rPnt.y() * sn),
                  rScale.y() * (rPnt.x() * sn + rPnt.y() * cn),
                  rScale.z() * rPnt.z());
}

bool Scene::TransformGeom(const char *sFile_Template, const char *sFile_Target,
                          const Wektor3D &rTrans_m, double RotAngle_rad,
                          const Wektor3D &rScale) {
  std::ofstream OuStrm(sFile_Target);
  std::ifstream InStrm(sFile_Template);
  Wektor3D Pos;

  if (!OuStrm.is_open()) {
    std::cerr << " Blad otwarcia do zapisu pliku \"" << sFile_Target << "\""
              << std::endl;
    return false;
  }
  if (!InStrm.is_open()) {
    std::cerr << " Blad otwarcia do odczytu pliku \"" << sFile_Template << "\""
              << std::endl;
    return false;
  }

  char Separator;
  double sn = sin(RotAngle_rad), cn = cos(RotAngle_rad);

  while (!InStrm.eof()) {
    if (InStrm >> Pos) {
      // Najpierw dokonujemy rotacji
      Pos = RotateXY(sn, cn, Pos, rScale);
      // Następnie translacja
      Pos += rTrans_m;
      OuStrm << Pos << std::endl;
      continue;
    }
    InStrm.clear();
    if (!(InStrm >> Separator))
      break;
    if (Separator != '#') {
      std::cerr << " Blad w pliku \"" << sFile_Target << "\"" << std::endl
                << " oczekiwano znaku #. Zamiast tego odebrano znak "
                << Separator << std::endl;
      return false;
    }
    OuStrm << "#\n\n";
  }
  return true;
}

void Scene::AddNewCuboid(std::string name) { _cuboids[name] = Cuboid(); }

Cuboid *Scene::getLastCuboid() { return &(_cuboids.rbegin()->second); }

std::map<std::string, Cuboid> *Scene::getCuboids() { return &_cuboids; }
