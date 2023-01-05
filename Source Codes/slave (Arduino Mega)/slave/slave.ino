// Arduino Mega controller

#include <Wire.h>
#include <ArduinoJson.h>

// Data transfer
const byte DATA_SIZE = 11;
String data[DATA_SIZE]; 
String incomingData;

// Timer
unsigned long startMillis = 0;
unsigned long currentMillis;
const unsigned long timerPeriod = 300000; // 5 * 60 * 1000 == 5p

// Declare GPIO booleans
bool D3, D5, D7, D9, D11, D13, D15, D17, D19, D23, D25, D27, D29, D30, D31, D32, D33, D34, D35, D36, D37, D38, D39, D40, D41, D42, D43, D44, D45, D46, D47, D54, D55, D56, D57, D58, D59, D60, D61, D62, D63, D64, D65, D66, D67, D68, D69;
bool btn47, btn54, btn55, btn56, btn57, btn58, btn59, btn60, btn61, btn62, btn63, btn64, btn66, btn68;
bool last_btn47, last_btn54, last_btn55, last_btn56, last_btn57, last_btn58, last_btn59, last_btn60, last_btn61, last_btn62, last_btn63, last_btn64, last_btn66, last_btn68;
bool in32, in34, in36, in38, in40, in41, in42, in43, in44, in45, in46;

const uint8_t INPUTS[25] = {32, 34, 36, 38, 40, 41, 42, 43, 44, 45, 46, 47, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 68};
const uint8_t OUTPUTS[22] = {3, 5, 7, 9, 11, 13, 15, 17, 19, 23, 25, 27, 29, 30, 31, 33, 35, 37, 39, 65, 67, 69};

void setup()
{
  D3 = D5 = D7 = D9 = D11 = D13 = D15 = D17 = D19 = D23 = D25 = D27 = D29 = D30 = D31 = D32 = D33 = D34 = D35 = D36 = D37 = D38 = D39 = D40 = D41 = D42 = D43 = D44 = D45 = D46 = D47 = D54 = D55 = D56 = D57 = D58 = D59 = D60 = D61 = D62 = D63 = D64 = D65 = D66 = D67 = D68 = D69 = false;
  btn47 = btn54 = btn55 = btn56 = btn57 = btn58 = btn59 = btn60 = btn61 = btn62 = btn63 = btn64 = btn66 = btn68 = false;
  last_btn47 = last_btn54 = last_btn55 = last_btn56 = last_btn57 = last_btn58 = last_btn59 = last_btn60 = last_btn61 = last_btn62 = last_btn63 = last_btn64 = last_btn66 = last_btn68 = false;
  in32 = in34 = in36 = in38 = in40 = in41 = in42 = in43 = in44 = in45 = in46 = false;
  
  // Initialize input GPIO-s
  for (int i = 0 ; i < 25 ; i++)
  { 
    pinMode(INPUTS[i], INPUT);
  }

  // Initialize output GPIO-s
  for (int i = 0 ; i < 22 ; i++)
  { 
    pinMode(OUTPUTS[i], OUTPUT);
    digitalWrite(OUTPUTS[i], HIGH);
  }
  
  Wire.begin(0xDD);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

  Serial.begin(115200);
  Serial.println("I2C Slave ready!");
}

void loop()
{
  loopInputs();
  checkTimer();
  loopOutputs();
  prepareJson();

  delay(100);
}

