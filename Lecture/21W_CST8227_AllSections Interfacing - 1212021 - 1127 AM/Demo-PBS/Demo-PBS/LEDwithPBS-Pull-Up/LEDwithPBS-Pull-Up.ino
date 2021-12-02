/*
 * Hold: OFF / Release: ON (No Interrupt)
 * 
 * Discrete LED controlled by push button switch (PBS)
 * in pull-up configuration.
 * 
 * @author Gerald.Hurdle@AlgonquinCollege.com
 */

int pbIn = 10;
int ledOut = 20; //13;    // The output LED pin
boolean state = LOW;    // The input state

void setup() {
  // put your setup code here, to run once:
  // Set up the digital Pin 10 to an Input and Pin 20 to an Output
  Serial.begin(38400);
  pinMode(pbIn, INPUT);
  pinMode(ledOut, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(pbIn);  //Read the state of the button
  Serial.println(state);
  digitalWrite(ledOut, state);  //write the state to LED
}
