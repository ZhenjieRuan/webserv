//display pins
int segA = 5;
int segB = 13;
int segC = 10;
 
int segD = 8;
int segE = 7;
int segF = 4;
int segG = 11;
int segPt = 9;
 
int d1 = 6;
 
int d2 = 3;
int d3 = 2;
int d4 = 12;
 
int delayTime = 900;
 
int counter = 0;
 
void setup() {
// put your setup code here, to run once:
//start serial communications
Serial.begin(9600);
 
//set up outputs
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(3, OUTPUT);
pinMode(2, OUTPUT);
pinMode(13, OUTPUT);
delay(1000);
}

void allLow() {
 
digitalWrite( 13, LOW); // A
digitalWrite( 2, LOW); // B
digitalWrite( 3, LOW); // C
digitalWrite(4, LOW); // D
digitalWrite(5, LOW); // E
digitalWrite( 6, LOW); // F
digitalWrite( 7, LOW); // G
digitalWrite(8, LOW); //point
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
 
}
void allHigh() {
 
digitalWrite( 13, HIGH); // A
digitalWrite( 2, HIGH); // B
digitalWrite( 3, HIGH); // C
digitalWrite(4, HIGH); // D
digitalWrite(5, HIGH); // E
digitalWrite( 6, HIGH); // F
digitalWrite( 7, HIGH); // G
digitalWrite(8, HIGH); //point
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
 
}
 
void one()
{
digitalWrite(segA, LOW);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, LOW);
digitalWrite(segE, LOW);
digitalWrite(segF, LOW);
digitalWrite(segG, LOW);
digitalWrite(segPt, LOW);
 
}
void two()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, LOW);
digitalWrite(segD, HIGH);
digitalWrite(segE, HIGH);
digitalWrite(segF, LOW);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);
 
}
void three()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, LOW);
digitalWrite(segF, LOW);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);
 
}
void four()
{
digitalWrite(segA, LOW);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, LOW);
digitalWrite(segE, LOW);
digitalWrite(segF, HIGH);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);
 
}
void five()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, LOW);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, LOW);
digitalWrite(segF, HIGH);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);
 
}
void six()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, LOW);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, HIGH);
digitalWrite(segF, HIGH);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);
 
}
void seven()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, LOW);
digitalWrite(segE, LOW);
digitalWrite(segF, LOW);
digitalWrite(segG, LOW);
digitalWrite(segPt, LOW);
 
}
void eight()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, HIGH);
digitalWrite(segF, HIGH);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);
 
}
void nine()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, LOW);
digitalWrite(segF, HIGH);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);
 
}
void zero()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, HIGH);
digitalWrite(segF, HIGH);
digitalWrite(segG, LOW);
digitalWrite(segPt, LOW);
 
}

void sendDigit(int x)
{
  switch(x)
  {
    case 1:
      one();
      break;
    case 2:
      two();
      break;
    case 3:
      three();
      break;
    case 4:
      four();
      break;
    case 5:
      five();
      break;
    case 6:
      six();
      break;
    case 7:
      seven();
      break;
    case 8:
      eight();
      break;
    case 9:
      nine();
      break;
    default:
      zero();
      break;
  }
}

void selectDigit(int d)
{
  switch (d)
  {
    case 1:
      digitalWrite(d1, LOW);
      break;
    case 2:
      digitalWrite(d2, LOW);
      break;
    case 3:
      digitalWrite(d3, LOW);
      break;
    default:
      digitalWrite(d4, LOW);
      break;
  }
}

void displayDigit(int d)
{
  switch (d)
  {
    case 1:
      digitalWrite(d1, HIGH);
      break;
    case 2:
      digitalWrite(d2, HIGH);
      break;
    case 3:
      digitalWrite(d3, HIGH);
      break;
    default:
      digitalWrite(d4, HIGH);
      break;
  }
}

int input;
int buf[5];

/*
void displayAll()
{
  int x=1;
  for(x;x<=j;x++) {
    selectDigit(x);
    Serial.println(buf[x]);
    sendDigit(buf[x] - 48);
    delayMicroseconds(delayTime);
    displayDigit(x);
  }
}
*/


void loop() {
  if(Serial.available()>0) {
    input = Serial.read();
  }
  
  Serial.println(input);
  
  if (input == '0'){
    selectDigit(1);
    sendDigit('2'-48);
    delayMicroseconds(delayTime);
    digitalWrite(d1, HIGH);
    selectDigit(2);
    sendDigit(0);
    delayMicroseconds(delayTime);
    digitalWrite(d2, HIGH);
    selectDigit(3);
    sendDigit(0);
    delayMicroseconds(delayTime);
    digitalWrite(d3, HIGH);
  }else if (input == '4'){
    selectDigit(1);
    sendDigit(4);
    delayMicroseconds(delayTime);
    digitalWrite(d1, HIGH);
    selectDigit(2);
    sendDigit(0);
    delayMicroseconds(delayTime);
    digitalWrite(d2, HIGH);
    selectDigit(3);
    sendDigit(4);
    delayMicroseconds(delayTime);
    digitalWrite(d3, HIGH);
  }else if (input == '1'){
    selectDigit(1);
    sendDigit(5);
    delayMicroseconds(delayTime);
    digitalWrite(d1, HIGH);
    selectDigit(2);
    sendDigit(0);
    delayMicroseconds(delayTime);
    digitalWrite(d2, HIGH);
    selectDigit(3);
    sendDigit(1);
    delayMicroseconds(delayTime);
    digitalWrite(d3, HIGH);
  }
  

}

