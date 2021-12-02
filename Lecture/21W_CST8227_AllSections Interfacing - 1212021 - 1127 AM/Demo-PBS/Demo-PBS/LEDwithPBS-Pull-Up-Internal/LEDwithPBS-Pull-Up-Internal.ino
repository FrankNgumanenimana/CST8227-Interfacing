/*
 * Hold: OFF / Release: ON (No Interrupt)
 * 
 * Discrete LED controlled by push button switch (PBS)
 * in *internal* pull-up configuration (no resistor and no Vcc).
 * 
 * @author Gerald.Hurdle@AlgonquinCollege.com
 */

int pbIn = 10;
int ledOut = 20; //13;    // The output LED pin
boolean state = LOW;    // The input state

void setup() {
  // put your setup code here, to run once:
  // Set up the digital Pin 10 to an Input Pullup and Pin 20 to an Output
  Serial.begin(38400);
  pinMode(pbIn, INPUT_PULLUP);  //NOTICE
  pinMode(ledOut, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(pbIn);  //Read the state of the button
  Serial.println(state);
  digitalWrite(ledOut, state);  //write the state to LED
}