void loopInputs()
{
  // Udvar Ház Sarkai
  last_btn47 = btn47;
  btn47 = digitalRead(47);
  if (last_btn47 == HIGH && btn47 == LOW) D19 = !D19;
  
  // Udvar Álló Lámpák
  last_btn54 = btn54;
  btn54 = digitalRead(54);
  if (last_btn54 == HIGH && btn54 == LOW) D23 = !D23;

  // Udvar Fészer
  last_btn55 = btn55;
  btn55 = digitalRead(55);
  if (last_btn55 == HIGH && btn55 == LOW) D25 = !D25;

  // Nagy-folyosó
  last_btn56 = btn56;
  btn56 = digitalRead(56);
  if (last_btn56 == HIGH && btn56 == LOW) D15 = !D15;

  // Műhely
  last_btn57 = btn57;
  btn57 = digitalRead(57);
  if (last_btn57 == HIGH && btn57 == LOW) D3 = !D3;

  // Konyha
  last_btn58 = btn58;
  btn58 = digitalRead(58);
  if (last_btn58 == HIGH && btn58 == LOW) D5 = !D5;

  // Kis-folyosó
  last_btn59 = btn59;
  btn59 = digitalRead(59);
  if (last_btn59 == HIGH && btn59 == LOW) D13 = !D13;

  // Fürdő
  last_btn60 = btn60;
  btn60 = digitalRead(60);
  if (last_btn60 == HIGH && btn60 == LOW)
  {    
    D7 = !D7;

    if (!D7 && D65) // Ha leoltottam a villanyt és a szellőző megy
    {
      startMillis = millis(); // Az aktuális időt megadom az időzítőnek
    }
  }

  // Spájz
  last_btn61 = btn61;
  btn61 = digitalRead(61);
  if (last_btn61 == HIGH && btn61 == LOW) D30 = !D30;

  // Háló
  last_btn62 = btn62;
  btn62 = digitalRead(62);
  if (last_btn62 == HIGH && btn62 == LOW) D11 = !D11;

  // Nappali
  last_btn63 = btn63;
  btn63 = digitalRead(63);
  if (last_btn63 == HIGH && btn63 == LOW) D17 = !D17;

  // Padlás
  last_btn64 = btn64;
  btn64 = digitalRead(64);
  if (last_btn64 == HIGH && btn64 == LOW) D27 = !D27;

  // Csengő
  btn66 = digitalRead(66);
  if (btn66 == HIGH) D31 = true;
  else D31 = false;

  // Szellőztető
  last_btn68 = btn68;
  btn68 = digitalRead(68);
  if (last_btn68 == HIGH && btn68 == LOW) D65 = !D65;

  // Nyitásérzékelő Háló ablak
  in36 = digitalRead(36);
  if (in36 == HIGH) D36 = false;
  else D36 = true;

  // Nyitásérzékelő Nappali ablak
  in38 = digitalRead(38);
  if (in38 == HIGH) D38 = false;
  else D38 = true;

  // Nyitásérzékelő Nagy-folyosó 1
  in40 = digitalRead(40);
  if (in40 == HIGH) D40 = false;
  else D40 = true;

  // Nyitásérzékelő Nagy-folyosó 2
  in41 = digitalRead(41);
  if (in41 == HIGH) D41 = false;
  else D41 = true;

  // Nyitásérzékelő Nagy-folyosó 3
  in46 = digitalRead(46);
  if (in46 == HIGH) D46 = false;
  else D46 = true;

  // Nyitásérzékelő Bejárati ajtó
  in43 = digitalRead(43);
  if (in43 == HIGH) D43 = false;
  else D43 = true;

  // Nyitásérzékelő Műhely ajtó
  in44 = digitalRead(44);
  if (in44 == HIGH) D44 = false;
  else D44 = true;

  // Nyitásérzékelő Műhely ablak
  in42 = digitalRead(42);
  if (in42 == HIGH) D42 = false;
  else D42 = true;

  // Nyitásérzékelő Fürdő ablak
  in32 = digitalRead(32);
  if (in32 == HIGH) D32 = false;
  else D32 = true;

  // Nyitásérzékelő Spájz ablak
  in34 = digitalRead(34);
  if (in34 == HIGH) D34 = false;
  else D34 = true;

  // Postaláda
  in45 = digitalRead(45);
  if (in45 == HIGH) D45 = true;
}

void checkTimer()
{
  if (0 < startMillis)
  {
    currentMillis = millis();
    
    if (timerPeriod <= currentMillis - startMillis)
    {
      D65 = false;
      startMillis = 0;
    }
  }
}

