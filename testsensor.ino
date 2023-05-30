#define colorS0 A4
#define colorS1 A5
#define colorS2 A2
#define colorS3 A1
#define colorOut A3

int redMin = 15, redMax = 200;
int greenMin = 15, greenMax = 200;
int blueMin = 15, blueMax = 200;
int redPW = 0, greenPW = 0, bluePW = 0;
int redValue, greenValue, blueValue;

void setup() {

  pinMode(colorS0, OUTPUT);
	pinMode(colorS1, OUTPUT);
	pinMode(colorS2, OUTPUT);
	pinMode(colorS3, OUTPUT);
	pinMode(colorOut, INPUT);
	digitalWrite(colorS0, HIGH);
	digitalWrite(colorS1, LOW);

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

  Serial.print(redValue);
  Serial.print(greenValue);
  Serial.println(blueValue);

  if (redValue < 200 && redValue > 140 && greenValue < 200 && greenValue > 170 && blueValue < 230 && blueValue > 200) {
    Serial.println("blue sensed");
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