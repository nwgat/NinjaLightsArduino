#include <ESPHue.h>
#include <WiFiClient.h>
#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"
#include <IRremoteESP8266.h>
#include <IRsend.h>
ESP8266WebServer server(80);
WiFiClient client;

void setup() {
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
  WiFi.softAPdisconnect(false);
  WiFi.enableAP(false);
  WiFi.begin("network24", "password");  //Connect to the WiFi network
    while (WiFi.status() != WL_CONNECTED) {  //Wait for connection 
    delay(500);
    Serial.println("Waiting to connect…");
 
  }
 
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //Print the local IP
 
  server.on("/on", []() {   //Define the handling function for the path
 
    server.send(200, "text / plain", "Switching to USB input");
    #define IR_LED D3  
    IRsend irsend(IR_LED);  // Set the GPIO to be used to sending the message.
    uint16_t rawData[71] = {8992, 4494,  574, 558,  572, 558,  574, 558,  574, 558,  574, 558,  572, 558,  572, 556,  572, 1660,  572, 1658,  574, 1658,  574, 1658,  574, 1660,  574, 1660,  574, 1660,  574, 1658,  602, 528,  574, 558,  574, 1658,  576, 556,  574, 556,  574, 1660,  574, 556,  574, 554,  574, 554,  574, 1658,  574, 556,  574, 1656,  576, 1658,  576, 556,  574, 1658,  576, 1656,  576, 1658,  576, 39978,  8994, 2256,  578};
    irsend.begin();
    irsend.sendRaw(rawData, 71, 38);  // Send a raw data capture at 38kHz.
    server.send(200, "text / plain", " Turning down lights");
    ESPHue myHue = ESPHue(client,"apikey", "huebridgeip", 80);
    myHue.setGroupPower(1, myHue.OFF);
    myHue.setGroupPower(2, myHue.OFF);
  });
 
  server.on("/", handleRootPath);    //Associate the handler function to the path
  server.begin();                    //Start the server
  Serial.println("Server listening");
 
}
 
void loop() {
 
  server.handleClient();         //Handling of incoming requests
 
}
 
void handleRootPath() {            //Handler for the rooth path
 
  server.send(200, "text/plain", "NinjaLights");
 
}
