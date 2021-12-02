byte SER = 14; //data
byte LATCH = 15; //RCLK
byte CLOCK = 16; //SRCLK
void setup()
{
  Serial.begin(38400);
  pinMode(A1, INPUT);
  pinMode(SER, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);

  digitalWrite(SER, LOW);
  digitalWrite(CLOCK, LOW);
  digitalWrite(LATCH, LOW);
  delay(200);
}

int code;
float celsius;

void loop()
{
  code = analogRead(23);
  celsius = 25 + (code - 512) / 11.3;
  /*if(celsius <30){
    }*/
  Serial.print("temperature: ");
  Serial.print(celsius);
  Serial.println(" Celsius, ");


  delay(1000);
}
