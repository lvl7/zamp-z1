#ifndef VISUALIZER_HH
#define VISUALIZER_HH

#include "DronePose.hh"
#include "lacze_do_gnuplota.hh"
/*!
 * \brief Klasa odpowiedzialna za wizualizację przelotu drona.
 *
 * Wykorzystuje lacze_do_gnuplota jako most pośredni między programem \p gnuplot, w
 * którym wyrysowywana jest scena oraz dron z zaznaczeniem ścieżki.
 */
class Visualizer {
private:
  /*!
   * \brief Pośredniczy w uruchomieniu i przekazywaniu poleceń
   *        do programu \p gnuplot
   */
  PzG::LaczeDoGNUPlota plotter;


public:
  /*!
   * \brief
   */
  virtual void Draw(DronePose *dronePose);
};
#endif
