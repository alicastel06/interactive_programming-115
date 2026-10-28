const int RledPin =9;
const int GledPin = 10;
const int BledPin = 11;
int maxBrightness = 0;
int fadingDirection = 1;
int currentBrightness = 0;

unsigned long previousMillis = 0;
int interval = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  maxBrightness = map(sensorValue, 0, 1023, 0, 255);

  unsigned long currentMillis = millis();
  int fadingAmount = fadingDirection * map(currentMillis - previousMillis, 0, interval, 0, maxBrightness);
  currentBrightness = currentBrightness + fadingAmount;
  if(currentBrightness >= 255){
    currentBrightness = 255;
    fadingDirection = -fadingDirection;
  }
  if (currentBrightness <= 0){
    currentBrightness = 0;
    fadingDirection = -fadingDirection;
  }


  analogWrite(RledPin, currentBrightness);
  analogWrite(GledPin, currentBrightness);
  analogWrite(BledPin, currentBrightness);
  previousMillis = currentMillis;
  delay (1);

}
