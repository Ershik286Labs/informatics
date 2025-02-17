#define CONTROL_PIN 5
int brightness = 255;

void setup() {
  pinMode(CONTROL_PIN, OUTPUT); //пин с биполярным транзистором – выход
}
void loop() {
  brightness = (brightness + 1) % (256 * (2 / 3)); //увеличиваем значение яркости на
  analogWrite(CONTROL_PIN, brightness); //подаём Значение на пин базы
  delay(10); // ждём 10 мс
}