# AsyncIOT [![N|Solid](http://sanusb.blogspot.com.br/favicon.ico)](http://sanusb.org/)

AsyncIOT provides:

  - an HMI (human-machine interface) environment sketch for ESP32 and ESP8266 (same script) in order to interact with processed inputs and outputs using any browser through HTML pages. As an example, the input parameters values are converted to integers, added, multiplied and the results are shown in the output parameters. The number of input and output parameters is also set by the user. 

  - This environment also makes it possible to update the firmware *.bin* via WiFi OTA (*Over the Air*). To generate a .bin file from your sketch, go to Sketch menu of the Arduino IDE > Export compiled Binary.

 To install the ESP32 and ESP8266 boards in Arduino IDE, follow these next instructions:
 In your Arduino IDE, go to File> Preferences. Insert into the "Additional Board Manager URLs":
 * https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
 
 Open the Boards Manager: Go to Tools > Board > Boards Manager:
 Search for ESP32 and press install button for the "ESP32 by Espressif Systems". Also search for ESP8266 and press install button for the "ESP8266 by ESP8266 Community".
 
 The dependencies of the AsyncIOT tool are the Async libraries. For ESP8266 are ESPAsyncTCP and ESPAsyncWebServer at:
 
 * https://github.com/me-no-dev/ESPAsyncTCP
 * https://github.com/me-no-dev/ESPAsyncWebServer
 
 For ESP32 are AsyncTCP and the same ESPAsyncWebServer at:
 
 * https://github.com/me-no-dev/AsyncTCP
 * https://github.com/me-no-dev/ESPAsyncWebServer
 
 To install all the libraries, including https://github.com/SanUSB/AsyncIOT , follow the steps: 
Arduino IDE -> Sketch -> Include Library -> Add .zip Libraries.
 
 You can usually find the installed ESP32 and ESP8266 libraries at:
  
 On Windows:    
*        C:\Users\UserName\Documents\Arduino\libraries (tested).
     
 On Linux:   
*       /home/UserName/Arduino/Libraries (tested).

On OSX:
*       ~/Documents/Arduino/libraries.

 In the installed **AsyncIOT** library folder there is an example for testing this proposed tool called **AsyncIOTstart.ino**.
 
 Other possible applications: post data to an IoT cloud server, modify operating parameters of the ESP microcontroller in real time, such as duty cycle PWM, online processing and calculators, etc..
 Tutorial: https://youtu.be/UKPWt2sKoHA.
 
*Have fun!*
