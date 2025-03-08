#define BusPin A0
#define ButtonDo 2
#define ButtonRe 3
#define ButtonMi 4
#define ButtonFa 5
#define ButtonSol 6
int Button[5] = {2, 3, 4, 5, 6};
int LastButton[5] = { HIGH, HIGH, HIGH, HIGH, HIGH };
int analogValue = 0;
int i = 2;
void setup() {
  pinMode(BusPin, OUTPUT);
  for (int i = 2; i < 7; i++) pinMode(i, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  i = (i + 1) % 5;
  CheckButton(i);
}
void CheckButton(int i){
  int value = digitalRead(Button[i]);
  if (value == HIGH && LastButton[i] == LOW) {
    switch(Button[i]) {
      case ButtonDo: tone(BusPin, 523, 300); break;
      case ButtonRe: tone(BusPin, 587, 300); break;
      case ButtonMi: tone(BusPin, 659, 300); break;
      case ButtonFa: tone(BusPin, 698, 300); break;
      case ButtonSol: tone(BusPin, 784, 300); break;
    }
  }
  LastButton[i] = value;
}
