// Includes
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

// Defines
#define WIFI_AP "Dbz-Otthon"
#define WIFI_PASSWORD "19850317"
#define TOKEN "JTMNEoX4rwH3XaWuvrNN"
#define BUTTON_RED D7
#define BUTTON_WHITE D1
#define LED_RED D2
#define LED_YELLOW D3
#define LED_GREEN D4
#define RELAY_IN1 D5
#define RELAY_IN2 D6

// Variables
char thingsboardServer[] = "192.168.1.35";
bool state_BUTTON_RED, state_BUTTON_WHITE, state_LED_RED, state_LED_YELLOW, state_LED_GREEN, state_RELAY_IN1, state_RELAY_IN2;
bool lastState_BUTTON_RED, lastState_BUTTON_WHITE;
//unsigned long lastSend;

//ETC
WiFiClient wifiClient;
PubSubClient client(wifiClient);
int status = WL_IDLE_STATUS;

void setup()
{
  Serial.begin(115200);
  //lastSend = 0;

  // Init states
  state_BUTTON_RED = state_BUTTON_WHITE = state_LED_RED = state_LED_YELLOW = state_LED_GREEN = state_RELAY_IN1 = state_RELAY_IN2 = false;
  lastState_BUTTON_RED = lastState_BUTTON_WHITE = false;

  // Init GPIOs
  pinMode(BUTTON_RED, INPUT);
  pinMode(BUTTON_WHITE, INPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(RELAY_IN1, OUTPUT);
  pinMode(RELAY_IN2, OUTPUT);

  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_YELLOW, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(RELAY_IN1, HIGH);
  digitalWrite(RELAY_IN2, HIGH);

  // Init WiFI
  InitWiFi();

  // Init Thingsboard
  client.setServer(thingsboardServer, 1883);
  client.setCallback(on_message);
}

void loop()
{
  loopInputs();

  if (!client.connected())
  {
    Reconnect();
  }

  /*
  if ( millis() - lastSend > 1000 ) // Update and send only after 1 seconds
  {
    //getAndSendData();
    lastSend = millis();
  }
  */

  client.loop();
}

void loopInputs()
{
  // Piros gomb toggle piros led
  lastState_BUTTON_RED = state_BUTTON_RED;
  state_BUTTON_RED = digitalRead(BUTTON_RED);
  if (lastState_BUTTON_RED == HIGH && state_BUTTON_RED == LOW)
  {
    state_LED_RED = !state_LED_RED;
    set_gpio_status(2, state_LED_RED);
    client.publish("v1/devices/me/attributes", get_gpio_status().c_str());
  } 

  // Fehér gomb
  lastState_BUTTON_WHITE = state_BUTTON_WHITE;  
  state_BUTTON_WHITE = digitalRead(BUTTON_WHITE);
  if (lastState_BUTTON_WHITE != state_BUTTON_WHITE)
  {
    client.publish("v1/devices/me/attributes", get_gpio_status().c_str());
  }
}

void on_message(const char* topic, byte* payload, unsigned int length)
{

  Serial.println("On message");

  char json[length + 1];
  strncpy (json, (char*)payload, length);
  json[length] = '\0';

  Serial.print("Topic: ");
  Serial.println(topic);
  Serial.print("Message: ");
  Serial.println(json);

  // Decode JSON request
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& data = jsonBuffer.parseObject((char*)json);

  if (!data.success())
  {
    Serial.println("parseObject() failed");
    return;
  }

  // Check request method
  String methodName = String((const char*)data["method"]);

  if (methodName.equals("getGpioStatus"))
  {
    // Reply with GPIO status
    String responseTopic = String(topic);
    responseTopic.replace("request", "response");
    client.publish(responseTopic.c_str(), get_gpio_status().c_str());
  }
  
  else if (methodName.equals("setGpioStatus"))
  {
    // Update GPIO status and reply
    set_gpio_status(data["params"]["pin"], data["params"]["enabled"]);
    String responseTopic = String(topic);
    responseTopic.replace("request", "response");
    client.publish(responseTopic.c_str(), get_gpio_status().c_str());
    client.publish("v1/devices/me/attributes", get_gpio_status().c_str());
  }
}

String get_gpio_status()
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& data = jsonBuffer.createObject();
  
  data[String(2)] = state_LED_RED ? true : false;
  data[String(3)] = state_LED_YELLOW ? true : false;
  data[String(4)] = state_LED_GREEN ? true : false;
  data[String(5)] = state_RELAY_IN1 ? true : false;
  data[String(6)] = state_RELAY_IN2 ? true : false;
  data[String(7)] = state_BUTTON_RED ? true : false;
  data[String(1)] = state_BUTTON_WHITE ? true : false;
  
  char payload[256];
  data.printTo(payload, sizeof(payload));
  String strPayload = String(payload);
  Serial.print("Get gpio status: ");
  Serial.println(strPayload);
  return strPayload;
}

void set_gpio_status(int pin, boolean enabled)
{
  if (pin == 2)
  {
    digitalWrite(LED_RED, enabled ? LOW : HIGH);
    state_LED_RED = enabled;
  }  
  else if (pin == 3)
  {
    digitalWrite(LED_YELLOW, enabled ? LOW : HIGH);
    state_LED_YELLOW = enabled;
  }
  else if (pin == 4)
  {
    digitalWrite(LED_GREEN, enabled ? LOW : HIGH);
    state_LED_GREEN = enabled;
  }
  else if (pin == 5)
  {
    digitalWrite(RELAY_IN1, enabled ? LOW : HIGH);
    state_RELAY_IN1 = enabled;
  }
  else if (pin == 6)
  {
    digitalWrite(RELAY_IN2, enabled ? LOW : HIGH);
    state_RELAY_IN2 = enabled;
  }
}

void InitWiFi()
{
  Serial.print("Connecting to: ");
  Serial.println(WIFI_AP);

  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi!");
}

void Reconnect()
{
  while (!client.connected())
  {
    status = WiFi.status();
    if (status != WL_CONNECTED)
    {
      InitWiFi();
    }

    Serial.println("Connecting to ThingsBoard");
    if (client.connect("Test-Send-Receive", TOKEN, NULL))
    {
      Serial.println("DONE!");
      // Subscribing to receive RPC requests
      client.subscribe("v1/devices/me/rpc/request/+");
      // Sending current GPIO status
      Serial.println("Sending current GPIO status ...");
      client.publish("v1/devices/me/attributes", get_gpio_status().c_str());
    }
    else
    {
      Serial.print("FAILED! [rc = ");
      Serial.print(client.state());
      Serial.println(" : retrying in 1 second]");
      delay(1000);
    }
  }
}
