#define LED 13
#define BUTTON_PIN 8
float lum = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}


void loop() {
  boolean btnDown = !digitalRead(BUTTON_PIN);

  // change brightness when button is pressed
  if (btnDown) {
    lum = lum + 0.1;
    if (lum > 20) {
      lum = lum - 0.1;
    }
  }


  // control the led
  digitalWrite(LED, HIGH);
  delay(lum);
  digitalWrite(LED, LOW);
  delay(20 - lum);
}