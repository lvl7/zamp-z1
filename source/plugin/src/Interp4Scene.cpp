#include "Interp4Scene.hh"

extern "C" {
Interp4Command *CreateCmd(void);
}

using namespace xercesc;

Interp4Command *CreateCmd(void) { return Interp4Scene::CreateCmd(); }

Interp4Scene::Interp4Scene() : _scenePath_xml("") {

  // std::unique_ptr<XMLParser4Scene> xmlParser(new XMLParser4Scene(NULL));
  // _xmlParser = std::move(xmlParser);

}

void Interp4Scene::PrintCmd() const {
  std::cout << GetCmdName() << " " << _scenePath_xml;
}

const char *Interp4Scene::GetCmdName() const { return "Scene"; }

bool Interp4Scene::ExecCmd(DronePose *pRobPose, Visualizer *pVis) const {

  // _xmlParser->setScene(pVis->getScene());

  try {
    XMLPlatformUtils::Initialize();
  } catch (const XMLException &toCatch) {
    char *message = XMLString::transcode(toCatch.getMessage());
    std::cerr << "Error during initialization! :\n";
    std::cerr << "Exception message is: \n" << message << "\n";
    XMLString::release(&message);
    return 1;
  }

  SAX2XMLReader* pParser = XMLReaderFactory::createXMLReader();

   pParser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
   pParser->setFeature(XMLUni::fgSAX2CoreValidation, true);
   pParser->setFeature(XMLUni::fgXercesDynamic, false);
   pParser->setFeature(XMLUni::fgXercesSchema, true);
   pParser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);

   pParser->setFeature(XMLUni::fgXercesValidationErrorAsFatal, true);

   DefaultHandler* pHandler = new XMLParser4Scene(pVis->getScene());
   pParser->setContentHandler(pHandler);
   pParser->setErrorHandler(pHandler);

   try {

     if (!pParser->loadGrammar("grammar/scene.xsd",
                              xercesc::Grammar::SchemaGrammarType,true)) {
       std::cerr << "!!! Plik grammar/scene.xsd, '" << std::endl
            << "!!! ktory zawiera opis gramatyki, nie moze zostac wczytany."
            << std::endl;
       return false;
     }
     pParser->setFeature(XMLUni::fgXercesUseCachedGrammarInParse,true);
     pParser->parse(_scenePath_xml.c_str());
   }
   catch (const XMLException& Exception) {
            char* sMessage = XMLString::transcode(Exception.getMessage());
            std::cerr << "Informacja o wyjatku: \n"
                 << "   " << sMessage << "\n";
            XMLString::release(&sMessage);
            return false;
   }
   catch (const SAXParseException& Exception) {
            char* sMessage = XMLString::transcode(Exception.getMessage());
            char* sSystemId = xercesc::XMLString::transcode(Exception.getSystemId());

            std::cerr << "Blad! " << std::endl
                 << "    Plik:  " << sSystemId << std::endl
                 << "   Linia: " << Exception.getLineNumber() << std::endl
                 << " Kolumna: " << Exception.getColumnNumber() << std::endl
                 << " Informacja: " << sMessage
                 << std::endl;

            XMLString::release(&sMessage);
            XMLString::release(&sSystemId);
            return false;
   }
   catch (...) {
            std::cout << "Zgloszony zostal nieoczekiwany wyjatek!\n" ;
            return false;
   }

   delete pParser;
   delete pHandler;
   return true;
}

bool Interp4Scene::ReadParams(std::istringstream &istream) {
  std::string param;

  // TODO make the fieldNames static!
  istream >> param;

  if (param != "") {
    _scenePath_xml = param;
  } else {
    // TODO param name to static!
    throw makeErrorComunicate(
        param, "scenePath",
        "Ścieżka do pliku zawierającego scene nie może być pusta.");
  }
  return true;
}

Interp4Command *Interp4Scene::CreateCmd() { return new Interp4Scene(); }

void Interp4Scene::PrintSyntax(std::ostream &ostr) const {
  // TODO move scenePath to static!
  ostr << "   " << GetCmdName() << "  scenePath" << std::endl;
}
