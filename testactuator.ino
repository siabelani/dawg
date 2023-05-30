#define actuator1 3
#define actuator2 4

void setup() {

  pinMode(actuator1, OUTPUT);
  pinMode(actuator2, OUTPUT);
  digitalWrite(actuator1, LOW);
  digitalWrite(actuator2, LOW);

	Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(actuator1, HIGH);
  digitalWrite(actuator2, LOW);
  delay(10000);
  digitalWrite(actuator1, LOW);
  digitalWrite(actuator2, HIGH);
  digitalWrite(actuator1, LOW);
  digitalWrite(actuator2, LOW);

}