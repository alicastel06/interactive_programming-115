const int buttonPin = 2;
const int RledPin =3;
const int GledPin =4;
const int BledPin =5;

int buttonState =1;
int ledState = 0;
int ledcolor =0;
String currentcolor = "led";
unsigned long previousMillis = 0;
const long interval = 1000;
bool ButtonPressed = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);

  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead (buttonPin);
  Serial.print ("Current Color: ");
  Serial.println (currentcolor);

  if(buttonState == HIGH && !ButtonPressed){
  ledcolor = ledcolor + 1;
    if (ledcolor > 7){
      ledcolor = 0;
    }
  ButtonPressed = true;
    //delay(100);
  }
  
  if (buttonState == LOW && ButtonPressed){
  ButtonPressed = false;
  }

  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;

    if(ledState == LOW){
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
  }

  if (ledcolor == 0){
    currentcolor= "LED off";
    digitalWrite (RledPin, HIGH);
    digitalWrite (GledPin, HIGH);
    digitalWrite (BledPin, HIGH);
  }
  else if (ledcolor == 1){
    //red
    currentcolor= "Red";
    if (ledState == LOW){
    digitalWrite (RledPin, LOW);
    digitalWrite (GledPin, HIGH);
    digitalWrite (BledPin, HIGH);
    } else {
      digitalWrite (RledPin, HIGH);
      digitalWrite (GledPin, HIGH);
      digitalWrite (BledPin, HIGH);
    }
  }
  else if (ledcolor == 2){
    //GREEN
    currentcolor = "Green";
    if (ledState == LOW){
    digitalWrite (RledPin, HIGH);
    digitalWrite (GledPin, LOW);
    digitalWrite (BledPin, HIGH);
    } else {
      digitalWrite (RledPin, HIGH);
      digitalWrite (GledPin, HIGH);
      digitalWrite (BledPin, HIGH);
    }
  }
  else if (ledcolor == 3){
    //BLUE
    currentcolor = "Blue";
    if (ledState == LOW){
    digitalWrite (RledPin, HIGH);
    digitalWrite (GledPin, HIGH);
    digitalWrite (BledPin, LOW);
    } else {
      digitalWrite (RledPin, HIGH);
      digitalWrite (GledPin, HIGH);
      digitalWrite (BledPin, HIGH);
    }
  }

   else if (ledcolor == 4){
    //yellow
    currentcolor = "Yellow";
    if (ledState == LOW){
    digitalWrite (RledPin, LOW);
    digitalWrite (GledPin, LOW);
    digitalWrite (BledPin, HIGH);
    } else {
      digitalWrite (RledPin, HIGH);
      digitalWrite (GledPin, HIGH);
      digitalWrite (BledPin, HIGH);
    }
  }

  else if (ledcolor == 5){
    //PURPLE
    currentcolor = "Purple";
    if (ledState == LOW){
    digitalWrite (RledPin, LOW);
    digitalWrite (GledPin, HIGH);
    digitalWrite (BledPin, LOW);
    } else {
      digitalWrite (RledPin, HIGH);
      digitalWrite (GledPin, HIGH);
      digitalWrite (BledPin, HIGH);
    }
  }

  else if (ledcolor == 6){
    //CYAN
    currentcolor = "Cyan";
    if (ledState == LOW){
    digitalWrite (RledPin, HIGH);
    digitalWrite (GledPin, LOW);
    digitalWrite (BledPin, LOW);
    } else {
      digitalWrite (RledPin, HIGH);
      digitalWrite (GledPin, HIGH);
      digitalWrite (BledPin, HIGH);
    }
  }

  else if (ledcolor == 7){
    //WHITE
    currentcolor = "White";
    if (ledState == LOW){
    digitalWrite (RledPin, LOW);
    digitalWrite (GledPin, LOW);
    digitalWrite (BledPin, LOW);
    } else {
      digitalWrite (RledPin, HIGH);
      digitalWrite (GledPin, HIGH);
      digitalWrite (BledPin, HIGH);
    }
  }

  //else if (ledcolor == 8){
    //ledcolor = 0;
    Serial.print("Current Color: ");
    Serial.println(currentcolor);

}

