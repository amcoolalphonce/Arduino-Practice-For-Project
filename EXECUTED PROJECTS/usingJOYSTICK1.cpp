// pin numbers
const int VRxPin = A0;  // X-axis o A0
const int VRyPin = A1;  // Y-axis to A1
const int SWPin = 2;    // digital

int xValue = 0;
int yValue = 0;
int buttonState = 0; 

void setup() {
  Serial.begin(9600);
  // button pin as input with a pull-up resistor
  pinMode(SWPin, INPUT_PULLUP);
}
