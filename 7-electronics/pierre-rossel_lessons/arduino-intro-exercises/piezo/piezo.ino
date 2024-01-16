#define PIEZO 9
float snd = 500;

void setup() {
  pinMode(PIEZO, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int value = analogRead(A1);

  snd = map(value,0,1023,5,0.001);
  
  Serial.print(value);
  Serial.print("\t");
  Serial.println(snd);


  digitalWrite(PIEZO, HIGH);  //5V is sent to the device
  delay(snd);
  digitalWrite(PIEZO, LOW);
  delay(snd);

}
