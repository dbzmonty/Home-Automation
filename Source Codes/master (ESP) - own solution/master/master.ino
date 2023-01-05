// NodeMCU WebServer

// Includes
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <EMailSender.h>
#include <ArduinoJson.h>
#include "Arduino.h"
#include "index.h"

// Defines
#define ssid      "Dbz-Home"
#define password  "19850317_"
#define LCD_RST D3

// Globals
ESP8266WebServer server (80);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 3600);
EMailSender emailSend("dbzmonty@gmail.com", "guzvjvzqsteradhn");

char i2c_buffer[33];
bool d01, d02, d03, d04, d05, d06, d07, d08, d09, d10, d11, d12, d13, d14, d15, d16, d17, d18, d19, d20, d21, d22, n01, n02, n03, n04, n05, n06, n07, n08, n09, n10, n11;
bool _d01, _d02, _d03, _d04, _d05, _d06, _d07, _d08, _d09, _d10, _d11, _d12, _d13, _d14, _d15, _d16, _d17, _d18, _d19, _d20, _d21, _d22, _n01, _n02, _n03, _n04, _n05, _n06, _n07, _n08, _n09, _n10, _n11;

void setup()
{
  d01 = d02 = d03 = d04 = d05 = d06 = d07 = d08 = d09 = d10 = d11 = d12 = d13 = d14 = d15 = d16 = d17 = d18 = d19 = d20 = d21 = d22 = n01 = n02 = n03 = n04 = n05 = n06 = n07 = n08 = n09 = n10 = n11 = false;
  _d01 = _d02 = _d03 = _d04 = _d05 = _d06 = _d07 = _d08 = _d09 = _d10 = _d11 = _d12 = _d13 = _d14 = _d15 = _d16 = _d17 = _d18 = _d19 = _d20 = _d21 = _d22 = _n01 = _n02 = _n03 = _n04 = _n05 = _n06 = _n07 = _n08 = _n09 = _n10 = _n11 = false;
  i2c_buffer[32] = '\0';

  pinMode(LCD_RST, OUTPUT);
  digitalWrite(LCD_RST, LOW);  
  Wire.begin();
  digitalWrite(LCD_RST, HIGH);
  
  Serial.begin(115200);
  Serial.println("I2C Master ready!");
  
  initializeWiFi();
  emailSnd("Smart Home booted", "Initialized");
}

void initializeWiFi()
{
  WiFi.begin (ssid, password);
  
  while (WiFi.status() != WL_CONNECTED)
  {
    delay (500);
    Serial.print (".");
  }
  
  Serial.println (""); 
  Serial.print ("Connected to "); Serial.println (ssid);
  Serial.print ("IP address: "); Serial.println (WiFi.localIP());

  timeClient.begin();
  
  server.on("/", handleRoot);
  server.on("/btnPressed", btnPressed);
  server.on("/getStates", getStates);
  server.begin();
  
  logMessage("HTTP started");
}

void loop()
{
  server.handleClient();
  requestJson();
  checkJsonChanged();
  delay(100);
}

void requestJson()
{
  for (int i = 0; i < 11; i++)
  {
    Wire.requestFrom(0xDD, 32);
    
    for (byte i = 0; i < 32 && Wire.available(); ++i)
    {
      i2c_buffer[i] = Wire.read();

      if (i2c_buffer[i] == '#')
      {
        i2c_buffer[i] = '\0';
        break;
      }
    }
    // Itt van kész egy csomag
    actualizeVariablesFromJson();
  }
}

