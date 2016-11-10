#include <cassert>
#include <cstdio>
#include <iostream>
#include <memory>
#include <memory>

#include "DronePose.hh"
#include "Interface.hh"
#include "Interp4Command.hh"
#include "commandInterpreter.hh"
#include "io.hh"
#include "pluginHandler.hh"


//TODO
// #define LINE_SIZE 500
// bool ExecPreprocesor(const char * NazwaPliku, std::istringstream &IStrm4Cmds) {
//   std::string Cmd4Preproc = "cpp -P ";
//   char Line[LINE_SIZE];
//   std::ostringstream OTmpStrm;
//   Cmd4Preproc += NazwaPliku;
//   FILE* pProc = popen(Cmd4Preproc.c_str(),"r");
//   if (!pProc)
//     return false;
//   while (fgets(Line, LINE_SIZE, pProc)) {
//     OTmpStrm << Line;
//   }
//   IStrm4Cmds.str(OTmpStrm.str());
//   return pclose(pProc) == 0;
// }

int main(int argc, char **argv) {

  // std::istringstream stream;
  // std::istringstream *strP = &stream;
  // ExecPreprocesor("temp.txt", stream);
  //
  // std::istringstream &str2(*strP);
  //
  //
  // while(true){
  //   std::string word;
  //   str2 >> word;
  //   std::cout << word << std::endl;
  //
  //   std::string c;
  //   std::cin >> c;
  // }

  /**
   * Wskaźnik na klasę do prowadzenia komunikacji z użytkownikiem,
   */
  std::unique_ptr<Interface> _interface(new Interface());

  // /**
  //  * Wskaźnik na zarzadcę wtyczek.
  //  */
  // std::unique_ptr<PluginHandler> _pluginHandler;
  //
  // Interp4Command * cmd = _pluginHandler->getPluginByName("Fly");
  //
  //
  // std::istringstream *commnadsStream = _io->openCommandsFile("commands.txt");
  //
  // std::cout << "Set parameters" << std::endl;
  // try {
  //   cmd->ReadParams(*commnadsStream);
  // } catch (std::string err) {
  //   std::cerr << err << std::endl;
  //   cmd->PrintSyntax();
  // }
  // //
  // // std::cout << std::endl;
  // // std::cout << cmd->GetCmdName() << std::endl;
  // // std::cout << std::endl;
  // // cmd->PrintSyntax();
  // // std::cout << std::endl;
  // // cmd->PrintCmd();
  // // std::cout << std::endl;
  //
  // std::ofstream coordFile;
  // coordFile.open("coords.txt");
  // std::unique_ptr<DronePose> drone(new DronePose);
  //
  // coordFile.close();
  // cmd->ExecCmd(drone.get(), NULL);
  // delete cmd;

  _interface->printMainMenu();
  _interface->getCommandAndExecute();
}
