/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

int red = 11;           // the PWM pin the LED is attached to
int green = 10;
int blue = 6;
int buttonPin = 8;

int r = 0;
int b = 0;
int g = 0;

int redValue = 255;
int blueValue = 127;
int greenValue = 0;

bool redInc = false;
bool blueInc = true;
bool greenInc = true;

int buttonState;             // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin

int currentMode = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
}

// the loop routine runs over and over again forever:
void loop() {

  int buttonState = digitalRead(buttonPin);
  
  if(buttonState != lastButtonState && buttonState == HIGH){
    currentMode++;
    if(currentMode >= 8){
      currentMode = 0;
    }
  }

  switch (currentMode) {

    case 0:
      coal();
      break;
    case 1:
      iron();
      break;
    case 2:
      gold();
      break;
    case 3:
      redstone();
      break;
    case 4:
      azur();
      break;
    case 5:
      emerald();
      break;
    case 6:
      diamond();
      break;
    case 7:
      fade();
      break;
    default:
      diamond();
  }
  

   lastButtonState = buttonState;

  delay(20);

}

void coal(){
  analogWrite(red,250);
  analogWrite(blue,250);
  analogWrite(green,250);
}

void iron(){
  analogWrite(red,102);
  analogWrite(blue,204);
  analogWrite(green,153);
}

void redstone(){
  analogWrite(red,0);
  analogWrite(blue,255);
  analogWrite(green,255);
}

void gold() {
  analogWrite(red,0);
  analogWrite(blue,255);
  analogWrite(green,40);
}

void diamond() {
  analogWrite(red,245);
  analogWrite(blue,0);
  analogWrite(green,0);
}

void emerald() {
  analogWrite(red,255);
  analogWrite(blue,240);
  analogWrite(green,20);
}

void azur(){
  analogWrite(red,255);
  analogWrite(blue,0);
  analogWrite(green,150);
}

void fade() {

   if(redInc){
    redValue = incrementToMax(redValue);
    if(redValue >= 255){ redInc = false;}
  } else {
    redValue = decrementToZero(redValue);
    if(redValue <= 0){ redInc = true;}
  }

  if(blueInc){
    blueValue = incrementToMax(blueValue);
    if(blueValue >= 255){ blueInc = false;}
  } else {
    blueValue = decrementToZero(blueValue);
    if(blueValue <= 0){ blueInc = true;}
  }

  if(greenInc){
    greenValue = incrementToMax(greenValue);
    if(greenValue >= 255){ greenInc = false;}
  } else {
    greenValue = decrementToZero(greenValue);
    if(greenValue <= 0){ greenInc = true;}
  }

  analogWrite(red,redValue);
  analogWrite(blue,blueValue);
  analogWrite(green,greenValue);

  delay(2);

  
}

int incrementToMax(int value) {

  if(value == 255){
    return 255;
  } else {
    return ++value;
  }
  
}

int decrementToZero(int value){
   
    if(value == 0){
      return 0;    
    } else {
      return --value;
    }
}

