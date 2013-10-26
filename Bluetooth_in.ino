#include <SoftwareSerial.h>
SoftwareSerial bt(3,4);

int redPin = A0;
int greenPin = A1;
int bluePin = A2;

//char flag = '0';

void setup() {
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  bt.begin(115200);
}

void loop() {
  if(bt.available())
    {
    char val = bt.read();
    bt.println(val);
    if(val=='g') {
    analogWrite(redPin, 230);
    analogWrite(greenPin, 200);
    analogWrite(bluePin, 5);
    bt.print("g");
    } else if(val=='r'){
    analogWrite(redPin, 230);
    analogWrite(greenPin, LOW);
    analogWrite(bluePin, LOW);
    } else if(val=='b'){
    analogWrite(redPin, LOW);
    analogWrite(greenPin, LOW);
    analogWrite(bluePin, 230);
    }
  }
}
