const int OneButton = 6;
const int TwoButton = 7;
const int ThreeButton = 8;
const int Red = 3;
const int Blue = 4;
const int Green = 5;

bool LightRed = false;
bool LightBlue = false;
bool LightGreen = false;

int LastOneButton = HIGH;//для проверки отпущенна ли кнопка
int LastTwoButton = HIGH;
int LastThreeButton = HIGH;
void setup(){
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(OneButton, INPUT_PULLUP);
  pinMode(TwoButton, INPUT_PULLUP);
  pinMode(ThreeButton, INPUT_PULLUP);
}
void loop() {
  CheckPressed();
  LightRGB(LightRed, Red);
  LightRGB(LightBlue, Blue);
  LightRGB(LightGreen, Green);
  digitalWrite(Red, LOW);
  digitalWrite(Blue, LOW);
  digitalWrite(Green, LOW);
}
void LightRGB(bool& LightColour, int Pin) {
  if (LightColour == true) {
    digitalWrite(Pin, HIGH);
  }
}
void CheckPressed() {
  int button = digitalRead(OneButton);
  if (button == HIGH && LastOneButton == LOW) {//отпущенна ли кнопка
    LightRed = !LightRed;
  }
  LastOneButton = button;
  button = digitalRead(TwoButton);
  if (button == HIGH && LastTwoButton == LOW) {
     LightBlue = !LightBlue;
  }
  LastTwoButton = button;
  button = digitalRead(ThreeButton);
  if (button == HIGH && LastThreeButton == LOW) {
    LightGreen = !LightGreen;
  }
  LastThreeButton = button;
}