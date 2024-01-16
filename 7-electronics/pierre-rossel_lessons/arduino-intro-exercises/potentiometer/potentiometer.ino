#define LED 13
int lum = 15;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // will get a value between 0 and 1023
  int value = analogRead(A1);

  lum = map(value,0,1023,0,20);
  
  Serial.print(value);
  Serial.print("\t");
  Serial.println(lum);
  
  

  digitalWrite(LED, HIGH);
  delay(lum);
  digitalWrite(LED, LOW);
  delay(20 - lum);
}
