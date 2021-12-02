/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink

  //LedPin 13 is the build in and 20 is the Led
*/

int pushButton = 10;
volatile int counter = 0;

long dutyCycleRandNumber;
int greenLED = 20;//3.0V, ~33ohm or bigger - LEDs turn ON with very little current so the 220 ohm that came with the tri-color LED are fine
int blueLED = 21;//2.3V, ~111ohm
int redLED = 23;//1.6V, ~189ohm


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);

  pinMode(blueLED,  OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED,   OUTPUT);
  pinMode(pushButton, INPUT);
  pinMode(A0, INPUT);//use this open circuited pin for a seed to the random number generator

}

// the loop function runs over and over again forever
void loop() {
int myDelay = 800;
//
   digitalWrite(redLED, HIGH);
   delay(myDelay);
   digitalWrite(redLED, LOW);
//
   digitalWrite(greenLED, true);
   delay(myDelay);
   digitalWrite(greenLED, false);
//
   digitalWrite(blueLED, 1);
   delay(myDelay);
   digitalWrite(blueLED, 0);
}
