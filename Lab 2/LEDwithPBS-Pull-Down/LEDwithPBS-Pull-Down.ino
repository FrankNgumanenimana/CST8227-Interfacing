/*
 * Hold: ON / Release: OFF (No Interrupt)
 * 
 * Discrete LED controlled by push button switch (PBS)
 * in pull-down configuration.
 * 
 * @author Gerald.Hurdle@AlgonquinCollege.com
 */

int pbIn = 10;
int ledOut = 20; //13;
int v=0;// The output LED pin
boolean state = LOW;    // The input state

void setup() {
  // put your setup code here, to run once:
  // Set up the digital Pin 9 to an Input and Pin 20 to an Output
  Serial.begin(38400);
  pinMode(pbIn, INPUT); 
  pinMode(ledOut, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(pbIn);  //Read the state of the8888888888888888888 button
  Serial.println(state);
  digitalWrite(ledOut, state);  //write the state to LED
}
