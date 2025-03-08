//Первая октава 262-523
#define MinSound 0 
#define MaxSound 6
#define BusPin 2
#define PhotoPin A0
float massiveNote[7] = {261.63, 293.66, 329.63, 349.23, 392, 440, 493.88};
int TempSound = MinSound;
int analogValue = 0;
void setup() {
  pinMode(BusPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogValue = analogRead(PhotoPin);
  Serial.print(analogValue);
  Serial.print("/");
  analogValue = map(analogValue, 6, 679, MinSound, MaxSound);
  
  
  Serial.println(massiveNote[analogValue]);
  tone(BusPin, massiveNote[analogValue]);
}