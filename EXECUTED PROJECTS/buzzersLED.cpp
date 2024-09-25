const int redLED = 7;
const int greenLED = 8;
const int blueLED = 9;

const int buzzer = 6;

int tone1 = 262; // C4
int tone2 = 294; // D4
int tone3 = 330; // E4

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(redLED, HIGH);  
  tone(buzzer, tone1);         
  delay(500);                   
  digitalWrite(redLED, LOW);    
  noTone(buzzer);               
  delay(200);                 

