#include <ESP8266WiFi.h>
const char* ssid     = "SSID";       // ssid of the router 
const char* password = "PASSWORD";   // password of the router
String buf;
IPAddress ip(192,168,225,5);           // IP Address of the client
WiFiServer server(2222);               // PORT to which data is send
WiFiClient cl;

void setup() 
{
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1);
  }
  server.begin();
  server.setNoDelay(true);
}

void loop()
{
 while(WiFi.status() != WL_CONNECTED)
  {
    WiFi.begin(ssid, password);
    delay(1);
  }
 
  if(cl.connect(ip,2222))
  {
    buf=Serial.readStringUntil('\n');
    cl.print(buf);
  }
}
   
  
