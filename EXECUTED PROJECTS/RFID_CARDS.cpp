#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9        
#define SS_PIN          10   

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
	Serial.begin(9600);		
	while (!Serial);		
	SPI.begin();		
	mfrc522.PCD_Init();	
	delay(5);			
	mfrc522.PCD_DumpVersionToSerial();	
	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {
	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}
	// Select one of the cards
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

	// Dump debug info about the card; PICC_HaltA() is automatically called
	mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
