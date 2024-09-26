#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}

byte rowPins[ROWS] = {2, 3, 4, 5}; // Row pins
byte colPins[COLS] = {6, 7, 8, 9}; // Column pins

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int ledPin = 10;

void setup() {
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  char key = keypad.getKey(); 

  if (key) { 
    Serial.println(key);
    blinkLED();
  }
}

void blinkLED() {
  digitalWrite(ledPin, HIGH); 
  delay(200);
  digitalWrite(ledPin, LOW); 
  delay(200); 
}
