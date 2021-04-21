# esp32-morphing-clock
ESP32 HUB75 Matrix Morphing Clock

I am working on building a clock based on a HUB75 RGB LED matrix, controlled by an ESP32.

![Photo](photos/photo1.jpg)

So far, it does the following:
* Displays the current date, time, and day of the week
* Updates the time on startup and periodically, via NTP
* Displays the current outdoor temperature and humidity (received via MQTT - if you want to use this, you will need an MQTT server and a separate temperature sensor publishing to it!)
* Displays the current light levels, read via a TSL2591 I2C light sensor

This is very much a work in progress, and it is far from being finished. Things that are planned for the future include:
* Using the current light levels to control the matrix brightness
* Displaying the weather forecast (min/max temperature, weather icons) pulled from Accuweather. The icons are already in place, I just need to pull and parse the JSON...
* Display alerts on-screen (received via MQTT)
* Add a buzzer module and use it to get the user's attention when an alert comes in

There is still some cleanup I need to do (and lots of READMEs/instructions to write), but over the following weeks I will be posting:
* The full source code
* The schematics for the PCB used
* The drawings for the lasercut plexiglass enclosure (already up, check it out [here](case/)! )

## Thanks

This project would not have been possible without the work of many others, who have been gracious enough to open source their work. Some of the things that I have used when building this:
* The ESP32 DMA library for controlling the matrix, from [mrfaptastic](https://github.com/mrfaptastic/ESP32-HUB75-MatrixPanel-I2S-DMA)
* The morphing clock code from [HariFun](https://www.instructables.com/Morphing-Digital-Clock/) (modified to work with mrfaptastic's library instead of pxmatrix)
* The shield schematics from [hallard](https://github.com/hallard/WeMos-Matrix-Shield-DMA), which gave me the confidence to try building my own version of a shield PCB :)

I also have to mention here [Brian Lough's work](https://www.tindie.com/products/brianlough/esp32-i2s-matrix-shield/) on a shield for the matrix. Even though he decided not to open source the board (he only sells the finished board on tindie), he has been extremely helpful during my initial work on the project. So if you are looking for a simple option for getting the full kit (shield and components, all in one package), take a look at [his tindie page](https://www.tindie.com/products/brianlough/esp32-matrix-shield-mini-32/) .


