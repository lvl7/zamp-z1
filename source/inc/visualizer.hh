#ifndef VISUALIZER_HH
#define VISUALIZER_HH

#include <fstream>
#include <iostream>

#include "DronePose.hh"
#include "lacze_do_gnuplota.hh"

#include "Wektor3D.hh"

// TODO ---
/*!
 * \brief Nazwa pliku zawierającego współrzędne trajektorii drona
 *
 * Symbol definiuje nazwę pliku, do którego dopisywane są współrzędne
 * kolejnych punktów trajektrii. Na podstawie zawartości tego pliku
 * rysowana jest łamana reprezentująca trajektorię drona.
 */
#define FILE_NAME__TRAJECTORY "coords.txt"
/*!
 * \brief Nazwa pliku zawierającego współrzędne korpusu drona
 *
 * Symbol definiuje nazwę pliku, do którego wpisywane są współrzędne
 * wierzchołków korpusu drona po każdorazowej zmianie jego pozycji.
 * Plik ten jest wykorzystywany do odczytu przez program gnuplot.
 * Na podstawi danych w nim zawartych.
 */
#define FILE_NAME__DRON_BODY_VIEW "widok_drona.dat"

/*!
 * \brief Nazwa pliku z opisem były wzorcowej modelującej korpus drona
 *
 * Symbol definiuje nazwę pliku, w którym zapisane są współrzędne
 * wierzchołków bryły wzorcowej, która modeluje korpus drona.
 * Współrzędne są podane względem lokalnego układu współrzędnych,
 * w którym współrzędne środka to (0,0,0). Aby więc otrzymać obrys
 * bryły w aktualnej pozycji należy je rotować o kąt odpowiadający
 * aktualnej orientacji drona, a następnie dodać do współrzędnych
 * poszczególnych wierzchołków, współrzędne akutalne pozycji.
 */
#define FILE_NAME__DRON_BODY_TEMPLATE "korpus_drona.dat"
// TODO ===

/*!
 * \brief Klasa odpowiedzialna za wizualizację przelotu drona.
 *
 * Wykorzystuje lacze_do_gnuplota jako most pośredni między programem \p
 * gnuplot, w
 * którym wyrysowywana jest scena oraz dron z zaznaczeniem ścieżki.
 */
class Visualizer {
private:
  /*!
   * \brief Pośredniczy w uruchomieniu i przekazywaniu poleceń
   *        do programu \p gnuplot
   */
  PzG::LaczeDoGNUPlota _plotter;

public:
  Visualizer();
  /*!
   * \brief
   */
  virtual void Draw(const DronePose *dronePose);
};
#endif
