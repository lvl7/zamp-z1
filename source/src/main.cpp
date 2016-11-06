#include <cassert>
#include <dlfcn.h>
#include <iostream>
#include <memory>

#include "DronePose.hh"
#include "Interface.hh"
#include "Interp4Command.hh"
#include "io.hh"

int main(int argc, char **argv) {

  std::unique_ptr<Io> io(new Io());
  std::unique_ptr<Interface> interface(new Interface(std::cin, std::cout));

  std::string pluginName = argv[1];

  void *pLibHnd_Move = dlopen(pluginName.c_str(), RTLD_LAZY);
  Interp4Command *(*pCreateCmd_Move)(void);
  void *pFun;

  std::ofstream coordFile;
  coordFile.open("coords.txt");

  std::unique_ptr<DronePose> drone(new DronePose);

  if (!pLibHnd_Move) {
    std::cerr << "!!! Brak biblioteki: " << pluginName << std::endl;
    return 1;
  }

  pFun = dlsym(pLibHnd_Move, "CreateCmd");
  if (!pFun) {
    std::cerr << "!!! Nie znaleziono funkcji CreateCmd" << std::endl;
    return 1;
  }
  pCreateCmd_Move = *reinterpret_cast<Interp4Command *(**)(void)>(&pFun);

  Interp4Command *pCmd = pCreateCmd_Move();

  std::istream *commnadsStream = io->openCommandsFile("commands.txt");

  std::cout << "Set parameters" << std::endl;
  try {
    pCmd->ReadParams(*commnadsStream);
  } catch (std::string err) {
    std::cerr << err << std::endl;
    pCmd->PrintSyntax();
  }
  //
  // std::cout << std::endl;
  // std::cout << pCmd->GetCmdName() << std::endl;
  // std::cout << std::endl;
  // pCmd->PrintSyntax();
  // std::cout << std::endl;
  // pCmd->PrintCmd();
  // std::cout << std::endl;

  coordFile.close();
  pCmd->ExecCmd(drone.get(), NULL);
  delete pCmd;

  dlclose(pLibHnd_Move);

  interface->printMainMenu();
  interface->getCommandAndExecute();
}
