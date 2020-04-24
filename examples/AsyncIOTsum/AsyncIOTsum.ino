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
real time, such as duty cycle PWM, online processing and calculators, etc..
*****************************************************************************************************************************/
 
#include "AsyncIOT.h"

AsyncWebServer server(80);

int paramsNr = 1;
int valorint[10], i = 0, sum = 0, product = 1;
String valor;

char last_modified[50];
const int led = 2; //builtin led

const char * ssid = "-----------"; //Wifi network
const char * password = "-------------";

void setup(void) {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  pinMode(led, OUTPUT); //colocar para startar o led quando houver reset.
  digitalWrite(led, 1);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  AsyncIOT.sethost();

  server.on("/sanusb", HTTP_GET, [](AsyncWebServerRequest * request) { //acesso somente pelo IP/sanusb
    AsyncResponseStream * response = request -> beginResponseStream("text/html");
    //********************************Imprime página********************
    response -> printf("<meta charset='UTF-8'> <link rel='icon' type='image/x-icon' href='http://sanusb.blogspot.com.br/favicon.ico'/><h2>SanUSB IO parameters processing</h2><form action='/calc'>");
    for (i = 0; i < paramsNr; i++) {
      response -> printf("Input %d: <input type='text' name='parameter%d' value=''><br>", i, i);
    }
    response -> printf("<br><br><input type='submit' value='Submit'><br></form>");
    //*****Retorno dos Valores - Imprime variáveis globais ara a página HTML********************
    response -> printf("<br><p><b>Output:</b></p>");
    /***************************************************************************************************** 
    In this page, input values ​​valorint[i] can be processed. In the case of this example, the input parameters 
    are converted to integers, added, multiplied and the results are shown in the output parameters. As other 
    applications, online calculators can be developed, post data to a cloud server, modify operating parameters 
    of the ESP32 ans ESP8266 microcontrollers in real time, such as duty cycle PWM, and so on.
    ******************************************************************************************************/
    for (i = 0; i < paramsNr; i++) {
      response -> printf("Processed value[%d]: %d<br>", i, valorint[i]); //Imprime valores na página
      sum += valorint[i];
    }
    response -> printf("<br>Sum value: %d<br>", sum);
    sum = 0; //Imprime valor da soma           

    response -> printf("<br><a href='/'>Start Page</a>");
    response -> printf("<br><p><a href='/param'>Change number of inputs</a></p>");
    //response->printf("<p>If it doesn't work, go to Browser History first and clear browsing data</p>");
    request -> send(response);
  });

  /*************************************************************************************************************/
  server.on("/calc", HTTP_GET, [](AsyncWebServerRequest * request) {

    paramsNr = request -> params();
    for (i = 0; i < paramsNr; i++) {
      AsyncWebParameter * p = request -> getParam(i);
      valor = (p -> value());
      valorint[i] = valor.toInt(); //convert to integer
      Serial.printf("valorint[%d]=%d\n", i, valorint[i]);
      Serial.println("------");
    }

    if (paramsNr <= 1 && flag == 1) {
      paramsNr = valorint[0];
    }
    if (paramsNr > 1 && flag == 1) {
      for (i = 0; i < paramsNr; i++) {
        valorint[i] = 0; //limpa os dados anteriores                                                      
      }
      flag = 0; //limpa flag
    }
    Serial.printf("Number of parameters: %d\n", paramsNr);
    request -> redirect("/sanusb"); //para mostrar os valores  
  });

  AsyncIOT.begin(&server);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  AsyncIOT.boot();
  digitalWrite(led, !digitalRead(led));
  delay(500);
}
