#include <cassert>
#include <iostream>
#include <memory>

#include "DronePose.hh"
#include "Interface.hh"
#include "Interp4Command.hh"
#include "io.hh"
#include "pluginHandler.hh"

int main(int argc, char **argv) {

  std::unique_ptr<Io> io(new Io());
  std::unique_ptr<Interface> interface(new Interface(std::cin, std::cout));
  std::unique_ptr<PluginHandler> plugins(new PluginHandler());

  Interp4Command * cmd = plugins->getPluginByName("Fly");


  std::istream *commnadsStream = io->openCommandsFile("commands.txt");

  std::cout << "Set parameters" << std::endl;
  try {
    cmd->ReadParams(*commnadsStream);
  } catch (std::string err) {
    std::cerr << err << std::endl;
    cmd->PrintSyntax();
  }
  //
  // std::cout << std::endl;
  // std::cout << cmd->GetCmdName() << std::endl;
  // std::cout << std::endl;
  // cmd->PrintSyntax();
  // std::cout << std::endl;
  // cmd->PrintCmd();
  // std::cout << std::endl;

  std::ofstream coordFile;
  coordFile.open("coords.txt");
  std::unique_ptr<DronePose> drone(new DronePose);

  coordFile.close();
  cmd->ExecCmd(drone.get(), NULL);
  delete cmd;


  interface->printMainMenu();
  interface->getCommandAndExecute();

  std::cout << "-------------------" << std::endl;
}
