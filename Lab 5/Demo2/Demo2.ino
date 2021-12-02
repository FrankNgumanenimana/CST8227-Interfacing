 //**********************DEMO 2********************************

byte SER = 14;//databyte 
byte LATCH = 15;//RCLKbyte 
byte CLOCK = 16;//SRCLK
byte value = 65535;
void setup() {
  pinMode(SER, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  digitalWrite(SER, LOW);
  digitalWrite(CLOCK, LOW);
  digitalWrite(LATCH, LOW);
  delay(1000);
  }
void loop() {
  
  //set the latch low
 int bitArray[] = {1, 3, 7, 15, 31, 63, 127, 255};
 
  for(byte i = 0; i < 8; i++) 
    {
       
  //first bit: ON
  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLOCK, MSBFIRST, 0);
  digitalWrite(LATCH, HIGH);
  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLOCK, MSBFIRST,bitArray[i]);  //shiftOut(dataPin, clockPin, bitOrder, value)
  digitalWrite(LATCH, HIGH);
  delay(250);
    } 
   for(byte i = 0; i < 8; i++) 
    {
  //first bit: OFF
  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLOCK, MSBFIRST,bitArray[i]);
  digitalWrite(LATCH, HIGH);
  digitalWrite(LATCH, LOW); 
  shiftOut(SER, CLOCK, MSBFIRST,255); 
  digitalWrite(LATCH, HIGH);
  delay(250);
     
    }
    for(int i = 7; i >=0 ; --i) 
    {
  //first bit: OFF
  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLOCK, MSBFIRST,bitArray[i]); 
  digitalWrite(LATCH, HIGH);
  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLOCK, MSBFIRST,255); 
  digitalWrite(LATCH, HIGH);
  delay(250);
     
    }

    for(int i = 7 ; i >= 0 ; --i) 
    {
  //first bit: OFF
  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLOCK, MSBFIRST,B00000000); 
  digitalWrite(LATCH, HIGH);
  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLOCK, MSBFIRST,bitArray[i]); 
  digitalWrite(LATCH, HIGH);
  delay(250);
     
    }
  
  }
