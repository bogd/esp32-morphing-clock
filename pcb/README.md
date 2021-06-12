# ESP32 Morphing Clock Shield PCB

## Info

Features:
* 16-wire ribbon cable connection to the RGB matrix
* Mounting holes for securing the shield to the enclosure
* Options for both PTH and SMD (0805/SOD-323) parts for all parts
* Multiple JST-XH (2.54mm) connectors for I2C sensors and for GPIOs (use for push-buttons, for example)
* Exposed JTAG and PROG connectors, for use with debugging/programming via ESP32-Prog (although they are a bit too close together in v0.3 :) )

**WARNING!!** Do not use v0.1 of the boards! I have made several mistakes while designing them (reversed OE/LAT pins on the matrix connector, and put in a WAY too thin power supply trace). As a result, I was unable to get the ESP32 to even boot when connected to these boards.

v0.3 has been tested, and works reliably.

## Board 

Images of the completed board:
![Front](photos/front.jpg)
![Back](photos/back.jpg)

The board with (a minimum of) components soldered on:
![Assembled Front](photos/assembled-front.jpg)
![Assembled Back](photos/assembled-back.jpg)

Connected to the matrix and the ESP32 module:
![Connected Front](photos/connected-front.jpg)
![Connected Back](photos/connected-back.jpg)



## Schematic

![Schematic](photos/schematic.png)

