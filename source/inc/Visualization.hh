#ifndef VISUALIZATION_HH
#define VISUALIZATION_HH


#include "DronePose.hh"

/*!
 * \brief
 */
class Visualization {

  public:
  /*!
   * \brief Destruktor wirtualny aby zapewnić poprawną destrukcję
   *        obiektu klasy pochodnej
   */
   virtual ~Visualization() {}
  /*!
   * \brief
   */
  virtual void Draw( DronePose *pPose ) {}
};
#endif
