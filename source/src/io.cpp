#include "io.hh"

std::istringstream *Io::openCommandsFile(const char *fileName) {
  std::string commandForPreprocessor = "cpp -P ";
  commandForPreprocessor += fileName;

  char line[READ_LINE_SIZE];

  std::ostringstream lineStreamString;

  FILE *commandsFile = popen(commandForPreprocessor.c_str(), "r");
  if (!commandsFile) {
    std::string errorComunicate = "Plik o nazwie: [";
    errorComunicate += fileName;
    errorComunicate += " ] nieznaleziony.";

    throw errorComunicate;
  }

  while (fgets(line, READ_LINE_SIZE, commandsFile)) {
    lineStreamString << line;
  }

  _commandsStream.str(lineStreamString.str());

  pclose(commandsFile);

  return &_commandsStream;
}

std::istringstream *Io::getCommandsStream() { return &_commandsStream; }
