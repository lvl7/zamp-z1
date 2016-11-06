#include "io.hh"

Io::Io(){

}

Io::~Io(){
  _commandsStream.close();
}

std::istream * Io::openCommandsFile(const char *fileName){

  //TODO add wrong file name exceptions
  //TODO add exception if the stream is already opended
  _commandsStream.open(fileName);

  return &_commandsStream;
}
