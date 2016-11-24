#ifndef SCENE_HH
#define SCENE_HH

#include <cmath>
#include <fstream>
#include <map>

#include "Cuboid.hh"
#include "Wektor3D.hh"

/**
 * \biref Ścieżka do folderu zawierającego wszystkie pliki związane ze sceną
 *
 * Ścieżka do folderu, w którym przechowywane są pliki definiujące secnę jak np:
 * przeszkody, czy elementarny sześcian.
 */
#define SCENE_PATH "scene/"

/*!
 * \brief Ścieżka pliku z opisem były wzorcowej modelującej sześcian wzorcowy
 *
 * Symbol definiuje ścieżkę do pliku, w którym zapisane są współrzędne
 * wierzchołków bryły wzorcowej, która modeluje korpus drona.
 * Współrzędne są podane względem lokalnego układu współrzędnych,
 * w którym współrzędne środka to (0,0,0). Aby więc otrzymać obrys
 * bryły w aktualnej pozycji należy je rotować o kąt odpowiadający
 * aktualnej orientacji drona, a następnie dodać do współrzędnych
 * poszczególnych wierzchołków, współrzędne akutalne pozycji.
 */
#define FILE_NAME__CUBOID_TEMPLATE SCENE_PATH "elementarny_szescian.dat"

class Scene {
private:
  /**
   * \brief mapa prostopadłościanów z ich nazwą jako kluczem
   */
  std::map<std::string, Cuboid> _cuboids;

public:
  /*
   * Czyta plik, który zawiera współrzędne bryły wzorocej. Przeczytane
   * współrzędne
   * wierzchołków są transformowane, tzn. podane są:
   *   \li rotacji,
   *   \li skalowaniu,
   *   \li translacji.
   * Następnie zapisywane są do pliku, który będzie czytał gnuplot. Ważne jest,
   * że funkcja ta zachowuje budowę pliku wzorcowego, tzn. w odpowiednim miejscu
   * znajdzie się wolna linia między poszczególnymi zestawami współrzędnych
   * wierzchołków.
   *
   * \param[in] sFile_Template - nazwa pliku zawierającego współrzędne
   * wierzchołków bryły
   *                             wzorcowej. Z tego pliku wspomniane współrzędne
   * są czytane.
   * \param[in] sFile_Target - nazwa pliku, do którego zostaną zapisane
   * przetransformowane
   *                           współrzędne.
   * \param[in] rTrans_m     - wektor translacji, którego współrzędne wyrażone
   * są w metrach.
   * \param[in] RotAngle_rad - kąt rotacji wyrażony w radianach.
   *
   * \retval true - gdy operacja otwarcia i zapisu odpowiednich plików
   * zakończyła się
   *                powodzeniem,
   * \retval false - w przypadku przeciwnym.
   */
  bool TransformGeom(const char *sFile_Template, const char *sFile_Target,
                     const Wektor3D &rTrans_m, double RotAngle_rad,
                     const Wektor3D &rScale);

  /*!
  * \brief Rotacja i skalowanie współrzędnych punktu
  *
  * Dokonuje rotacji i skalowania współrzędnych zadanego punktu.
  * \param[in] sn - sinus kąta rotacji,
  * \param[in] cn - cosinus kąta rotacji,
  * \param[in] rPnt   - współrzędne punktu, które mają być podane rotacji i
  * skalowaniu,
  * \param[in] rScale - współczynniki skali wzdłuż każdej z osi.
  * \return Zwaraca przetransformowane współrzędne punktu.
  */
  Wektor3D RotateXY(double sn, double cn, const Wektor3D &rPnt,
                    const Wektor3D &rScale);

  /**
   * \brief dodaje nowy prospodałościan do mapy cuboids
   * \param name - klucz dla prostopadłościanu
   */
  void AddNewCuboid(std::string name);

  /**
   * \biref zwraca ostatnio dodany prosropadłościan
   */
  Cuboid *getLastCuboid();

  /**
   * \brief Zwraca przeszkody w postaci mapy przeszkód z ich nazwą jako kluczem.
   */
  std::map<std::string, Cuboid> * getCuboids();



};

#endif
