byte SER = 14; //data
byte LATCH = 15; //RCLK
byte CLOCK = 16; //SRCLK
byte bitArray1[10] = {B00000011,B10011111,B00100101,B00011001, B10011001,B01001001,B11000001,B00011111,B00000001, B00011001};

//B00000011,B10011111,B00100101,B00011001, B10011001,B01001001,B11000001,B00011111,B00000001, B00011001
void setup() {

pinMode(SER, OUTPUT);
pinMode(CLOCK, OUTPUT);
pinMode(LATCH, OUTPUT);

digitalWrite(SER, LOW);
digitalWrite(CLOCK, LOW);
digitalWrite(LATCH, LOW);
delay(200);
}
void loop() {
  
  //set the latch low
  
 //*************************DEMO 3*************************
 
  for(int j = 0; j < 10; j++) {
    for(int i = 0; i < 10; i++) {  
      digitalWrite(LATCH, LOW);
      shiftOut(SER, CLOCK, LSBFIRST, bitArray1[i]);//B00000001
      shiftOut(SER, CLOCK, LSBFIRST,bitArray1[j]);  //shiftOut(dataPin, clockPin, bitOrder, value)
      digitalWrite(LATCH, HIGH);
      delay(100);
    } 
  }
}
