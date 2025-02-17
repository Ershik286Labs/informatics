#define pin 13
const int OneButton = 3;
const int TwoButton = 4;
bool OneButtonClick = false;
bool TwoButtonClick = false;
bool light = false;
int LastOneButton = HIGH;//для проверки отпущенна ли кнопка
int LastTwoButton = HIGH;
void setup(){
  pinMode(pin, OUTPUT);
  pinMode(OneButton, INPUT_PULLUP);
  pinMode(TwoButton, INPUT_PULLUP);
}
void loop() {
  CheckPressed();
  if (light == true) {digitalWrite(pin, HIGH);}
  else {digitalWrite(pin, LOW);}
}
void CheckPressed() {
  int button = digitalRead(OneButton);
  if (button == HIGH && LastOneButton == LOW) {//отпущенна ли кнопка
    if (light == true) {OneButtonClick = true;}
    else {light = true;}
  }
  LastOneButton = button;
  button = digitalRead(TwoButton);
  if (button == HIGH && LastTwoButton == LOW) {
     if (light == true) {TwoButtonClick = true;}
    else {light = true;}
  }
  LastTwoButton = button;
  if (OneButtonClick == true && TwoButtonClick == true) {
  	light = false;
    OneButtonClick = false;
    TwoButtonClick = false;
  }
}