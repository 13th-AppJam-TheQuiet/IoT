#include <SoftwareSerial.h>
int curdb;
int redPin = 4;
int greenPin = 5;
int bluePin = 6;
int blueTx=2;  
int blueRx=3;
int aval=0;
int cnt=1;
int tot = 0;
bool fc = false;
SoftwareSerial mySerial(blueTx, blueRx);
void setup() 
{
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
}
void loop()
{
  int val;
  if (mySerial.available()) {
    Serial.write(mySerial.read());
    mySerial.println("place");
    fc = true;
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
  if(fc){
  val = analogRead(0)*3;
  mySerial.println(val);
  Serial.println(val);
  if(val<=19){
    setColor(100,50,255);
  }
  else if(val>19&&val<=39){
    setColor(100,150,150);
  }
  else if(val>39&&val<=59)
  {
    setColor(200,75,20);
  }
  else if (val>59&&val<=79)
  {
    setColor(150,75,80);
  }
  else{
    setColor(255,30,30);
  }
    delay(5000);
  }
}
void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue); 
}

