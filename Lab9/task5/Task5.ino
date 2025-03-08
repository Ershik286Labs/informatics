const int button[3] = {6, 7, 8};
const int Led[3] = {3, 4, 5};
bool FlagLight[3] = {false, false, false};
int LastButton[3] = {HIGH, HIGH, HIGH};
int i = 0;

void setup(){
  for (int j = 0; j < 3; j++) {
    pinMode(Led[j], OUTPUT);
    analogWrite(Led[j], 255); // Изначально выключаем (HIGH для анодного)
    pinMode(button[j], INPUT_PULLUP);
  }
}

void loop() {
  i = i % 3;
  LightRGB(FlagLight[i], Led[i]);
  Press(button[i], FlagLight[i], LastButton[i]);
  i++;
}

void LightRGB(bool LightColour, int Pin) {
  if (LightColour == true) { analogWrite(Pin, 0); }
  else { analogWrite(Pin, 255); }
}

void Press(int button, bool& Light, int& LastButton) {
  int check = digitalRead(button);
  if (check == LOW && LastButton == HIGH) { Light = !Light; }
  LastButton = check;
}