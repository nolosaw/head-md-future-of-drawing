#define LED 13

void setup() {
  pinMode(LED, OUTPUT);
}


void loop() {
  int lum = random(20);  // luminosité entre 0 et 20

  int freq = 1;  // Hz

  digitalWrite(LED, HIGH);
  delay(lum);
  digitalWrite(LED, LOW);
  delay(20 - lum);
}