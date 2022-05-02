
#include <Servo.h>

Servo myservo;

int pos = 120;    // variable to store the servo position
//int pos = 90;

int button1 = 7;
int button2 = 8;
int button3 = 10;

int analogPin = A0;

int step = 15;

double deg = 50;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  //myservo.read();

  myservo.write(pos);

  Serial.begin(9600);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
}

void loop() {
  // button1 to advance the position

  //delay(200);

  pos = myservo.read();
  deg = analogRead(analogPin);
  //step = 3;//20*(deg/1024);

  Serial.println(pos);
  
  while (digitalRead(button1) == 1 && (pos < 175))
  {
    Serial.write(pos);
    pos = pos + step;
    myservo.write(pos);
    delay(75);
  }

  /*while(digitalRead(button1) == 1 && (pos < 175)){
    myservo.write(pos);
    delay(15);
  }*/

  while (digitalRead(button2) == 1 && (pos > 0)) 
  {
    Serial.write(pos);
    pos = pos - step;
    myservo.write(pos);
    delay(75);
  }

  // 
  while (digitalRead(button3) == 1)
  {
    int pos_start = myservo.read();
    for (int i= 0; i<10; i++)
    {
      myservo.write(pos + 30);
      delay(75);
      myservo.write(pos - 30);
      delay(75);  
    }
    //delay(50);
    myservo.write(pos_start);
    delay(20);
  }

//  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
}
