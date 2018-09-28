#include <ThingSpeak.h>
#include <ESP8266WiFi.h>

const char* ssid = "U R Hacked";
const char* password = "1223334444";

int pin = 2;  //lamp connected to pin 2 of nodemcu
int lamp = 1;
unsigned long speak = 584014;

WiFiClient client;
void setup() {
 
  Serial.begin(115200);
  delay(500);

  pinMode(pin, OUTPUT);

  digitalWrite(pin,0);
  
  Serial.println("Connecting to WIFI: ");
  Serial.println(ssid);

  WiFi.begin(ssid,password);

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println(".");
  }

  Serial.print("Connected to: ");
  Serial.println(ssid);

  Serial.print("The IP address is: ");
  Serial.println(WiFi.localIP());
  Serial.print("The Subnet mask is: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("The gateway is: ");
  Serial.println(WiFi.gatewayIP());

  ThingSpeak.begin(client);
}
void loop() {
  int lamp_val = ThingSpeak.readFloatField(speak,lamp);
  if(lamp_val == 0){
    digitalWrite(pin,1);
    Serial.println("Lamp is off!"); 
  }
  else{
    digitalWrite(pin,0);
    Serial.println("Lamp is on!");
  }
  delay(5000);
}
