const int buttonPin =2;
const int RledPin = 3;
const int GledPin = 4;
const int BledPin = 5;

int buttonState = 0;
int ledState = LOW;
int ledcolor = 0;

bool ButtonPressed = false;
String currentcolor = "led";

unsigned long previousMillis = 0;
const long interval = 1000;
bool  ledColorOrder = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);

  pinMode(buttonPin, INTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if(buttonState0 == HIGH && !ButtonPressed) {
    ledColorOrder =  !ledColorOrder;
    ButtonPressed = true;
  }

  if(buttonState == LOW && ButtonPressed) {
    ButtonPressed = false;
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previourMillis >= interval) {
    previousMillis = currentMillis;
  }
  if (ledColorOrder == true){
    ledcolor = ledcolor + 1;
    if (ledcolor > 3 )
    ledcolor = 0;
  } else {
      ledcolor = ledcolor -1;
    if (ledcolor < 0)
      ledcolor
  }


}
