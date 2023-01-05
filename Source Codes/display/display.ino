#include <Wire.h>
#include <MCUFRIEND_kbv.h>
#include <Adafruit_GFX.h>

String incomingData;
String rows[20];
int actualRow = 0;

#define LCD_RESET A6  // Can alternately just connect to Arduino's reset pin
#define LCD_CS A3     // Chip Select goes to Analog 3
#define LCD_CD A2     // Command/Data goes to Analog 2
#define LCD_WR A1     // LCD Write goes to Analog 1
#define LCD_RD A0     // LCD Read goes to Analog 0

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

MCUFRIEND_kbv tft;

void setup(void)
{
  Wire.begin(0xAA);
  Wire.onReceive(receiveEvent);
  
  tft.reset();
  tft.begin(0x9341);
  tft.fillScreen(BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(GREEN);
  tft.setTextSize(2);
  
  rows[actualRow] = "I2C Display ready!";
  tft.println(rows[actualRow]);
}

void receiveEvent(int numBytes)
{
  incomingData = "";
  
  while (Wire.available())
  {
    char c = Wire.read();
    incomingData += c;
  }

  incomingData = incomingData.substring(0, 19);

  if (actualRow < 19)
  {
    actualRow++; 
    rows[actualRow] = incomingData;    
    displayArray();
  }
  else
  {
    for(int i = 1; i < 20; i++)
    {
      rows[i - 1] = rows[i];
    }
    rows[19] = incomingData;
    displayArray();
  }
}

void displayArray()
{
  tft.fillScreen(BLACK);
  tft.setCursor(0, 0);

  for(int i = 0; i < 20; i++)
  {
    tft.println(rows[i]);
  }
}

void loop(void)
{
  delay(100);
}
