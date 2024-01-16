// turns on the LED on pin 13
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  // the program sleeps for a certain time (in milliseconds)
  delay(random(1000));
  // après l'attente, on lui dit de s'éteindre
  digitalWrite(13, LOW);
  // on lui dit d'attendre dans cet état pendant un temps donné
  delay(100);
  // à la fin de la boucle on recommence
}
