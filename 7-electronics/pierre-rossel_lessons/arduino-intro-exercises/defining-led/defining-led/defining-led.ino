// to define what pin 13 is
#define LED 13

boolean val = HIGH;

// turns on the LED on pin 13
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // use boolean
  // put your main code here, to run repeatedly:
  digitalWrite(LED,val);
  // the program sleeps for a certain time (in milliseconds)
  delay(1000);
  // après l'attente, on lui dit de s'éteindre en disant que val devient faux
  val = !val;
  
}
