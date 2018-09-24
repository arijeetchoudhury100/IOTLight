//#include <WiFiClientSecureAxTLS.h>
//#include <ESP8266WiFiSTA.h>
//#include <WiFiClientSecure.h>
//#include <WiFiClient.h>
//#include <ESP8266WiFiAP.h>
//#include <WiFiServer.h>
//#include <BearSSLHelpers.h>
//#include <CertStoreBearSSL.h>
//#include <WiFiServerSecure.h>
//#include <WiFiClientSecureBearSSL.h>
//#include <WiFiServerSecureAxTLS.h>
//#include <ESP8266WiFiMulti.h>
//#include <ESP8266WiFiType.h>
//#include <WiFiServerSecureBearSSL.h>
//#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFi.h>
//#include <WiFiUdp.h>
//#include <ESP8266WiFiScan.h>

/*
  ESP8266 Blink by Simon Peter
  Blink the blue LED on the ESP-01 module
  This example code is in the public domain

  The blue LED on the ESP-01 module is connected to GPIO1
  (which is also the TXD pin; so we cannot use Serial.print() at the same time)

  Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/
const char* ssid = "U R Hacked";
const char* password = "1223334444";

int ledpin = 2;//D4 in nodemcu

WiFiServer  server(80);
void setup() {
  Serial.begin(115200); 
  delay(10); 
  pinMode(ledpin,OUTPUT); 
  digitalWrite(ledpin,LOW); 
  //connect to WiFi network 
  Serial.println(); 
  Serial.println(); 
  Serial.print("Connecting to "); 
  Serial.println(ssid); 
  WiFi.begin(ssid,password); 
  while (WiFi.status()!=WL_CONNECTED) 
  { delay(500); 
    Serial.print("."); 
  } 
  Serial.println(""); 
  Serial.println("WiFi connected"); 
  // Start the server 
  server.begin(); 
  Serial.println("Server started"); 
  //Print the IP Address 
  Serial.print("Use this url to connect: "); 
  Serial.print("http://"); 
  Serial.print(WiFi.localIP()); 
  Serial.println("/");
}

// the loop function runs over and over again forever
void loop() {
 // Check if a client has connected 
 WiFiClient client = server.available(); 
 if (!client) { return; } 
 //Wait until the client sends some data 
 Serial.println("new client"); 
 while (!client.available()) 
 { delay(1); } 
 // Read the first line of the request 
 String request = client.readStringUntil('\r'); 
 Serial.println(request); 
 client.flush(); 
 //Match the request 
 int value=LOW; 
 if (request.indexOf(" /LED=ON")!=-1) 
 { 
  digitalWrite(ledpin,1); 
  value=HIGH ; 
 } 
 if (request.indexOf(" /LED=OFF")!=-1) 
 { 
  digitalWrite(ledpin,0); 
  value=LOW ; 
 } 
 // Set ledpin according to the request 
 client.println("HTTP/1.1 200 OK"); 
 client.println("Content-Type: text/html"); 
 client.println(""); 
 client.println("<!DOCTYPE HTML>"); 
 client.println("<html>"); 
 client.println("<title>switch</title>");
 client.print("Led pin is now: "); 
 if (value==HIGH) 
 { 
  client.print("OFF"); 
 } 
 else 
 { 
  client.print("ON"); 
 }
 client.println("<br><br>");
 client.println("<a href=\"/LED=OFF\"\"><button>Turn <b>ON</b></button></a>"); 
 client.println("<a href=\"/LED=ON\"\"><button>Turn <b>OFF</b></button></a></br>"); 
 client.println("</html>"); 
 delay(1); 
 Serial.println("Client disconnected"); 
 Serial.println("");                // Wait for two seconds (to demonstrate the active low LED)
}
