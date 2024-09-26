
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

// Create the Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int ledPin = 10;
const int buzzerPin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  char key = keypad.getKey(); 

  if (key) {
    Serial.println(key);
    blinkLED(); 
    playBuzzerTone(); 
  }
}

void blinkLED() {
  digitalWrite(ledPin, HIGH); 
  delay(500); 
  digitalWrite(ledPin, LOW); 
  delay(500); 
}

void playBuzzerTone() {
  tone(buzzerPin, 1000);
  delay(200);
  noTone(buzzerPin);
}
