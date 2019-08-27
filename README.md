MCP3008 is an Arduino library to communicate with the MCP3008 A/D converter.
Created by Uros Petrevski, Nodesign.net 2013. Released into the public domain.
Additional modifications and additions by erodrigufer 2019.

Ported from the [Python code originally by Adafruit for the RPi](http://learn.adafruit.com/send-raspberry-pi-data-to-cosm/python-script):

Branch fastCommands was implemented by erodrigufer to increase the communication speed with the MCP3008. The standard Arduino commands were replaced by custom commands to reduce the execution time of, for example, reading a pin.

# Pin connections

MCP3008 Pin | Arduino Pin
------------|------------
VDD | 5V or 3.3V 
VREF |  any voltage value between 0,25V and VDD *
AGND | 
CLK | Digital Output
DOUT (MISO) | Digital Input
DIN (MOSI) | Digital Output
CS | Digital Output
DGND | GND

\*Check datasheet pg. 3
 
# Installing the library

Copy all files to the _libraries_ folder in your Arduino main folder.

# TO DO

- [x] Implement differential input function
- [ ] replace digitalWrite with a faster custom command
- [ ] replace digitalRead with a faster custom command
- [ ] Comment code from Uros / Clean code practices
- [ ] Write a guide on to how to properly use MCP3008 with Arduino
