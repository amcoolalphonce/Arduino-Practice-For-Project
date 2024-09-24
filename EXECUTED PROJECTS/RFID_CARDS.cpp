#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9        
#define SS_PIN          10   

MFRC522 mfrc522(SS_PIN, RST_PIN);
