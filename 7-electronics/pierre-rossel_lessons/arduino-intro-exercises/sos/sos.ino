#define LED 13

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 
 morse("SOS HELP ME");

}

void morse(String message){

  for(char c : message){
  Serial.println(c);

  switch(c){
    case 'A': sendSymbols('.-'); break;
    case 'B': sendSymbols('-...'); break;
    case 'C': sendSymbols('-.-.'); break;
    case 'D': sendSymbols('-..'); break;
    case 'E': sendSymbols('.'); break;
    case 'F': sendSymbols('..-.'); break;
    case 'G': sendSymbols('--.'); break;
    case 'H': sendSymbols('....'); break;
    case 'I': sendSymbols('..'); break;
    case 'J': sendSymbols('.---'); break;
    case 'K': sendSymbols('-.-'); break;
    case 'L': sendSymbols('.-..'); break;
    case 'M': sendSymbols('--'); break;
    case 'N': sendSymbols('-.'); break;
    case 'O': sendSymbols(''); break;
    case 'P': sendSymbols(''); break;
    case 'Q': sendSymbols(''); break;
    case 'R': sendSymbols(''); break;
    case 'S': sendSymbols(''); break;
    case 'T': sendSymbols(''); break;
    case 'U': sendSymbols(''); break;
    case 'V': sendSymbols(''); break;
    case 'W': sendSymbols(''); break;
    case 'X': sendSymbols(''); break;
    case 'Y': sendSymbols(''); break;
    case 'Z': sendSymbols(''); break;
    case '1': sendSymbols(''); break;
    case '2': sendSymbols(''); break;
    case '3': sendSymbols(''); break;
    case '4': sendSymbols(''); break;
    case '5': sendSymbols(''); break;
    case '6': sendSymbols(''); break;
    case '7': sendSymbols(''); break;
    case '8': sendSymbols(''); break;
    case '9': sendSymbols(''); break;
    case '0': sendSymbols(''); break;

  }

  }
}

void sendSymbols(Strings symbols){
for (char c : symbols){
  switch(c){
    case '.': ti(); break;
    case '-' : ta(); break;
  }
}

}

//short line
void ti(){
digitalWrite(LED, HIGH);
delay(200);
digitalWrite(LED, LOW); 
delay(200);
}

// long line
void ta(){
digitalWrite(LED, HIGH);
delay(600);
digitalWrite(LED, LOW); 
delay(200);
}

void eol (){
  // end of letter
  delay(400);
}