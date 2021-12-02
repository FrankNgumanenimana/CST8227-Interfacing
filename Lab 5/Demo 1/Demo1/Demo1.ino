byte SER = 14; //databyte 
byte LATCH = 15; //RCLKbyte 
byte CLOCK = 16;  //SRCLK
byte value = 255;

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
  for(byte i = 0; i < 8; i++) {   
  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLOCK, MSBFIRST, value & (1 << i));  //shiftOut(dataPin, clockPin, bitOrder, value)
  digitalWrite(LATCH, HIGH);
  delay(500);

  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLOCK, MSBFIRST, 0);
  digitalWrite(LATCH, HIGH);
  delay(500);
    }
}
