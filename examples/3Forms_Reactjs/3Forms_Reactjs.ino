/*
Mais detalhes em: https://sanusb.blogspot.com/2021/08/servindo-um-exemplo-de-app-reactjs-com.html
 */

#if defined(ESP8266)
    #include <ESP8266WiFi.h>
    #include <ESPAsyncTCP.h>
    #include <FS.h>
#elif defined(ESP32)
    #include <WiFi.h>
    #include <AsyncTCP.h>
    #include <SPIFFS.h>
#endif

#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

const char* ssid     = "-------------";
const char* password = "-------------";
const char* hostname = "ESP_SanUSB";

void setup(void)
{
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(115200);
  SPIFFS.begin();
	
   WiFi.mode(WIFI_STA);
   WiFi.begin(ssid, password);

   while (WiFi.status() != WL_CONNECTED) 
   { 
     delay(500);  
     Serial.print('.'); 
   }
 
   Serial.println("");
   Serial.print("Iniciado STA:\t");
   Serial.println(ssid);
   Serial.print("IP address:\t");
   Serial.println(WiFi.localIP());
//**********************************************************

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");
  });
 
  server.on("/demo.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/demo.js", "text/javascript");
  });

  server.onNotFound([](AsyncWebServerRequest *request) {
    request->send(400, "text/plain", "Not found");
  });

  server.begin();
  Serial.println("HTTP server started");
}


 void handleFormLed(AsyncWebServerRequest *request)
{
 String ledStatus = request->arg("status");
 
 Serial.print("Status:\t");
 Serial.println(ledStatus);

 digitalWrite(LED_BUILTIN, ledStatus == "ON" ? LOW : HIGH);

 request->redirect("/"); //volta para a página original sem argumento
}

void loop(void)
{
}
