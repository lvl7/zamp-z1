#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "Interp4Command.hh"

using std::cout;
using std::cerr;
using std::endl;

int main()
{

  std::cout << "hello wrold! <<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;

  // void *pLibHnd_Move = dlopen("Interp4Fly.so",RTLD_LAZY);
  // Interp4Command *(*pCreateCmd_Move)(void);
  // void *pFun;
  //
  // if (!pLibHnd_Move) {
  //   cerr << "!!! Brak biblioteki: Interp4Fly.so" << endl;
  //   return 1;
  // }
  //
  //
  // pFun = dlsym(pLibHnd_Move,"CreateCmd");
  // if (!pFun) {
  //   cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
  //   return 1;
  // }
  // pCreateCmd_Move = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);
  //
  //
  // Interp4Command *pCmd = pCreateCmd_Move();
  //
  // cout << endl;
  // cout << pCmd->GetCmdName() << endl;
  // cout << endl;
  // pCmd->PrintSyntax();
  // cout << endl;
  // pCmd->PrintCmd();
  // cout << endl;
  //
  // delete pCmd;
  //
  // dlclose(pLibHnd_Move);
}
