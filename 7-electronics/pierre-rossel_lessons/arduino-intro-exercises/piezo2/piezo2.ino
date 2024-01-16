#define PIEZO 9
#define POT A1;
int snd = 3000;

void setup() {
  pinMode(PIEZO, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int value = analogRead(A1);

  snd = map(value, 0, 1023, 1000, 4);

  Serial.println(value);
  Serial.print("\t");
  Serial.println(snd);


  tone(PIEZO, snd, 1000);
  delay(20);
}
