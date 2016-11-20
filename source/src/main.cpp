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

int main(int argc, char **argv) {
  std::unique_ptr<Interface> _interface(new Interface());

    _interface->printMainMenu();
    _interface->getCommandAndExecute();

}
