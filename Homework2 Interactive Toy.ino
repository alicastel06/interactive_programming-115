const int buttonPin = 2;
const int RledPin = 9;
const int GledPin = 10;
const int BledPin = 11;

int mood = 0;
const int neutralMood = 10;
int buttonState = 0;
bool ButtonPressed = false;

unsigned long touchedTimer = 0;
unsigned long reducedTimer = 0;
unsigned long PressStartTime = 0;

const long unTouchInterval = 5000;
const long reducedInterval = 2000;
const long longPressInterval = 2000;

bool longPressHandled = false;
bool sleepingState = false;

float shownMood = 10;
unsigned long fadeTimer = 0;
//unsigned long previousMillis = 0;

void setup() {
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

  mood = neutralMood;
}

void loop() {
  
  if(millis() - fadeTimer > 20){
    fadeTimer = millis();
    if(mood - shownMood > 0.1) shownMood = shownMood + 0.1;
    else if(shownMood - mood > 0.1) shownMood = shownMood - 0.1;
  }

  if(sleepingState){
    showSleeping();
  } else{
    showLEDState(shownMood);
  }
    
    buttonState = digitalRead(buttonPin);
    Serial.println(buttonState);
    
    if(buttonState == HIGH && !ButtonPressed){
        mood = mood + 2;
        if(mood > 20) mood = 20;
        touchedTimer = millis();
        ButtonPressed = true;
        PressStartTime = millis();
        longPressHandled = false;
        
    } 
    if(buttonState == HIGH && ButtonPressed && !longPressHandled){
        if(millis() - PressStartTime >= longPressInterval){
          sleepingState = !sleepingState;
          longPressHandled = true;
        }
    }
        
    if (buttonState == LOW && ButtonPressed){
        ButtonPressed = false;
    }
  
    unsigned long currentMillis = millis();
    if(!sleepingState && currentMillis - touchedTimer > unTouchInterval){

      if(currentMillis - reducedTimer > reducedInterval){
        mood = mood - 1;
        if(mood < 0) mood = 0;
        reducedTimer = currentMillis;
      }
    }
}

  void showLEDState(float state){
    
    float brightnessInterval = 255 / 10.0;
    if(state >= neutralMood){
      analogWrite(RledPin, 255);
      analogWrite(GledPin, brightnessInterval * (state - neutralMood));
      analogWrite(BledPin, 255 - brightnessInterval * (state - neutralMood));
    }
    else if (state < neutralMood){
      analogWrite(RledPin, brightnessInterval * state); 
      analogWrite(GledPin, 255 - brightnessInterval * state);
      analogWrite(BledPin, 255);
    }
}

  void showSleeping() {
    analogWrite(RledPin, 0);
    analogWrite(GledPin, 255);
    analogWrite(BledPin, 0);
  }


