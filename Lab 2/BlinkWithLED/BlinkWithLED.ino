byte SER = 14; //data
byte LATCH = 15; //RCLK
byte CLOCK = 16; //SRCLK
byte PBS = 9;//PBS
//boolean buttonState = LOW;
int numbers [10] = {B11000000, B11111001, B10100100,B10110000,B10011001,B10010010,B10000010,B11111000,B10000000, B10011000};
int lastState = HIGH; 
int currentState,pbsCount=0,rnd=1;   
byte count = 0;
int choice1 = 0;
int choice2 = 0;
void setup() {
  Serial.begin(38400);
  pinMode(SER, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(PBS, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  digitalWrite(SER, LOW);
  digitalWrite(CLOCK, LOW);
  digitalWrite(LATCH, LOW);
  Serial.print("Round #1 \n");
  delay(1000);
}
   
void loop() {  

    int num = random(0,10);
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLOCK, MSBFIRST, numbers[num]); //Set on each bit one at a time
    digitalWrite(LATCH, HIGH);
    delay(500);
    
    currentState = digitalRead(PBS);
  
    
    if(lastState == HIGH && currentState == LOW){
      digitalWrite(LATCH, LOW);
      shiftOut(SER, CLOCK, MSBFIRST, numbers[num]); //Set on each bit one at a time
      digitalWrite(LATCH, HIGH);
      
      pbsCount++;
      
       if (pbsCount==1){
      Serial.print("Round #");
      Serial.println(rnd);
      choice1 = num;
      Serial.print("First num is ");
      Serial.println(choice1);
      }
      else {
        
      choice2 = num;
      Serial.print("second num is ");
      Serial.println(choice2); 
      if(choice1==choice2){
        Serial.println("MATCH");
      }
      else{
        Serial.println("NO MATCH");
      }
      rnd++;
      pbsCount=0;

      
      }
      
      delay(2000);
    }
    

}//loop()
