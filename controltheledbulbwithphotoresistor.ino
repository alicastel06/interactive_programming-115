int Photoresistor = 2;
int led = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Photoresistor, INPUT);
  pinMode (led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int PhotoresistorState = digitalRead (Photoresistor);
  digitalWrite (led, PhotoresistorState);

  Serial.println(PhotoresistorState);
  delay(1);
}
