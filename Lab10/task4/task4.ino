#define FIRST_LEFT_PIN 4
#define FIRST_RIGHT_PIN 11
#define BAR_COUNT 14
#define MAX_SCORE 28
#define Red A5
#define Blue A4
#define Green 0

//A0 - 14, A3 - 17
volatile int score = 0;

int scorePin = 4;
int ledOne = 4;
bool ButtonLast[2] = {false, false};
int massiveLeftPin[] = {-24, -20, -16, -12, -8, -4, 0};
int massiveRightPin[] = {0, 4, 8, 12, 16, 20, 24};
void setup()
{
  //Serial.begin(9600);
  for (int i = 0; i < BAR_COUNT; ++i){
    pinMode(i + FIRST_LEFT_PIN, OUTPUT); }
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Green, OUTPUT);
  attachInterrupt(INT0, pushP1, FALLING);
  attachInterrupt(INT1, pushP2, FALLING);
}
void pushP1() { ++score; }
void pushP2() { --score; }

void loop(){
  digitalWrite(Green, HIGH);
  delay(1000);
  digitalWrite(Green, LOW);
  while (abs(score) < MAX_SCORE) {
    for (int i = 0; i < 7; ++i) {
    	if (massiveLeftPin[i] >= score)
          digitalWrite(i + FIRST_LEFT_PIN, HIGH);
        else digitalWrite(i + FIRST_LEFT_PIN, LOW);
    }
    for (int i = 0; i < 7; i++) {
        if (massiveRightPin[i] <= score)
          digitalWrite(i + FIRST_RIGHT_PIN, HIGH);
        else digitalWrite(i + FIRST_RIGHT_PIN, LOW);
    }
  }
  if (score < 0) digitalWrite(Red, HIGH);
  else digitalWrite(Blue, HIGH);
  while (true) {}
}
