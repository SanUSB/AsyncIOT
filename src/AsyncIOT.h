/********************************************************sanusb.org********************************************************
AsyncIOT provides:

an UNIVERSAL HMI (human-machine interface) environment sketch for ESP32 and ESP8266 in order to interact with processed 
inputs and outputs using any browser through HTML pages. As an example, the input parameters values are converted to 
integers, added, multiplied and the results are shown in the output parameters. The number of input and output parameters 
is also set by the user.

This environment also makes it possible to update the firmware .bin via WiFi OTA (Over the Air). To generate a .bin file 
from your sketch, go to Sketch menu of the Arduino IDE > Export compiled Binary.

To install the ESP32 and ESP8266 boards in Arduino IDE, follow these next instructions: In your Arduino IDE, go to File> 
Preferences. Insert into the "Additional Board Manager URLs":

https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
Open the Boards Manager: Go to Tools > Board > Boards Manager: Search for ESP32 and press install button for the "ESP32 
by Espressif Systems". Also search for ESP8266 and press install button for the "ESP8266 by ESP8266 Community".

The dependencies of the universal AsyncIOT tool are the Assync libraries. For ESP8266 are ESPAsyncTCP and ESPAsyncWebServer 
at:

https://github.com/me-no-dev/ESPAsyncTCP
https://github.com/me-no-dev/ESPAsyncWebServer

For ESP32 are AsyncTCP and the same ESPAsyncWebServer at:

https://github.com/me-no-dev/AsyncTCP
https://github.com/me-no-dev/ESPAsyncWebServer

To install all the libraries, including https://github.com/SanUSB/AsyncIOT , follow the steps: Arduino IDE -> Sketch -> 
Include Library -> Add .zip Libraries.

You can usually find the installed ESP32 and ESP8266 libraries at:

On Windows: C:\Users\UserName\Documents\Arduino\libraries (tested) or 
            C:\Program Files(x86)\Arduino\libraries.
            
On Linux: /home/UserName/Arduino/Libraries (tested).

On OSX:  ~/Documents/Arduino/libraries.

In the installed AsyncIOT library folder there is an example for testing this proposed tool called AsyncIOT.ino.

Other possible applications: post data to an IoT cloud server, modify operating parameters of the ESP microcontroller in 
real time, such as duty cycle PWM, online processing and calculators, etc.. Tutorial: https://youtu.be/UKPWt2sKoHA.

*****************************************************************************************************************************/
 
#ifndef AsyncIOT_h
#define AsyncIOT_h

#if defined(ESP8266)
    #include <ESP8266WiFi.h>
    #include <ESPAsyncTCP.h>
#elif defined(ESP32)
    #include <WiFi.h>
    #include <AsyncTCP.h>
    #include <Update.h>
    #include <Preferences.h>
    Preferences serv;
#endif

#include <ESPAsyncWebServer.h>

#include "AsyncIOTpages.h"


int flag=0;
size_t content_len;
unsigned int s=0;
AsyncWebServer *_server; 

class AsyncIOTClass{
    public:

        void begin(AsyncWebServer *server){
            _server = server;

           _server->on("/", HTTP_GET, [](AsyncWebServerRequest *request){
                AsyncWebServerResponse * response = request->beginResponse_P(200, "text/html", start_html_gz, start_html_gz_len);
                response->addHeader("Content-Encoding", "gzip");           
                request->send(response);            
                });    
//*****************************************************************************
           _server->on("/param", HTTP_GET, [](AsyncWebServerRequest * request) {
                flag=1;
                AsyncWebServerResponse * response = request->beginResponse_P(200, "text/html", main_html_gz, main_html_gz_len);
                response->addHeader("Content-Encoding", "gzip");
                request->send(response);            
                });
//*****************************************************************************  
           _server->on("/update", HTTP_GET, [](AsyncWebServerRequest *request){
                AsyncWebServerResponse * response = request->beginResponse_P(200, "text/html", grava_html_gz, grava_html_gz_len);
                response->addHeader("Content-Encoding", "gzip"); 
                request->send(response); 
                });
//*****************************************************************************
            _server->on("/update", HTTP_POST, [&](AsyncWebServerRequest *request) {
                AsyncWebServerResponse *response = request->beginResponse((Update.hasError())?500:200, "text/plain", (Update.hasError())?"FAIL":"OK SanUSB");
                response->addHeader("Connection", "close");
                response->addHeader("Access-Control-Allow-Origin", "*");
                request->send(response);
                restartRequired = true;
            }, [](AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final) {
                
                if (!index) { // if index == 0 then this is the first frame of data                
                    content_len = request->contentLength();                    
                    #if defined(ESP8266)
                        int cmd = (filename.indexOf("spiffs") > -1) ? U_FS : U_FLASH;
                        Update.runAsync(true);
                        if (!Update.begin(content_len, cmd)){ // Start with max available size
                        #elif defined(ESP32)
                        while(!serv.getUInt("c", 0)){}
                        int cmd = (filename.indexOf("spiffs") > -1) ? U_SPIFFS : U_FLASH;
                        if (!Update.begin(UPDATE_SIZE_UNKNOWN, cmd)) { // Start with max available size
                    #endif
                            Update.printError(Serial);   
                        }
                
                }

                // Write chunked data to the free sketch space
                if (Update.write(data, len) != len) {
                    Update.printError(Serial); 
                }
                    
              if(final){
                  if(Update.end(true)){
                      Serial.printf("Update Success: %u B\nRebooting...\n", index+len);
                      request->redirect("/"); //to local url 
                    } else {
                     Update.printError(Serial);
                    }
                    Serial.setDebugOutput(false);
                }
            });
        }
//*****************************************************************************      
        
            void sethost() {
                  #if defined(ESP8266)
                  WiFi.hostname("sanusb.org");
                  Serial.println(WiFi.hostname());
                  #elif defined(ESP32) 
                  serv.begin("serv", false);
                  s=start_html_gz[0];                 
                  serv.putUInt("c", s);     
                  WiFi.setHostname("sanusb.org");
                  #endif
            }

            void boot(void) {      
 if(restartRequired){
                   restartRequired = false; 
                   ESP.restart();                           
                    }
            }

    private:
              bool restartRequired = false; 
};

AsyncIOTClass AsyncIOT;
#endif
