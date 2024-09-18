int brightness = 0;

// using PWM analogue pins ~

void()
{
  pinMode(9, OUTPUT);
}

vooid loop()
{
  for (brightness = 0 , brightness <= 255, brightness +=5)
    {
      analogWrite(9, brightness);
      delay(20); //wait 20 milliseconds
    }
  for (brightness = 255, brightness > 0, brightness -= 5)
    {
      analogWrite(9, brightness);
      delay(20);
    }
}
