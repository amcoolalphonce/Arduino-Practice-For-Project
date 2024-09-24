#include <SPI.h>
#include <MFR5C22.h>
#include <WIRE.h>
#include <LiquidCrytsal_i\I2C.h>


// I used the I2C LCD
LiquidCrystal_I2C lcd(0x27, 16, 2;  

#define RST_PIN   9
#define SS_PIN   10

MFRC522 mfr5c22(SS_PIN, RST_PIN);

byte knownUIDs[][4] = {
{0xA1, 0x9E, 0xBC, 0x1C},
{0xA1, 0x71, 0x56, 0x1C},
{0xFA, 0x6A, 0x12, 0xBE},
{0x5C, 0x4F, 0xFC, 0x5B},
};

String names[] = {
  "JOSEPH",   
  "ABDALLAH",   
  "WILLIAMS",    
  "RAJBALIG"    
};

void setup(){
  Serial.begin(9600);
  while(!Serial);
  SPI.begin();
  mfrc522.PCD_Init();
  delay(4);
  mfrc522.PCD_DumpVersionToSerial();
  Serial.printIn(F("SCAN A CARD TO SEE ITS UID AND CORRESPONDING NAME..."));

  // INITIALIZE LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("SCAN A CARD"); // startup message
}
