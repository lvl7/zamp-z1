#include "Interp4Command.hh"

Interp4Command::Interp4Command() : _timeInterval_ms(TIME_INTERVAL_MS) {}

std::string
Interp4Command::makeErrorComunicate(std::string &errorParam,
                                    const char *filedName,
                                    const char *additionalInforamtion) {

  std::string errorComunicate = GetCmdName();
  errorComunicate += " | Niewłaściwa nastawa: [ ";
  errorComunicate += errorParam;
  errorComunicate += " ] dla ";
  errorComunicate += filedName;
  if (additionalInforamtion != NULL) {
    errorComunicate += " > ";
    errorComunicate += additionalInforamtion;
  }

  return errorComunicate;
}

void Interp4Command::setField(std::string &param, double &filed,
                              const char *fieldName,
                              const char *additionalInforamtion) {
  try {
    filed = std::stod(param, NULL);
  } catch (...) {
    throw makeErrorComunicate(param, fieldName, additionalInforamtion);
  }
}
