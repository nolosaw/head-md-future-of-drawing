// pins des leds
#define LEDR 2
#define LEDV 3
#define LEDB 4
#define LEDJ 5

// pins des boutons
#define BUTTONO 8
#define BUTTONR 9
#define BUTTONV 10
#define BUTTONB 11
#define BUTTONJ 12

// bits des leds dans la variable leds
#define BIT_R 0
#define BIT_V 1
#define BIT_B 2
#define BIT_J 3

// Leds allumées 1 bit par led (Voir constantes BIT_* )
int leds = 0;

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


  if (rbtnDown && leds == 0) {
    bitSet(leds, BIT_R);
    acceptSequence();
  }

  if (vbtnDown && leds == 0) {
    bitSet(leds, BIT_V);
    acceptSequence();
  }

  if (bbtnDown && leds == 0) {
    bitSet(leds, BIT_B);
    acceptSequence();
  }

  if (jbtnDown && leds == 0) {
    bitSet(leds, BIT_J);
    acceptSequence();
  }

  // reset btn
  if (obtnDown) {

    // fun reset sequence
    setLeds(0b1111);
    delay(100);
    setLeds(0b0000);
    delay(100);
    setLeds(0b1111);
    delay(100);
    setLeds(0b0000);
    delay(100);

    leds = 0;
  }

  // mets à jour les leds$$
  setLeds(leds);
}

void setLeds(int leds) {
  digitalWrite(LEDR, bitRead(leds, BIT_R));
  digitalWrite(LEDV, bitRead(leds, BIT_V));
  digitalWrite(LEDB, bitRead(leds, BIT_B));
  digitalWrite(LEDJ, bitRead(leds, BIT_J));
}

void acceptSequence() {
    setLeds(0b1000);
    delay(100);
    setLeds(0b0100);
    delay(100);
    setLeds(0b0010);
    delay(100);
    setLeds(0b0001);
    delay(100);

    setLeds(0b0010);
    delay(100);
    setLeds(0b0100);
    delay(100);
    setLeds(0b1000);
    delay(100);
    setLeds(0b0000);
    delay(100);

}