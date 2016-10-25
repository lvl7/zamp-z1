#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <memory>

#include "Interp4Command.hh"
#include "DronePose.hh"

int main()
{
  void *pLibHnd_Move = dlopen("libInterp4Fly.so",RTLD_LAZY);
  Interp4Command *(*pCreateCmd_Move)(void);
  void *pFun;

  std::unique_ptr<DronePose> drone(new DronePose);

  if (!pLibHnd_Move) {
    std::cerr << "!!! Brak biblioteki: libInterp4Fly.so" << std::endl;
    return 1;
  }

  pFun = dlsym(pLibHnd_Move,"CreateCmd");
  if (!pFun) {
    std::cerr << "!!! Nie znaleziono funkcji CreateCmd" << std::endl;
    return 1;
  }
  pCreateCmd_Move = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);

  Interp4Command *pCmd = pCreateCmd_Move();


  std::cout << "Set parameters" << std::endl;
  try{
    pCmd->ReadParams(std::cin);
  } catch (std::string err ){
    std::cerr << err << std::endl;
    pCmd->PrintSyntax();
  }

  std::cout << "---------------" << std::endl;
  //
  // std::cout << std::endl;
  // std::cout << pCmd->GetCmdName() << std::endl;
  // std::cout << std::endl;
  pCmd->PrintSyntax();
  // std::cout << std::endl;
  pCmd->PrintCmd();
  // std::cout << std::endl;

  pCmd->ExecCmd(drone.get(), NULL);

  delete pCmd;

  dlclose(pLibHnd_Move);
}
