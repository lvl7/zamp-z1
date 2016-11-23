#include "visualizer.hh"

Visualizer::Visualizer() {

  _plotter.Inicjalizuj();

  _plotter.DodajNazwePliku(FILE_NAME__TRAJECTORY);
  _plotter.DodajNazwePliku(FILE_NAME__DRON_BODY_VIEW);

  _plotter.ZmienTrybRys(PzG::TR_3D);
  _plotter.UstawZakresX(-100, 250);
  _plotter.UstawZakresY(-100, 250);
  _plotter.UstawZakresZ(-100, 200);
  _plotter.UstawRotacjeXZ(40, 60);
}



/*!
 * Dodaje do pliku, którego nazwa jest zdefinowana
 * przez stałą
 * \link Visualization.hh::FILE_NAME__DRON_BODY_VIEW
 *                                     FILE_NAME__DRON_BODY_VIEW\endlik,
 * współrzędne następnego punktu ścieżki ruchu drona.
 */
bool AddTrajectoryPoint( const DronePose *dronePose )
{
  std::ofstream  OuStrm(FILE_NAME__TRAJECTORY, std::ios::app);
  if (!OuStrm.is_open()) {
    std::cerr << " Blad otwarcia do zapisu pliku \"" FILE_NAME__TRAJECTORY "\""
	 << std::endl;
    return false;
  }
  OuStrm << dronePose->GetPos_m() << std::endl;
  return true;
}


/*!
 * Zapisanie pliku z zaktualnymi współrzędnymi wierzchołków bryły
 * opisującej drona.
 * Ze względu na specyfikę sposobu rysowania powierzchni przez program gnuplot,
 * format wejściowy i wyjściowy pliku musi zostać zachowany, tzn. muszą być
 * zachwane przerwy w postaci wolnych linii między kolejnymi zbiorami wierzchołków,
 * które stanowią tworzącą rysowanej siatki danej powierzchni.
 * Ta funkcja to zapewnia.
 * \param[in] dronePose - wskaźnik na obiekt zawierający dane dotyczące aktualnej pozy
 *                    drona.
 *
 * \warning W tej funkcji brakuje uwzględnienia rotacji, która pozwoli odzwierciedlić
 *          aktualną orientację drona. W kodzie funkcji jest zaznaczone miejsce,
 *          w którym należy wpisać odpowiedni kod.
 *
 */
bool WriteCurrDonPose( const DronePose *dronePose )
{
  std::ofstream  OuStrm(FILE_NAME__DRON_BODY_VIEW);
  std::ifstream  InStrm(FILE_NAME__DRON_BODY_TEMPLATE);
  Wektor3D Pos;

  if (!OuStrm.is_open()) {
  std::cerr << " Blad otwarcia do zapisu pliku \"" FILE_NAME__DRON_BODY_VIEW "\""
	 << std::endl;
    return false;
  }
  if (!InStrm.is_open()) {
  std::cerr << " Blad otwarcia do odczytu pliku \"" FILE_NAME__DRON_BODY_TEMPLATE "\""
	 << std::endl;
    return false;
  }

  char      Separator;

  while (!InStrm.eof()) {
    if (InStrm >> Pos) {
      //
      // Przed translacją trzeba dokonać właściwej rotacji, aby uwzględnić aktualną
      // orientację drona. Dla ułatwienia przyjmujemy, że uwzględniamy tylko orientację
      // w płaszczyźnie 0XY.
      //
      // Tutaj więc należy dopisać kod rotacji
      //
      Pos += dronePose->GetPos_m();
      OuStrm << Pos << std::endl;
      continue;
    }
    InStrm.clear();
    if (!(InStrm >> Separator)) break;
    if (Separator != '#') {
    std::cerr << " Blad w pliku \"" FILE_NAME__DRON_BODY_TEMPLATE "\"" << std::endl
           << " oczekiwano znaku #. Zamiast tego odebrano znak " << Separator
	   << std::endl;
      return false;
    }
    OuStrm << "#\n\n";
  }
  return true;
}



/*!
 * Powoduje dopisanie aktualnej współrzędnej drona do pliku,
 * w którym zawarta jest sekwencja wcześniejszych położeń.
 * W ten sposób otrzymana łamana reprentuje trajektorię ścieżkę
 * lotu drona.
 * Ponadto na podstawie pliku wzorcowego opisującego korpus drona,
 * utworzony zostaje plik ze współrzędnymi wierzchołków w jego
 * nowej pozycji. Po tej pozycji następuje odrysowanie drona
 * w jego aktulanej pozycji.
 *
 * \param[in] dronePose - wskaźnik na obiekt zawierający dane dotyczące aktualnej pozy
 *                    drona.
 */
void Visualizer::Draw( const DronePose *dronePose )
{
  AddTrajectoryPoint(dronePose);
  WriteCurrDonPose(dronePose);
  _plotter.Rysuj();
}
