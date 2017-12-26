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

int r = 0;
int b = 0;
int g = 0;

int redValue = 255;
int blueValue = 127;
int greenValue = 0;

bool redInc = false;
bool blueInc = true;
bool greenInc = true;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  r = analogRead(A0);
  b = analogRead(A5);
  g = analogRead(A1);
  
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

  delay(20);

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