void loopOutputs()
{
  D3  ? digitalWrite(3, LOW)  : digitalWrite(3, HIGH);
  D5  ? digitalWrite(5, LOW)  : digitalWrite(5, HIGH);
  D7  ? digitalWrite(7, LOW)  : digitalWrite(7, HIGH);
  D9  ? digitalWrite(9, LOW)  : digitalWrite(9, HIGH);
  D11 ? digitalWrite(11, LOW) : digitalWrite(11, HIGH);
  D13 ? digitalWrite(13, LOW) : digitalWrite(13, HIGH);
  D15 ? digitalWrite(15, LOW) : digitalWrite(15, HIGH);
  D17 ? digitalWrite(17, LOW) : digitalWrite(17, HIGH);
  D19 ? digitalWrite(19, LOW) : digitalWrite(19, HIGH);
  D23 ? digitalWrite(23, LOW) : digitalWrite(23, HIGH);
  D25 ? digitalWrite(25, LOW) : digitalWrite(25, HIGH);
  D27 ? digitalWrite(27, LOW) : digitalWrite(27, HIGH);
  D29 ? digitalWrite(29, LOW) : digitalWrite(29, HIGH);
  D30 ? digitalWrite(30, LOW) : digitalWrite(30, HIGH);
  D31 ? digitalWrite(31, LOW) : digitalWrite(31, HIGH);
  D33 ? digitalWrite(33, LOW) : digitalWrite(33, HIGH);
  D35 ? digitalWrite(35, LOW) : digitalWrite(35, HIGH);
  D37 ? digitalWrite(37, LOW) : digitalWrite(37, HIGH);
  D39 ? digitalWrite(39, LOW) : digitalWrite(39, HIGH);
  D65 ? digitalWrite(65, LOW) : digitalWrite(65, HIGH);
  D67 ? digitalWrite(67, LOW) : digitalWrite(67, HIGH);
  D69 ? digitalWrite(69, LOW) : digitalWrite(69, HIGH);
}

void receiveEvent(int numBytes)
{
  incomingData = "";
  
  while (Wire.available())
  {
    char c = Wire.read();
    incomingData += c;
  }
  
  if      (incomingData == "d01") D3 = !D3;
  else if (incomingData == "d02") D5 = !D5;
  else if (incomingData == "d03") D7 = !D7;
  else if (incomingData == "d04") D9 = !D9;
  else if (incomingData == "d05") D11 = !D11;
  else if (incomingData == "d06") D13 = !D13;
  else if (incomingData == "d07") D15 = !D15;
  else if (incomingData == "d08") D17 = !D17;
  else if (incomingData == "d09") D19 = !D19;
  else if (incomingData == "d10") D23 = !D23;
  else if (incomingData == "d11") D25 = !D25;
  else if (incomingData == "d12") D27 = !D27;
  else if (incomingData == "d14") D30 = !D30;
  else if (incomingData == "d20") D65 = !D65;
  else if (incomingData == "n10") D45 = false;
}

void requestEvent()
{
  static byte req_number = 0;
  Wire.write(reinterpret_cast < const unsigned char* > (data[req_number].c_str()), data[req_number].length());
  req_number = (req_number + 1) % DATA_SIZE;
}

void prepareJson()
{
  prepareJson00();
  prepareJson01();
  prepareJson02();
  prepareJson03();
  prepareJson04();
  prepareJson05();
  prepareJson06();
  prepareJson07();
  prepareJson08();
  prepareJson09();
  prepareJson10();
}

void prepareJson00()
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  char jsonChar[200];
  
  // Packet 0
  root["d01"] = D3  ? 1 : 0;  // Lámpa műhely
  root["d02"] = D5  ? 1 : 0;  // Lámpa konyha
  root["d03"] = D7  ? 1 : 0;  // Lámpa fürdő
  root.printTo((char*)jsonChar, root.measureLength() + 1);  
  data[0] = String(jsonChar) + '#';
}

void prepareJson01()
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  char jsonChar[200];
    
  // Packet 1
  root["d04"] = D9  ? 1 : 0;
  root["d05"] = D11 ? 1 : 0;  // Lámpa háló
  root["d06"] = D13 ? 1 : 0;  // Lámpa kis-folyosó
  root.printTo((char*)jsonChar, root.measureLength() + 1);  
  data[1] = String(jsonChar) + '#';
}