void actualizeVariablesFromJson()
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(i2c_buffer);

  if (!root.success())
  {
    Serial.println("parseObject() failed");
    return;
  }

  if (root.containsKey("d01")) d01 = root["d01"];
  if (root.containsKey("d02")) d02 = root["d02"];
  if (root.containsKey("d03")) d03 = root["d03"];
  if (root.containsKey("d04")) d04 = root["d04"];
  if (root.containsKey("d05")) d05 = root["d05"];
  if (root.containsKey("d06")) d06 = root["d06"];
  if (root.containsKey("d07")) d07 = root["d07"];
  if (root.containsKey("d08")) d08 = root["d08"];
  if (root.containsKey("d09")) d09 = root["d09"];
  if (root.containsKey("d10")) d10 = root["d10"];
  if (root.containsKey("d11")) d11 = root["d11"];
  if (root.containsKey("d12")) d12 = root["d12"];
  if (root.containsKey("d13")) d13 = root["d13"];
  if (root.containsKey("d14")) d14 = root["d14"];
  if (root.containsKey("d15")) d15 = root["d15"];
  if (root.containsKey("d16")) d16 = root["d16"];
  if (root.containsKey("d17")) d17 = root["d17"];
  if (root.containsKey("d18")) d18 = root["d18"];
  if (root.containsKey("d19")) d19 = root["d19"];
  if (root.containsKey("d20")) d20 = root["d20"];
  if (root.containsKey("d21")) d21 = root["d21"];
  if (root.containsKey("d22")) d22 = root["d22"];
  
  if (root.containsKey("n01")) n01 = root["n01"];
  if (root.containsKey("n02")) n02 = root["n02"];
  if (root.containsKey("n03")) n03 = root["n03"];
  if (root.containsKey("n04")) n04 = root["n04"];
  if (root.containsKey("n05")) n05 = root["n05"];
  if (root.containsKey("n06")) n06 = root["n06"];
  if (root.containsKey("n07")) n07 = root["n07"];
  if (root.containsKey("n08")) n08 = root["n08"];
  if (root.containsKey("n09")) n09 = root["n09"];
  if (root.containsKey("n10")) n10 = root["n10"];
  if (root.containsKey("n11")) n11 = root["n11"];
}

void handleRoot()
{ 
  Serial.println("Handling root");
  server.send (200, "text/html", String(webpage));
}

void btnPressed()
{
  String btn = server.arg("btn");

  if (btn == "d01")
  {
    sendMessage("d01");
    server.send(200, "text/plane", String(d01));
  }
  else if (btn == "d02")
  {
    sendMessage("d02");
    server.send(200, "text/plane", String(d02));
  }
  else if (btn == "d03")
  {
    sendMessage("d03");
    server.send(200, "text/plane", String(d03));
  }
  else if (btn == "d04")
  {
    sendMessage("d04");
    server.send(200, "text/plane", String(d04));
  }
  else if (btn == "d05")
  {
    sendMessage("d05");
    server.send(200, "text/plane", String(d05));
  }
  else if (btn == "d06")
  {
    sendMessage("d06");
    server.send(200, "text/plane", String(d06));
  }
  else if (btn == "d07")
  {
    sendMessage("d07");
    server.send(200, "text/plane", String(d07));
  }
  else if (btn == "d08")
  {
    sendMessage("d08");
    server.send(200, "text/plane", String(d08));
  }
  else if (btn == "d09")
  {
    sendMessage("d09");
    server.send(200, "text/plane", String(d09));
  }
  else if (btn == "d10")
  {
    sendMessage("d10");
    server.send(200, "text/plane", String(d10));
  }
  else if (btn == "d11")
  {
    sendMessage("d11");
    server.send(200, "text/plane", String(d11));
  }
  else if (btn == "d12")
  {
    sendMessage("d12");
    server.send(200, "text/plane", String(d12));
  }
  else if (btn == "d14")
  {
    sendMessage("d14");
    server.send(200, "text/plane", String(d14));
  }
  else if (btn == "d20")
  {
    sendMessage("d20");
    server.send(200, "text/plane", String(d20));
  }
  else if (btn == "n10")
  {
    sendMessage("n10");
    server.send(200, "text/plane", String(n10));
  }
}

void sendMessage(char gpio[])
{
  Wire.beginTransmission(0xDD);
  Wire.write(gpio);
  Wire.endTransmission();
  Serial.println(gpio);  
}

