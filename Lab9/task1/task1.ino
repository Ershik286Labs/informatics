int parityMax = 10;//максимальный пин у четной
int parityMin = 2;//минимальный пин у четной

int NoParityMax = 11;//максимальный пин у нечетной
int NoParityMin = 3;//минимальный пин у нечетной
bool flag = false;//дошло ли до центра

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
  digitalWrite(parityMax, 255);
  digitalWrite(parityMin, 255);
  digitalWrite(NoParityMax, 255);
  digitalWrite(NoParityMin, 255);
  delay(2500);
  digitalWrite(parityMax, LOW);
  digitalWrite(parityMin, LOW);
  digitalWrite(NoParityMax, LOW);
  digitalWrite(NoParityMin, LOW);
  if (parityMax == parityMin) { flag = true; }
  if (parityMax == 10) {flag = false; }
  if (flag == false) {
  	parityMax -= 2;
  	parityMin += 2;
  	NoParityMax -= 2;
  	NoParityMin += 2;	
  }
  else {
  	parityMax += 2;
  	parityMin -= 2;
  	NoParityMax += 2;
  	NoParityMin -= 2;
  }
}