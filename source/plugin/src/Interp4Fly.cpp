#include <iostream>
#include "Interp4Fly.hh"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
}




/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Fly::CreateCmd();
}


/*!
 *
 */
Interp4Fly::Interp4Fly(): _Speed_mmS(0)
{}


/*!
 *
 */
void Interp4Fly::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() << " " << _Speed_mmS  << " 10  2" << endl;
}


/*!
 *
 */
const char* Interp4Fly::GetCmdName() const
{
  return "Fly";
}


/*!
 *
 */
bool Interp4Fly::ExecCmd( DronPose     *pRobPose,  Visualization *pVis) const
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
bool Interp4Fly::ReadParams(std::istream& Strm_CmdsList)
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
Interp4Command* Interp4Fly::CreateCmd()
{
  return new Interp4Fly();
}


/*!
 *
 */
void Interp4Fly::PrintSyntax() const
{
  cout << "   Fly  hor_speed[m/s]  ver_speed[m/s]  dist[m]" << endl;
}
