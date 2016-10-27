#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <memory>

#include "Interp4Command.hh"
#include "DronePose.hh"



int main(int argc, char ** argv)
{
  std::string pluginName = argv[1];

  void *pLibHnd_Move = dlopen(pluginName.c_str(),RTLD_LAZY);
  Interp4Command *(*pCreateCmd_Move)(void);
  void *pFun;


  std::ofstream coordFile;
  coordFile.open("coords.txt");

  std::unique_ptr<DronePose> drone(new DronePose);

  if (!pLibHnd_Move) {
    std::cerr << "!!! Brak biblioteki: "<< pluginName << std::endl;
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

  //
  // std::cout << std::endl;
  // std::cout << pCmd->GetCmdName() << std::endl;
  // std::cout << std::endl;
  pCmd->PrintSyntax();
  // std::cout << std::endl;
  pCmd->PrintCmd();
  // std::cout << std::endl;

  coordFile.close();
  pCmd->ExecCmd(drone.get(), NULL);

  delete pCmd;

  dlclose(pLibHnd_Move);
}
