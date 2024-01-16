// Translate text received on the serial line to morse code
// Pierre Rossel and MD1 2023
//
// History
// 2023-11-28 Initial version

#define LED 2

String message;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  morse("SOS");
}

void loop() {

  // Read text from serial port and send it as morse when 
  // we receive a new line
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') { // new line
      morse(message);
      message = "";
    } else {
      message = message + c;
    }
  }
}

// transform a text message to morse and send it to LED pin
void morse(String message) {
  //Serial.print(message);

  for (char c : message) {
    Serial.print(c);

    switch (c) {
      case 'A': sendSymbols(".-"); break;
      case 'B': sendSymbols("-..."); break;
      case 'C': sendSymbols("-.-."); break;
      case 'D': sendSymbols("-.."); break;
      case 'E': sendSymbols("."); break;
      case 'F': sendSymbols("..-."); break;
      case 'G': sendSymbols("--."); break;
      case 'H': sendSymbols("...."); break;
      case 'I': sendSymbols(".."); break;
      case 'J': sendSymbols(".---"); break;
      case 'K': sendSymbols("-.-"); break;
      case 'L': sendSymbols(".-.."); break;
      case 'M': sendSymbols("--"); break;
      case 'N': sendSymbols("-."); break;
      case 'O': sendSymbols("---"); break;
      case 'P': sendSymbols(".--."); break;
      case 'Q': sendSymbols("--.-"); break;
      case 'R': sendSymbols(".-."); break;
      case 'S': sendSymbols("..."); break;
      case 'T': sendSymbols("-"); break;
      case 'U': sendSymbols("..-"); break;
      case 'V': sendSymbols("...-"); break;
      case 'W': sendSymbols(".--"); break;
      case 'X': sendSymbols("-..-"); break;
      case 'Y': sendSymbols("-.--"); break;
      case 'Z': sendSymbols("--.."); break;
      case '0': sendSymbols("-----"); break;
      case '1': sendSymbols(".----"); break;
      case '2': sendSymbols("..---"); break;
      case '3': sendSymbols("...--"); break;
      case '4': sendSymbols("....-"); break;
      case '5': sendSymbols("....."); break;
      case '6': sendSymbols("-...."); break;
      case '7': sendSymbols("--..."); break;
      case '8': sendSymbols("---.."); break;
      case '9': sendSymbols("----."); break;

      case ' ': endOfLetter(); break;
    }

    endOfLetter();
  }

  Serial.println();
}

// Send a string of morse symbols such as -..-
void sendSymbols(String symbols) {
  for (char c : symbols) {
    switch (c) {
      case '.': ti(); break;
      case '-': ta(); break;
    }
  }
}

void ti() {
  // Ti
  Serial.print(".");
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
}

void ta() {
  // Ta
  Serial.print("-");
  digitalWrite(LED, HIGH);
  delay(600);
  digitalWrite(LED, LOW);
  delay(200);
}

// End of letter
void endOfLetter() {
  // End of letter
  Serial.print(" ");
  delay(400);
}
