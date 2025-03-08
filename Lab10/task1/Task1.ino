int soundPin = 3;
int Button = 2;
int ledPin[3] = {7, 6, 5};
int dotDelay = 50;
int countWord = 0;//выбранное сообщение
long time;
int rate = 100;

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

unsigned long lastDebounceTime = 0;  // Время последнего корректного нажатия
const unsigned long debounceDelay = 50; // Задержка для подавления дребезга (50 мс)


void setup(){
  pinMode(soundPin, OUTPUT);
  pinMode(Button, INPUT_PULLUP);
  for (int i = 0; i < 3; i++)
    pinMode(ledPin[i], OUTPUT);  
  attachInterrupt(digitalPinToInterrupt(Button), CheckPressed, FALLING); // Исправленный номер прерывания
  Serial.begin(9600);
}

void beep(int note, int duration){
  //Play tone on buzzerPin
  if (countWord == 1) return;
  tone(soundPin, note, duration);

  //Play different LED depending on value of 'counter'
  for (int i = 0; i < 3; i++)
    digitalWrite(ledPin[i], HIGH);

    delay(duration);
  for (int i = 0; i < 3; i++)
    digitalWrite(ledPin[i], LOW);

  //Stop tone on buzzerPin
  noTone(soundPin);

  delay(50);

  //Increment counter
}

void CheckPressed() {
  Serial.println(countWord);
  unsigned long currentTime = millis();
  if ((currentTime - lastDebounceTime) > debounceDelay) {
    noTone(soundPin);
    countWord = (countWord + 1) % 2;
    // Кнопка действительно нажата (а не просто дребезг)
    lastDebounceTime = currentTime;
  }
}

void loop() {
  if (countWord == 0) {
    firstSectionSW();
    secondSectionSW();
  }
  else {
    firstSectionPS();
  }
}

void firstSectionSW()
{
  beep(a, 500);
  beep(a, 500);
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);

  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);
}

void secondSectionSW()
{
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);
  beep(fSH, 250);

  delay(325);

  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);
  beep(cSH, 175);
  beep(cH, 125);
  beep(b, 125);
  beep(cH, 250);

  delay(350);
}

