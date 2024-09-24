#include <SPI.h>
#include <MFRC22.h>
#include <WIRE.h>
#include <LiquidCrytsal_i\I2C.h>


// I used the I2C LCD
LiquidCrystal_I2C lcd(0x27, 16, 2;  

#define RST_PIN   9
#define SS_PIN   10

MFRC22 mfrc22(SS_PIN, RST_PIN);

byte knownUIDs[][4] = {
{0xA1, 0x9E, 0xBC, 0x1C},
{0xA1, 0x71, 0x56, 0x1C},
{0xFA, 0x6A, 0x12, 0xBE},
{0x5C, 0x4F, 0xFC, 0x5B},
};
