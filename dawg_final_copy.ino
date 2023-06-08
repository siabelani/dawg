#include <Servo.h>

#define motorPin1 5
#define motorPin2 6
#define motorPin3 10
#define motorPin4 9

#define colorS0 A4
#define colorS1 A5
#define colorS2 A2
#define colorS3 A1
#define colorOut A3

Servo servo;
Servo latch;

#define actuator1 3
#define actuator2 4


int redMin = 15, redMax = 200;
int greenMin = 15, greenMax = 200;
int blueMin = 0, blueMax = 200;
int redPW = 0, greenPW = 0, bluePW = 0;
int redValue, greenValue, blueValue;

int treatcount = 0;


void setup() {

  pinMode(colorS0, OUTPUT);
  pinMode(colorS1, OUTPUT);
  pinMode(colorS2, OUTPUT);
  pinMode(colorS3, OUTPUT);
  pinMode(colorOut, INPUT);
  digitalWrite(colorS0, HIGH);
  digitalWrite(colorS1, LOW);

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);

  servo.attach(8);
  servo.write(0);

  latch.attach(11);
  latch.write(0);

  pinMode(actuator1, OUTPUT);
  pinMode(actuator2, OUTPUT);
  digitalWrite(actuator1, LOW);
  digitalWrite(actuator2, HIGH);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  redPW = getRedPW();
  redValue = map(redPW, redMin, redMax, 255, 0);
  delay(200);

  greenPW = getGreenPW();
  greenValue = map(greenPW, greenMin, greenMax, 255, 0);
  delay(200);

  bluePW = getBluePW();
  blueValue = map(bluePW, blueMin, blueMax, 255, 0);
  delay(200);

  if (redValue < 200 && redValue > 5 && greenValue < 150 && greenValue > 50 && blueValue < 180 && blueValue > 100) {
    dawgActivate();
  }

}

int getRedPW() {
  digitalWrite(colorS2, LOW);
  digitalWrite(colorS3, LOW);
  int PW;
  PW = pulseIn(colorOut, LOW);
  return PW;
}

int getGreenPW() {
  digitalWrite(colorS2, HIGH);
  digitalWrite(colorS3, HIGH);
  int PW;
  PW = pulseIn(colorOut, LOW);
  return PW;
}

int getBluePW() {
  digitalWrite(colorS2, LOW);
  digitalWrite(colorS3, HIGH);
  int PW;
  PW = pulseIn(colorOut, LOW);
  return PW;
}

void runMotor() {
  digitalWrite(actuator1, HIGH);
  digitalWrite(actuator2, LOW);
  delay(5000);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(30000);
  digitalWrite(actuator1, LOW);
  digitalWrite(actuator2, HIGH);
  delay(20000);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}

void runActuator() {
  digitalWrite(actuator1, HIGH);
  digitalWrite(actuator2, LOW);
  delay(10000);
  digitalWrite(actuator1, LOW);
  digitalWrite(actuator2, HIGH);
  digitalWrite(actuator1, LOW);
  digitalWrite(actuator2, LOW);
}

void dawgActivate() {
  //lets ball through funnel and begins motors
  latch.write(180);
  delay(2000);
  latch.write(0);
  //pushes ball towards motors
  runMotor();
  treatcount++;
  if (treatcount % 3 == 0) {
    servo.write(180);
    delay(2000);
    servo.write(0);
  }
}

//170, 190, 220
