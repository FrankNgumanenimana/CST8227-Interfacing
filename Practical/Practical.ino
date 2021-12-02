
#include <Bounce2.h>// Include the Bounce2 library 
// INSTANTIATE A Bounce OBJECT
Bounce b = Bounce();
byte SER = 14; //data
byte LATCH = 15; //RCLK
byte CLOCK = 16; //SRCLK
byte PBS = 9;//PBS
int buttonLoop = 0,checkRandom1,checkRandom2;
int randomGeneratorRounds = 1;//A counter to keep up with the randomGeneratorber of rounds but has only a limit of 2
int digits [10] = {B11000000, B11111001, B10100100, B10110000, B10011001, B10010010, B10000010, B11111000, B10000000, B10011000};
int stateCheck;//Check the state

void setup() {
  Serial.begin(38400);
  //INPUT HAS AN INTERNAL PULL-UP
  b.attach(PBS, INPUT_PULLUP);
  // DEBOUNCE INTERVAL IN MILLISECONDS
  b.interval(5);
  pinMode(SER, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(PBS, INPUT_PULLUP);
  digitalWrite(SER, LOW);
  digitalWrite(CLOCK, LOW);
  digitalWrite(LATCH, LOW);
  delay(1000);
}

void loop() {
  // Update the Bounce instance (YOU MUST DO THIS EVERY LOOP)
  b.update();
  //The generator for random numbers
  int randomGenerator = random(0, 10);
  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLOCK, MSBFIRST, digits[randomGenerator]); //Set on each bit one at a time
  digitalWrite(LATCH, HIGH);
  delay(500);
  
  //fell() and rose() return 1 when the pin went from HIGH to LOW (fell) or went from LOW to HIGH (rose) since the last update
  if ( b.rose()) {
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLOCK, MSBFIRST, digits[randomGenerator]);
    digitalWrite(LATCH, HIGH);
    buttonLoop++;

    //If statement to check the counter of pressed button
    if (buttonLoop == 1) {
      checkRandom1 = randomGenerator;
      Serial.println("");
      Serial.print("Round ");
      Serial.println(randomGeneratorRounds);
      Serial.print("");
      Serial.print("PBS press #1 => ");
      Serial.print(checkRandom1);
      
    }
    else {
      checkRandom2 = randomGenerator;
      Serial.println("");
      Serial.print("PBS press #2 => ");
      Serial.print(checkRandom2);
      Serial.println("");

      //Implementing the match after comparing if both vaues ae equal or not
      if (checkRandom1 == checkRandom2) {
        Serial.print("==> **MATCH** ***CONGRATULATIONS!!***");
        //Accessing the decimal so that it blinks for not matched 
        for (int n = 0; n < 7; n++) {
          digitalWrite(LATCH, LOW);
          shiftOut(SER, CLOCK, MSBFIRST, digits[checkRandom1]); 
          digitalWrite(LATCH, HIGH);
          delay(200);
          digitalWrite(LATCH, LOW);
          shiftOut(SER, CLOCK, MSBFIRST, B11111111);
          digitalWrite(LATCH, HIGH);
          delay(250);
        }
      }
      else {
        Serial.print("==> NO Match... Sorry...");
        Serial.println("");
        delay(500);
        digitalWrite(LATCH, LOW);
        for (int n = 0; n < 3; n++) {
          //Accessing the decimal so that it blinks for not matched 
          digitalWrite(LATCH, LOW);
          shiftOut(SER, CLOCK, MSBFIRST, B01111111);
          digitalWrite(LATCH, HIGH);
          delay(200);
          digitalWrite(LATCH, LOW);
          shiftOut(SER, CLOCK, MSBFIRST, B11111111); 
          digitalWrite(LATCH, HIGH);
          delay(200);
        }
      }
      //Resetting the buttonLoop which has maximum 2 to 0 
      randomGeneratorRounds++;
      buttonLoop = 0;
    }
    delay(2000);//Delay in millisenconds
  }




}//loop()
