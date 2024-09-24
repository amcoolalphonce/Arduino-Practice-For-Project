#include <SPI.h>
#include <MFRC22.h>
#include <WIRE.h>
#include <LiquidCrytsal_i\I2C.h>


// I used the I2C LCD
LiquidCrystal_I2C lcd(0x27, 16, 2;  

#define RST_PIN   9
#define SS_PIN   10

MFRC22 mfrc22(SS_PIN, RST_PIN);
