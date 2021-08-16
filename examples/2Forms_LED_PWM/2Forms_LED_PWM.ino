/*
Exemplo 2Form_LED_PWM.ino (Comutar a intensidade luminosa do pino por PWM no ESP32 e ESP8266 através de página html e Javascript na memória SPIFFS): https://youtu.be/5d9Z8eptu8A  
Esse exemplo faz parte de mais uma aplicação Async com código disponível nos exemplos do repositório https://github.com/SanUSB/AsyncIOT onde 
todas as bibliotecas Async descritas no README do repositório devem ser previamente instaladas.
 */

#if defined(ESP8266)
    #include <ESP8266WiFi.h>
    #include <ESPAsyncTCP.h>
    #include <FS.h>
#elif defined(ESP32)
    #include <WiFi.h>
    #include <AsyncTCP.h>
    #include <SPIFFS.h>
    const int LED_PIN = 2;
    const int freq = 5000;
    const int ledChannel = 0;
    const int resolution = 8;
#endif

#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

const char* ssid     = "SanUSB";
const char* password = "sanusblaese19";
const char* hostname = "ESP_SanUSB";

void setup(void)
{
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(115200);
  SPIFFS.begin();
  #if defined(ESP32)
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_PIN, ledChannel);
  #endif
	
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

  server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html"); //pagina no SPIFFS

  server.on("/LED", HTTP_POST, handleFormPWM);

  server.onNotFound([](AsyncWebServerRequest *request) {
    request->send(400, "text/plain", "Not found");
  });

  server.begin();
  Serial.println("HTTP server started");
}


void handleFormPWM(AsyncWebServerRequest *request)
{
 String pwmValue = request->arg("pwmValue");
 
 Serial.print("PWM:\t");
 Serial.println(pwmValue);

  #if defined(ESP8266)
  analogWrite(LED_BUILTIN, 1023 - pwmValue.toInt());
  #elif defined(ESP32)
  ledcWrite(ledChannel, pwmValue.toInt()); //1023 - pwmValue.toInt()
  #endif
 
 request->redirect("/");
}

void loop(void)
{
}