void prepareJson02()
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  char jsonChar[200];

  // Packet 2
  root["d07"] = D15 ? 1 : 0;  // Lámpa nagy-folyosó
  root["d08"] = D17 ? 1 : 0;  // Lámpa nappali
  root["d09"] = D19 ? 1 : 0;  // Lámpa udvar ház sarkai
  root.printTo((char*)jsonChar, root.measureLength() + 1);  
  data[2] = String(jsonChar) + '#';
}

void prepareJson03()
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  char jsonChar[200];

  // Packet 3
  root["d10"] = D23 ? 1 : 0;  // Lámpa udvar álló lámpák
  root["d11"] = D25 ? 1 : 0;  // Lámpa udvar fészer
  root["d12"] = D27 ? 1 : 0;  // Lámpa padlás
  root.printTo((char*)jsonChar, root.measureLength() + 1);  
  data[3] = String(jsonChar) + '#';
}

void prepareJson04()
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  char jsonChar[200];

  // Packet 4
  root["d13"] = D29 ? 1 : 0;
  root["d14"] = D30 ? 1 : 0;  // Lámpa spájz
  root["d15"] = D31 ? 1 : 0;  // Csengő
  root.printTo((char*)jsonChar, root.measureLength() + 1);  
  data[4] = String(jsonChar) + '#';
}

void prepareJson05()
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  char jsonChar[200];

  // Packet 5
  root["d16"] = D33 ? 1 : 0;
  root["d17"] = D35 ? 1 : 0;
  root["d18"] = D37 ? 1 : 0;
  root.printTo((char*)jsonChar, root.measureLength() + 1);  
  data[5] = String(jsonChar) + '#';
}

void prepareJson06()
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  char jsonChar[200];

  // Packet 6
  root["d19"] = D39 ? 1 : 0;
  root["d20"] = D65 ? 1 : 0;  // Szellőztető
  root["d21"] = D67 ? 1 : 0;
  root.printTo((char*)jsonChar, root.measureLength() + 1);  
  data[6] = String(jsonChar) + '#';
}

void prepareJson07()
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  char jsonChar[200];

  // Packet 7
  root["d22"] = D69 ? 1 : 0;  
  root["n01"] = D32 ? 1 : 0;  // Nyitásérzékelő Fürdő ablak
  root["n02"] = D34 ? 1 : 0;  // Nyitásérzékelő Spájz ablak
  root.printTo((char*)jsonChar, root.measureLength() + 1);  
  data[7] = String(jsonChar) + '#';
}

void prepareJson08()
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  char jsonChar[200];

  // Packet 8
  root["n03"] = D36 ? 1 : 0;  // Nyitásérzékelő Háló ablak
  root["n04"] = D38 ? 1 : 0;  // Nyitásérzékelő Nappali ablak
  root["n05"] = D40 ? 1 : 0;  // Nyitásérzékelő Nagy-folyosó 1
  root.printTo((char*)jsonChar, root.measureLength() + 1);  
  data[8] = String(jsonChar) + '#';
}

void prepareJson09()
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  char jsonChar[200];

  // Packet 9
  root["n06"] = D41 ? 1 : 0;  // Nyitásérzékelő Nagy-folyosó 2
  root["n07"] = D42 ? 1 : 0;  // Nyitásérzékelő Műhely ablak
  root["n08"] = D43 ? 1 : 0;  // Nyitásérzékelő Bejárati ajtó
  root.printTo((char*)jsonChar, root.measureLength() + 1);  
  data[9] = String(jsonChar) + '#';
}

void prepareJson10()
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  char jsonChar[200];

  // Packet 10
  root["n09"] = D44 ? 1 : 0;  // Nyitásérzékelő Műhely ajtó
  root["n10"] = D45 ? 1 : 0;  // Postaláda
  root["n11"] = D46 ? 1 : 0;  // Nyitásérzékelő Nagy-folyosó 3
  root.printTo((char*)jsonChar, root.measureLength() + 1);  
  data[10] = String(jsonChar) + '#';
}
