#ifndef DRONE_POSE_HH
#define DRONE_POSE_HH

#include "Wektor3D.hh"

#include <fstream>
#include <iostream>

// TODO
/**
 * \file
 * \brief Definicja klasy DronePose
 *
 * Plik zawiera definicję klasy DronePose
 */

// TODO
/**
 * \brief Modeluje zestaw informacji określający pozę robota
 *
 *  Klasa modeluje zestaw informacji określających pozę robota.
 *  Ponadto udostępnia metody, które pozwalają aktualizowanie
 *  współrzędnych pozy robota, jak też pobieranie tych informacji.
 */
class DronePose {
private:
  // TODO
  /**
     * \brief  Współrzędne drona w globalnym układzie współrzędnych
     *
     * Współrzędne pozycji drona w globalnym układzie współrzędnych.
     * Wartość współrzędnej wyrażona jest w metrach.
     */
  Wektor3D _coordinateWektor3_m;

  // TODO
  /**
     * \brief Kąt orientacji robota w globalnym układzie współrzednych
     *
     *  Kąt orientacji robota w globalnym układzie współrzednych.
     *  Wartość kąta wyrażona jest w stopniach.
     */
  double _angle_deg;

  /**
   * \biref Plik, do którego mają być wpisywane nowe współrzędne.
   *
   * Plik, do którego mają być wpisywane nowe współrzędne.
   */
  std::ofstream _outFile;

public:
  // TODO
  /**
     * \brief Zeruje pozę robota
     *
     *  Inicjalizuje wartościami 0 zarówno pozycję robota,
     *  jak też jego kąt orientacji.
     */
  DronePose();

  /**
   * \biref Zwalnia wszystkie pola.
   *
   * Zamyka plik wyjściowy _openFile.
   */
  ~DronePose();

  /**
     * \brief Ustawia wartości współrzędnych pozy robota
     *
     *  Ustawia wartości współrzędnych kartezjańskich pozycji.
     *  Wywołuje funkcje DronePose::AfterUpdate()
     *
     *  \param[in] x_m - usawiana wartość współrzędnej \e x-owej
     *                    wyrażonej w metrach,
     *  \param[in] y_m - usawiana wartość współrzędnej \e y-owej
     *                    wyrażonej w metrach,
     *  \param[in] z_m - usawiana wartość współrzędnej \e z-owej
     *                    wyrażonej w metrach,
     */
  void SetPos_m(double x_m, double y_m, double z_m);

  /**
     * \brief Ustawia wartości współrzędnych pozy robota
     *
     *  Ustawia wartości współrzędnych kartezjańskich pozycji.
     *  Wywołuje funkcje DronePose::AfterUpdate()
     *
     *  \param[in] x_m - usawiana wartość współrzędnej \e x-owej
     *                    wyrażonej w metrach,
     *  \param[in] y_m - usawiana wartość współrzędnej \e y-owej
     *                    wyrażonej w metrach,
     *  \param[in] z_m - usawiana wartość współrzędnej \e z-owej
     *                    wyrażonej w metrach,
     *  \param[in] ang_deg - ustawiana wartość kąta orientacji
     *                   robota wyrażona w stopniach.
     */
  void SetPos_m_deg(double x_m, double y_m, double z_m, double ang_deg);

  /**
   * \brief Dodaje do aktualnych współrzędnych pozy robota podane wartości w
   * metrach.
   *
   *  Do aktualnych współrzędnych pozy robota dodaje podane w argumentach
   * wartości wyrażnone w metrach
   *  Wywołuje funkcje DronePose::AfterUpdate()
   *
   * @param[in] xDelta_m różnica wartości współrzędnej x-owej w metrach
   * @param[in] yDelta_m różnica wartości współrzędnej y-owej w metrach
   * @param[in] zDelta_m różnica wartości współrzędnej z-owej w metrach
   */
  void AddDeltaPos_m(double xDelta_m, double yDelta_m, double zDelta_m);

  /**
   * \brief Dodaje do aktualnych współrzędnych pozy robota podane wartości w
   * metrach oraz pozycji kątowej w stopniach.
   *
   *  Do aktualnych współrzędnych pozy robota dodaje podane w argumentach
   * wartości wyrażnone w metrach, do kątu obrotu w stopniach.
   *
   *  Wywołuje funkcje DronePose::AfterUpdate()
   *
   * @param[in] xDelta_m różnica wartości współrzędnej x-owej w metrach
   * @param[in] yDelta_m różnica wartości współrzędnej y-owej w metrach
   * @param[in] zDelta_m różnica wartości współrzędnej z-owej w metrach
   * @param[in] angleDelta_deg różnica kątu obrotu drona w stopniach
   */
  void AddDeltaPos_m_deg(double xDelta_m, double yDelta_m, double zDelta_m,
                         double angleDelta_deg);

  // TODO
  /**
     * \brief Ustawia wartości współrzędnych pozycji robota
     *
     *  Ustawia wartości współrzędnych kartezjańskich pozycji
     *  robota.
     *  \param[in] rWsp_m - usawiana wartość współrzędnej \e x-owej
     *                    wyrażonej w metrach,
     */
  void SetPos_m(const Wektor3D &rWsp_m);

  // TODO
  /**
     * \brief Ustawia wartości kąta orientacji robota
     *
     *  Ustawia wartości kąta orientacji robota.
     *  Po wykonaniu tej operacji wywołana zostaje metoda
     *  \link DronePose::AfterUpdate AfterUpdate()\endlink.
     *  \param[in] angle_deg - ustawiana wartość kąta orientacji
     *                   robota wyrażona w stopniach.
     */
  void SetAngle_deg(double angle_deg);

  // TODO
  /**
     * \brief Dodaje do aktualnej wartości kąta orientacji robota angleDelta_deg
     *
     *  Dodaje do aktualnej wartości kąta orientacji robota angleDelta_deg
     *  Po wykonaniu tej operacji wywołana zostaje metoda
     *  \link DronePose::AfterUpdate AfterUpdate()\endlink.
     *  \param[in] angleDelta_deg - różnica wartość kątu orientacji
     *                   robota wyrażona w stopniach.
     */
  void AddAngle_deg(double angleDelta_deg);

  // TODO
  /**
    * \brief //TODO
    *
    *  Metoda uruchamiana po zakończeniu metody
    *  \link DronePos::SetAngle_deg( double angle_deg ) SetAngle_deg( double
    * angle_deg )\endlink.
    */
  void AfterUpdate();

  // TODO
  /**
     * \brief Udostępnia wartości współrzędnych pozy robota
     *
     *  Udostępnia wartości współrzędnych kartezjańskich pozycji
     *  oraz kąt orientacji robota.
     *  \return Bieżące współrzędne położenia drona.
     */
  const Wektor3D &GetPos_m() const;

  // TODO
  /**
     * \brief Udostępnia kąt orientacji drona.
     *
     * Udostępnia kąt orientacji drona. Kąt wyrażony jest w stopniach.
     */
  double GetAngle_deg();

//TODO
  // /**
  //  * \biref Ustawia plik do którego mają być zapisywane nowe współrzędne drona.
  //  *
  //  * Ustawia plik do którego mają być zapisywane nowe współrzędne drona.
  //  * @param outFile Plik do którego mają być zapisywane nowe współrzędne drona.
  //  */
  // void setOutputFileStream(std::ofstream &outFile);
};

#endif // DRONE_POSE
