#define FIRST_LEFT_PIN 4
#define FIRST_RIGHT_PIN 11
#define BAR_COUNT 14
#define MAX_SCORE 28
#define Red A5
#define Blue A4
#define Green 0

//A0 - 14, A3 - 17
volatile int score = 0;
int number = 0;

int scorePin = 4;
int ledOne = 4;
bool ButtonLast[2] = {false, false};
int massiveLeftPin[] = {0, -4, -8, -12, -16, -20, -24};
int massiveRightPin[] = {0, 4, 8, 12, 16, 20, 24};
void setup()
{
  for (int i = 0; i < BAR_COUNT; ++i){
    pinMode(i + FIRST_LEFT_PIN, OUTPUT); }
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Green, OUTPUT);
  //Serial.begin(9600);
  attachInterrupt(INT0, pushP1, FALLING);
  attachInterrupt(INT1, pushP2, FALLING);
}
bool FlagStart = false;
void pushP1() {
  //Serial.print("+ - ");
  //Serial.print(score);
  //Serial.print("/");
  //Serial.println(number);
  if (number == -1 && score == 0) {
  	FlagStart = true;
  }
  if (FlagStart == true) {
  	FlagStart = false;
    score += 2;
  }
  else score++;
  
  if (score == 4) {
    number++; 
    score = 0;
   }
  //Serial.println(score);
}
void pushP2() {
  if (number == 1 && score == 0) {
  	FlagStart = true;
  }
  if (FlagStart == false) {
  	FlagStart = true;
    score -= 2;
  }
  else score--;
  if (score == -4) {
    number--; 
    score = 0;
  }
  //Serial.println(score);
  //Serial.println(number);
}

void loop(){
  digitalWrite(Green, HIGH);
  delay(1000);
  digitalWrite(Green, LOW);
  while (abs(number) < 7) {
    for (int i = 0; i < 7; i++) {
        if (i <= abs(number) && number <= 0) {
      		digitalWrite(FIRST_LEFT_PIN + i, HIGH);
        }
        else digitalWrite(FIRST_LEFT_PIN + i, LOW);
    }
    for (int i = 0; i < 7; i++) {
        if (i <= number && number >= 0) {
      		digitalWrite(FIRST_RIGHT_PIN + i, HIGH);
        }
        else digitalWrite(FIRST_RIGHT_PIN + i, LOW);
    }
  }
  if (number < 0) digitalWrite(Red, HIGH);
  else digitalWrite(Blue, HIGH);
  while (true) {}
}
