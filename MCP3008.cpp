/*
  MCP3008.cpp is an Arduino library to communicate with the MCP3008 A/D converter. 
  Created by Uros Petrevski, Nodesign.net 2013. Released into the public domain. 
  Additional modifications and additions by erodrigufer 2019.
  
  Ported from Python code originally written by Adafruit for RPi:
  http://learn.adafruit.com/send-raspberry-pi-data-to-cosm/python-script
*/

#include "Arduino.h"
#include "MCP3008.h"
#include "digitalWriteFast.h"

MCP3008::MCP3008(const int clockpin,const int mosipin,const int misopin,const int cspin) {
  // define with const to get fast port manipulation  
  
    // define SPI outputs and inputs for bitbanging
    
    _cspin = cspin;
    _clockpin = clockpin;
    _mosipin = mosipin;
    _misopin = misopin;
    
    pinModeFast(_cspin, OUTPUT);
    pinModeFast(_clockpin, OUTPUT);
    pinModeFast(_mosipin, OUTPUT);
    pinModeFast(_misopin, INPUT);
    
}

// read SPI data from MCP3008 chip, 8 possible adc's (0 thru 7)
int MCP3008::readADC_single(int adcnum) {

  if ((adcnum > 7) || (adcnum < 0)) return -1; // Wrong adc address return -1

  // algo
  digitalWriteFast(_cspin, HIGH);

  digitalWriteFast(_clockpin, LOW); //  # start clock low
  digitalWriteFast(_cspin, LOW); //     # bring CS low

  int commandout = adcnum; // # commandout equals addresses to be read
  commandout |= 0x18; //  # start bit + single-ended bit
  //commandout |=0x8; // # start bit + differential inputs (10000)
  commandout <<= 3; //    # we only need to send 5 bits here
 
  for (int i=0; i<5; i++) {
    if (commandout & 0x80) 
      digitalWriteFast(_mosipin, HIGH);
    else   
      digitalWriteFast(_mosipin, LOW);
      
    commandout <<= 1;
    digitalWriteFast(_clockpin, HIGH);
    digitalWriteFast(_clockpin, LOW);

  }

  int adcout = 0;
  // read in one empty bit, one null bit and 10 ADC bits
  for (int i=0; i<12; i++) {
    digitalWriteFast(_clockpin, HIGH);
    digitalWriteFast(_clockpin, LOW);
    adcout <<= 1;
    if (digitalRead(_misopin))
      adcout |= 0x1;
  } 
  digitalWriteFast(_cspin, HIGH);

  adcout >>= 1; //      # first bit is 'null' so drop it
  return adcout;
}

// read SPI data from MCP3008 chip, 8 possible adc's (0 thru 7)
int MCP3008::readADC_differential(int adcnum) {

  if ((adcnum > 7) || (adcnum < 0)) return -1; // Wrong adc address return -1

  // algo
  digitalWriteFast(_cspin, HIGH);

  digitalWriteFast(_clockpin, LOW); //  # start clock low
  digitalWriteFast(_cspin, LOW); //     # bring CS low

  int commandout = adcnum; // # commandout equals addresses to be read
  //commandout |= 0x18; //  # start bit + single-ended bit
  commandout |=0x8; // # start bit + differential inputs (10000)
  commandout <<= 3; //    # we only need to send 5 bits here
 
  for (int i=0; i<5; i++) {
    if (commandout & 0x80) 
      digitalWriteFast(_mosipin, HIGH);
    else   
      digitalWriteFast(_mosipin, LOW);
      
    commandout <<= 1;
    digitalWriteFast(_clockpin, HIGH);
    digitalWriteFast(_clockpin, LOW);

  }

  int adcout = 0;
  // read in one empty bit, one null bit and 10 ADC bits
  for (int i=0; i<12; i++) {
    digitalWriteFast(_clockpin, HIGH);
    digitalWriteFast(_clockpin, LOW);
    adcout <<= 1;
    if (digitalRead(_misopin))
      adcout |= 0x1;
  } 
  digitalWriteFast(_cspin, HIGH);

  adcout >>= 1; //      # first bit is 'null' so drop it
  return adcout;
}

