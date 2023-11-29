#define LEDR 2
#define LEDV 3
#define LEDB 4
#define LEDJ 5

#define BUTTONO 8
#define BUTTONR 9
#define BUTTONV 10
#define BUTTONB 11
#define BUTTONJ 12



void setup() {
  //INITIALISE LES LEDS
  pinMode(LEDR, OUTPUT);
  pinMode(LEDV, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDJ, OUTPUT);

  //INITIALISE LES BOUTONS
  pinMode(BUTTONO, INPUT_PULLUP);  //connect internal resistor to pin
  pinMode(BUTTONR, INPUT_PULLUP);  //connect internal resistor to pin
  pinMode(BUTTONV, INPUT_PULLUP);  //connect internal resistor to pin
  pinMode(BUTTONB, INPUT_PULLUP);  //connect internal resistor to pin
  pinMode(BUTTONJ, INPUT_PULLUP);  //connect internal resistor to pin

  //Turn the leds off when started
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDV, LOW);
  digitalWrite(LEDB, LOW);
  digitalWrite(LEDJ, LOW);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  boolean rbtnDown = !digitalRead(BUTTONR);
  boolean vbtnDown = !digitalRead(BUTTONV);
  boolean bbtnDown = !digitalRead(BUTTONB);
  boolean jbtnDown = !digitalRead(BUTTONJ);
  boolean obtnDown = !digitalRead(BUTTONO);

  //boolean rLedOff = !digitalRead();


  if (rbtnDown) {
    digitalWrite(LEDR, HIGH);
  }

  if (vbtnDown) {
    digitalWrite(LEDV, HIGH);
  }

  if (bbtnDown) {
    digitalWrite(LEDB, HIGH);
  }

  if (jbtnDown) {
    digitalWrite(LEDJ, HIGH);
  }

  if (obtnDown) {
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDV, LOW);
    digitalWrite(LEDB, LOW);
    digitalWrite(LEDJ, LOW);
  }
}
