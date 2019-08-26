MCP3008 is an Arduino library to communicate with the MCP3008 A/D converter.
Created by Uros Petrevski, Nodesign.net 2013. Released into the public domain.
Additional modifications and additions by erodrigufer 2019.

Ported from the [Python code originally by Adafruit for the RPi](http://learn.adafruit.com/send-raspberry-pi-data-to-cosm/python-script):


# Pin connections

MCP3008 Pin | Arduino Pin
------------|------------
VDD | 5V or 3.3V 
VREF |  any voltage value between 0,25V and VDD *
AGND | 
CLK | Digital Output
DOUT | Digital Input
DIN | Digital Output
CS | Digital Output
DGND | GND

\*Check datasheet pg. 3
 
# Installing the library

Copy all files to the _libraries_ folder in your Arduino main folder.

# TO DO

- [x] Implement differential input function
- [ ] Comment code from Uros / Clean code practices
