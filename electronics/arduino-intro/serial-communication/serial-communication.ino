#define BUTTON_PIN 8
#define LED_PIN 13

void setup() {
  // put your setup code here, to run once:
  //pinMode(BUTTON_PIN, INPUT);  //optionnel parce que par défaut les pins sont des Inputs
  pinMode(LED_PIN, OUTPUT);

  //Turn the led off when started
  digitalWrite(LED_PIN, LOW);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  //connect internal resistor to pin

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Nom du projet pour le retrouver");
}

void loop() {
  // put your main code here, to run repeatedly:

  // on lui demande de lire si la valeur du bouton est HIGH ou LOW (1 ou 0)
  // on le met dans le loop pour qu'il lise constamment l'état du bouton
  boolean buttonValue = digitalRead(BUTTON_PIN);

  // pour voir les données de temps
  int freq = 1;  // Hz
  Serial.print(sin(TWO_PI * freq * millis() / 1000.0));
  // faire une tabulation
  Serial.print("\t");
  // Serial.print("Button is ");
  // donner la valeur du bouton
  Serial.print(buttonValue);
  Serial.println();


  if (!buttonValue) {  //implicite que ça veut dire que c'est vrai
    // do something
    digitalWrite(LED_PIN, HIGH);
  }

  if (buttonValue) {  //implicite que ça veut dire que c'est vrai
    // do something
    digitalWrite(LED_PIN, LOW);
  }

  delay(100);
}
