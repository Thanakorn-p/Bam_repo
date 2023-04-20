// define the pin numbers and blink settings
int speakerPin = D6; // the pin number for the speaker output
int ledPin = D7; // the pin number for the LED output
int blinkDuration = 1000; // the duration of each LED blink, in milliseconds
int blinkCount = 2; // the number of times to blink the LED

void setup() {
  // set the pin modes for the speaker and LED outputs
  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // define the message to output in Morse code
  String message = "Hello"; // replace with your message
  outputMorseCode(message, speakerPin); // output the message in Morse code using the speaker
  
  // blink the LED
  for (int i = 0; i < blinkCount; i++) {
    digitalWrite(ledPin, HIGH); // turn the LED on
    delay(blinkDuration); // wait for the blink duration
    digitalWrite(ledPin, LOW); // turn the LED off
    delay(blinkDuration); // wait for the blink duration
  }
  
  delay(5000); // wait for 5 seconds before repeating
}

void outputMorseCode(String message, int pin) {
  // define the lengths of the different Morse code elements
  const int dotLength = 250; // the duration of a dot, in milliseconds
  const int dashLength = dotLength * 3; // the duration of a dash, in milliseconds
  const int letterGap = dotLength * 3; // the duration of the gap between letters, in milliseconds
  const int wordGap = dotLength * 7; // the duration of the gap between words, in milliseconds
  
  // define the Morse code for each letter of the alphabet
  const char* morseCodes[] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--.." // Z
  };

  // output the Morse code for each character in the message
  for (int i = 0; i < message.length(); i++) { // begins a for loop that iterates through each character in the message string.
    char uppercase = toupper(message.charAt(i)); // converts the current character to uppercase using the toupper() function, and assigns it to the uppercase variable.
    int index = uppercase - 'A'; // calculates the index of the current character in the morseCodes array by subtracting the ASCII value of 'A' from the ASCII value of the current character.
    if (index < 0 || index >= 26) { // checks if the current character is not one of the 26 letters of the English alphabet. If so, the program skips to the next character using the continue statement.
      // character is not supported, skip it
      continue;
    }
    const char* morseCode = morseCodes[index]; //assigns the Morse code for the current character, which is stored in the morseCodes array, to the morseCode variable.
    for (int j = 0; j < strlen(morseCode); j++) { //begins another for loop that iterates through each dot or dash in the Morse code for the current character.
      if (morseCode[j] == '.') { //plays a tone of the appropriate frequency and duration for each dot or dash in the Morse code, using the tone() function.
        tone(pin, 440, dotLength);
      } else if (morseCode[j] == '-') {
        tone(pin, 440, dashLength);
      }
      delay(dotLength);//pauses for the duration of a dot in the Morse code.
    }
    delay(letterGap); //pauses for the duration of the gap between letters in the Morse code.
  }
  
  // pause for the word gap
  delay(wordGap); // pauses for the duration of the gap between words in the Morse code, which is longer than the letter gap. This delay is executed after the for loop that iterates through each character in the message.
}
// Hello sawasdeeja tatermahen koh kwan nii yak ja bok wa kob khun ti kao ma ann naaaa D jaaaaa jing jing pen kae comment mai tong sai jai *_*