void firstSectionPS()
{
    //BeeepSOV(soundPin, 174, 249.99975, 277.7775);
    BeeepSOV(soundPin, 233, 499.9995, 555.555);
    BeeepSOV(soundPin, 174, 374.999625, 416.66625);
    BeeepSOV(soundPin, 195, 124.999875, 138.88875);
    BeeepSOV(soundPin, 220, 499.9995, 555.555);
    BeeepSOV(soundPin, 146, 249.99975, 277.7775);
    BeeepSOV(soundPin, 146, 249.99975, 277.7775);
    BeeepSOV(soundPin, 195, 499.9995, 555.555);
    BeeepSOV(soundPin, 174, 374.999625, 416.66625);
    BeeepSOV(soundPin, 155, 124.999875, 138.88875);
    BeeepSOV(soundPin, 174, 499.9995, 555.555);
    BeeepSOV(soundPin, 116, 249.99975, 277.7775);
    BeeepSOV(soundPin, 116, 249.99975, 277.7775);
    BeeepSOV(soundPin, 130, 499.9995, 555.555);
    BeeepSOV(soundPin, 130, 374.999625, 416.66625);
    BeeepSOV(soundPin, 146, 124.999875, 138.88875);
    BeeepSOV(soundPin, 155, 499.9995, 555.555);
    BeeepSOV(soundPin, 155, 374.999625, 416.66625);
    BeeepSOV(soundPin, 174, 124.999875, 138.88875);
    BeeepSOV(soundPin, 195, 499.9995, 555.555);
    BeeepSOV(soundPin, 220, 374.999625, 416.66625);
    BeeepSOV(soundPin, 233, 124.999875, 138.88875);
    BeeepSOV(soundPin, 261, 749.99925, 833.3325);
    BeeepSOV(soundPin, 174, 249.99975, 277.7775);
    BeeepSOV(soundPin, 293, 499.9995, 555.555);
    BeeepSOV(soundPin, 261, 374.999625, 416.66625);
    BeeepSOV(soundPin, 233, 124.999875, 138.88875);
    BeeepSOV(soundPin, 261, 499.9995, 555.555);
    BeeepSOV(soundPin, 174, 249.99975, 277.7775);
    BeeepSOV(soundPin, 174, 249.99975, 277.7775);
    BeeepSOV(soundPin, 233, 499.9995, 555.555);
	BeeepSOV(soundPin, 220, 374.999625, 416.66625);
    BeeepSOV(soundPin, 195, 124.999875, 138.88875);
    BeeepSOV(soundPin, 220, 499.9995, 555.555);
    BeeepSOV(soundPin, 146, 374.999625, 416.66625);
    BeeepSOV(soundPin, 146, 124.999875, 138.88875);
    BeeepSOV(soundPin, 195, 499.9995, 555.555);
    BeeepSOV(soundPin, 174, 374.999625, 416.66625);
    BeeepSOV(soundPin, 155, 124.999875, 138.88875);
    BeeepSOV(soundPin, 174, 499.9995, 555.555);
    BeeepSOV(soundPin, 116, 374.999625, 416.66625);
    BeeepSOV(soundPin, 116, 124.999875, 138.88875);
    BeeepSOV(soundPin, 233, 499.9995, 555.555);
    BeeepSOV(soundPin, 220, 374.999625, 416.66625);
    BeeepSOV(soundPin, 195, 124.999875, 138.88875);
    BeeepSOV(soundPin, 174, 999.999, 1111.11);
    BeeepSOV(soundPin, 293, 999.999, 1111.11);
    BeeepSOV(soundPin, 261, 249.99975, 277.7775);
    BeeepSOV(soundPin, 233, 249.99975, 277.7775);
    BeeepSOV(soundPin, 220, 249.99975, 277.7775);
    BeeepSOV(soundPin, 233, 249.99975, 277.7775);
    BeeepSOV(soundPin, 261, 749.99925, 833.3325);
    BeeepSOV(soundPin, 174, 249.99975, 277.7775);
    BeeepSOV(soundPin, 174, 999.999, 1111.11);
    BeeepSOV(soundPin, 233, 999.999, 1111.11);
    BeeepSOV(soundPin, 220, 249.99975, 277.7775);
    BeeepSOV(soundPin, 195, 249.99975, 277.7775);
    BeeepSOV(soundPin, 174, 249.99975, 277.7775);
    BeeepSOV(soundPin, 195, 249.99975, 277.7775);
    BeeepSOV(soundPin, 220, 749.99925, 833.3325);
    BeeepSOV(soundPin, 146, 249.99975, 277.7775);
    BeeepSOV(soundPin, 146, 999.999, 1111.11);
    BeeepSOV(soundPin, 233, 499.9995, 555.555);
    BeeepSOV(soundPin, 195, 374.999625, 416.66625);
    BeeepSOV(soundPin, 220, 124.999875, 138.88875);
    BeeepSOV(soundPin, 233, 499.9995, 555.555);
    BeeepSOV(soundPin, 195, 374.999625, 416.66625);
    BeeepSOV(soundPin, 220, 124.999875, 138.88875);
    BeeepSOV(soundPin, 233, 499.9995, 555.555);
    BeeepSOV(soundPin, 195, 374.999625, 416.66625);
    BeeepSOV(soundPin, 233, 124.999875, 138.88875);
    BeeepSOV(soundPin, 311, 999.999, 1111.11);
    BeeepSOV(soundPin, 311, 999.999, 1111.11);
    BeeepSOV(soundPin, 293, 249.99975, 277.7775);
    BeeepSOV(soundPin, 261, 249.99975, 277.7775);
    BeeepSOV(soundPin, 233, 249.99975, 277.7775);
    BeeepSOV(soundPin, 261, 249.99975, 277.7775);
    BeeepSOV(soundPin, 293, 749.99925, 833.3325);
    BeeepSOV(soundPin, 233, 249.99975, 277.7775);
    BeeepSOV(soundPin, 233, 999.999, 1111.11);
    BeeepSOV(soundPin, 261, 999.999, 1111.11);
    BeeepSOV(soundPin, 233, 249.99975, 277.7775);
    BeeepSOV(soundPin, 220, 249.99975, 277.7775);
    BeeepSOV(soundPin, 195, 249.99975, 277.7775);
    BeeepSOV(soundPin, 220, 249.99975, 277.7775);
    BeeepSOV(soundPin, 233, 749.99925, 833.3325);
    BeeepSOV(soundPin, 195, 249.99975, 277.7775);
    BeeepSOV(soundPin, 195, 999.999, 1111.11);
    BeeepSOV(soundPin, 233, 499.9995, 555.555);
    BeeepSOV(soundPin, 220, 374.999625, 416.66625);
    BeeepSOV(soundPin, 195, 124.999875, 138.88875);
    BeeepSOV(soundPin, 174, 499.9995, 555.555);
    BeeepSOV(soundPin, 116, 374.999625, 416.66625);
    BeeepSOV(soundPin, 116, 124.999875, 138.88875);
    BeeepSOV(soundPin, 174, 999.999, 1111.11);
    BeeepSOV(soundPin, 195, 499.9995, 555.555);
    BeeepSOV(soundPin, 220, 499.9995, 555.555);
    BeeepSOV(soundPin, 233, 1999.998, 2222.22);
}

void BeeepSOV(int soundPin, int herc, float time, float delayTime) {
  if (countWord == 0) return;
  for (int i = 0; i < 3; i++) 
    digitalWrite(ledPin[i], HIGH);
  tone(soundPin, herc, time);
  delay(delayTime);
  for (int i = 0; i < 3; i++) 
    digitalWrite(ledPin[i], LOW);
  delay(100);
}