void logMessage(String msg)
{
  timeClient.update();
  int h = timeClient.getHours();
  int m = timeClient.getMinutes();
  String sH = h < 10 ? "0" + String(h) : String(h);
  String sM = m < 10 ? "0" + String(m) : String(m);  
  String currentTime = sH + ":" + sM + " ";
  String message = currentTime + msg;
  
  int str_len = message.length() + 1;
  char char_array[str_len];
  message.toCharArray(char_array, str_len);
  
  Wire.beginTransmission(0xAA);
  Wire.write(char_array);
  Wire.endTransmission();
}

void emailSnd(String sbj, String msg)
{
  EMailSender::EMailMessage message;
  message.subject = sbj;
  message.message = msg;

  EMailSender::Response resp = emailSend.send("dbzmonty@gmail.com", message);
}

void checkJsonChanged()
{
  if (_n08 == 0 && n08 == 1) logMessage("Bejarati ajto");
  if (_n09 == 0 && n09 == 1) logMessage("Muhely ajto");
  if (_n10 == 0 && n10 == 1)
  {
    logMessage("Posta van");
    emailSnd("You have a mail!", "Check post box!");
  }  
  
  if (_d01 != d01 || _d02 != d02 || _d03 != d03 || _d04 != d04 || _d05 != d05 || _d06 != d06 || _d07 != d07 || _d08 != d08 || _d09 != d09 || _d10 != d10 || _d11 != d11 ||
      _d12 != d12 || _d13 != d13 || _d14 != d14 || _d15 != d15 || _d16 != d16 || _d17 != d17 || _d18 != d18 || _d19 != d19 || _d20 != d20 || _d21 != d21 || _d22 != d22 ||
      _n01 != n01 || _n02 != n02 || _n03 != n03 || _n04 != n04 || _n05 != n05 || _n06 != n06 || _n07 != n07 || _n08 != n08 || _n09 != n09 || _n10 != n10 || _n11 != n11)
    {
      Serial.println("Something changed...");
      actualizePrevBooleanValues();    
    }
}

void actualizePrevBooleanValues()
{
  _d01 = d01; _d02 = d02; _d03 = d03; _d04 = d04; _d05 = d05; _d06 = d06; _d07 = d07; _d08 = d08; _d09 = d09; _d10 = d10; _d11 = d11;
  _d12 = d12; _d13 = d13; _d14 = d14; _d15 = d15; _d16 = d16; _d17 = d17; _d18 = d18; _d19 = d19; _d20 = d20; _d21 = d21; _d22 = d22;
  _n01 = n01; _n02 = n02; _n03 = n03; _n04 = n04; _n05 = n05; _n06 = n06; _n07 = n07; _n08 = n08; _n09 = n09; _n10 = n10; _n11 = n11;
}

void getStates()
{
   server.send(200, "text/plane", prepareJson());
}

String prepareJson()
{
  StaticJsonBuffer<400> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root["d01"] = d01;
  root["d02"] = d02;
  root["d03"] = d03;
  //  root["d04"] = d04;
  root["d05"] = d05;
  root["d06"] = d06;
  root["d07"] = d07;
  root["d08"] = d08;
  root["d09"] = d09;
  root["d10"] = d10;
  root["d11"] = d11;
  root["d12"] = d12;  
  //  root["d13"] = d13;  
  root["d14"] = d14;
  //  root["d15"] = d15;  
  //  root["d16"] = d16;
  //  root["d17"] = d17;
  //  root["d18"] = d18;
  //  root["d19"] = d19;
  root["d20"] = d20;
  //  root["d21"] = d21;
  //  root["d22"] = d22;
  root["n01"] = n01;
  root["n02"] = n02;
  root["n03"] = n03;
  root["n04"] = n04;
  root["n05"] = n05;
  root["n06"] = n06;
  root["n07"] = n07;
  root["n08"] = n08;
  root["n09"] = n09;
  root["n10"] = n10;
  root["n11"] = n11;

  char jsonChar[400];
  root.printTo((char*)jsonChar, root.measureLength() + 1);

  return String(jsonChar);
}
