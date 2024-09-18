const int ledPin2 = 2;  // LED connected to pin 2 of the arduino

void setup()
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);  // set LED to off
}

void loop() // this function lights on and off after 4 seconds
{
  digitalWrite(ledPin, HIGH);
  delay(4000); // delay 4 seconds
  digitalWrite(ledPin, LOW);
  delay(4000);
}
