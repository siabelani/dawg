#include <Servo.h>

Servo servo;
Servo latch;

void setup() {

  servo.attach(8);
  servo.write(0);

  latch.attach(11);
  latch.write(0);

	Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  servo.write(180);
  delay(2000);
  servo.write(0);

  latch.write(180);
  delay(2000);
  latch.write(0);

}