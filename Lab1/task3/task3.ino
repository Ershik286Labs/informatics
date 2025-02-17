#define ControlPin 5
int brightness = 0;
void setup()
{
  pinMode(ControlPin, OUTPUT);
}

void loop(){
  brightness = (brightness + 1) % 256;
  analogWrite(ControlPin, brightness);
  delay(10);
}