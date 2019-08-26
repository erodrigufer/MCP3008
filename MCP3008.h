/*
  MCP3008.cpp is an Arduino library to communicate with the MCP3008 A/D converter. 
  Created by Uros Petrevski, Nodesign.net 2013. Released into the public domain. 
  Additional modifications and additions by erodrigufer 2019.
  
  Ported from Python code originally written by Adafruit for RPi:
  http://learn.adafruit.com/send-raspberry-pi-data-to-cosm/python-script
*/

#ifndef MCP3008_h
#define MCP3008_h

#include "Arduino.h"

class MCP3008
{
  public:
    MCP3008(int clockpin, int mosipin, int misopin, int cspin);
    int readADC_single(int adcnum);
    int readADC_differential(int adcnum);

  private:
      int _clockpin, _mosipin, _misopin, _cspin;
};


#endif
