#ifndef  INTERP4COMMAND_HH
#define  INTERP4COMMAND_HH

#include <iostream>
#include "DronePose.hh"
#include "Visualization.hh"

#define TIME_INTERVAL_MS 200
//TODO
/**
 * \file
 * \brief Definicja klasy Interp4Command
 *
 * Plik zawiera definicję klasy Interp4Command ...
 */

//TODO
/**
 * \brief Modeluje abstrakcyjne polecenie dla robota mobilnego
 *
 *  Klasa modeluje ...
 */
 class Interp4Command {
  public:
    /**
     * \biref Interwał czasu dzielący wyliczane współrzędne w mili sekundach
     */
     double _timeInterval_ms;

  /**
   * \biref Konstruktor.
   *
   * Ustawia
   */
     Interp4Command();
   //TODO
/**
    * \brief Destruktor wirtualny ze wzgledu na klasy pochodne
    *
    *
    */
   virtual ~Interp4Command() {}
   //TODO
/**
    * \brief
    */
   virtual void PrintCmd() const = 0;
   //TODO
/**
    * \brief
    */
   virtual void PrintSyntax() const = 0;
   //TODO
/**
    * \brief
    */
   virtual const char* GetCmdName() const = 0;
   //TODO
/**
    * \brief
    */
   virtual bool ExecCmd(  DronePose  *pRobPose,  Visualization *pVis  ) const = 0;
   //TODO
/**
    * \brief
    */
   virtual bool ReadParams(std::istream& Strm_CmdsList) = 0;
 };

#endif
