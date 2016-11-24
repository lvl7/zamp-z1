#ifndef CUBOID_HH
#define CUBOID_HH


#include "Wektor3D.hh"

/**
 * \brief Klasa modelująca prostopadłościan.
 *
 * Wykorzystywana jako przeszkoda na scenie.
 * Prostopadłościan definiowany jako wektor środka oraz długości boków
 */
class Cuboid{
private:
      /**
     * \brief współrzędne środka bryły
     */
    Wektor3D _center;

    /**
     * \brief Długości boków
     */
    Wektor3D _size;

  public:

    /**
     * \brief Zwraca wektor środka bryły
     * \retval Wektor środka bryły
     */
    Wektor3D * getCenter();

    /**
     * \brief Zwraca wektor zawierający długości boków prostopadłościanu
     * \retval Wektor zawierający długości boków prostopadłościanu
     */
    Wektor3D * getSize();

};


#endif //CUBOID_HH
