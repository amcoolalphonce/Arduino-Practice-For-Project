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


void loop(){
    if (!mfrc522.PICC_IsNewCardPresent()) { // reset loop if no new card is there
    delay(10);
    return;

    if (!mfrc522.PICC_ReadCardSerial()) { // select one card
    delay(10);
    return;
  }
      //Check for matches between known UIDs and selected cards 
  bool matchFound = false;
  for (int i = 0; i < sizeof(knownUIDs) / sizeof(knownUIDs[0]); i++) {
    if (isSameUID(knownUIDs[i], mfrc522.uid.uidByte)) {
      Serial.print("Card UID: ");
      printUID(mfrc522.uid.uidByte, mfrc522.uid.size);
      Serial.print(" -> Name: ");
      Serial.println(names[i]);

      lcd.clear();                  
      lcd.setCursor(0, 0);          
      lcd.print("Name:");
      lcd.setCursor(0, 1);         
      lcd.print(names[i]);
      
      matchFound = true;
      break;
    }   
}
 if (!matchFound) {
    Serial.print("Unknown card UID: ");
    printUID(mfrc522.uid.uidByte, mfrc522.uid.size);
    
    // Display "Unknown" on the LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Unknown UID");
  }

  mfrc522.PICC_HaltA();
}


//check if two UIDs are the same
bool isSameUID(byte uid1[], byte uid2[]) {
  for (byte i = 0; i < 4; i++) {
    if (uid1[i] != uid2[i]) {
      return false;
    }
  }
  return true;
}

//print the UID
void printUID(byte *uid, byte length) {
  for (byte i = 0; i < length; i++) {
    Serial.print(uid[i] < 0x10 ? " 0" : " ");
    Serial.print(uid[i], HEX);
  }
  Serial.println();
}

// THE FEATURE FOR DISPLAYING THE NAMES IS NOT YET WORKING WELL,workinng on it
