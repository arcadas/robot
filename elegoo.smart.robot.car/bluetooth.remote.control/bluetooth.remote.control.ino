#include <IRremote.h>
int receiverpin = 12;
int in1=9;
int in2=8;
int in3=7;
int in4=6;
int ENA=10;
int ENB=5;
int ABS=130;
char INBYTE;
unsigned long RED;
#define A 16736925
#define B 16754775
#define X 16712445
#define C 16720605
#define D 16761405

IRrecv irrecv(receiverpin);
decode_results results;

void _mForward()
{
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  // Serial.println("go forward!");
  Serial.println("go back!");
}
void _mBack()
{
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  // Serial.println("go back!");
  Serial.println("go forward!");
}
void _mLeft()
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  // Serial.println("go left!");
  Serial.println("go right!");
}
void _mRight()
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  // Serial.println("go right!");
  Serial.println("go left!");
}
void _mStop()
{
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  Serial.println("STOP!");
}
void _stepStop()
{
  delay(1000);
  _mStop();
}
void _turnStop()
{
  delay(2000);
  _mStop();
}
void setup() {
  // put your setup code here, to run once:
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(receiverpin,INPUT);
  Serial.begin(9600);
  _mStop();
  irrecv.enableIRIn();
}

void loop()
{
  Serial.println("Press W,S,A,D to control robot car:");
  while (!Serial.available());

  INBYTE = Serial.read();        // read next available byte
  
  if( INBYTE == 'w' ) {
      _mBack();
      _stepStop();
  }
  if( INBYTE == 's' ) {
      _mForward();
      _stepStop();
  }
  if( INBYTE == 'a' ) {
      _mRight();
      _stepStop();
  }
  if( INBYTE == 'd' ) {
      _mLeft();
      _stepStop();
  }
  
  delay(500);
}

