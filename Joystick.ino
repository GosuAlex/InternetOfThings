// Pin numbers:
int JoyStick_X = 0; // Pin: Analog 0 = X axis
int JoyStick_Y = 1; // Pin: Analog 1 = y axis
int JoyStick_Pressed = 10; // Pin: Digital 10 = Press

void setup () { 
  Serial.begin(9600);
  pinMode(JoyStick_X, INPUT); 
  pinMode(JoyStick_Y, INPUT); 
  pinMode(JoyStick_Pressed, INPUT); 
} 

void loop () { 
  //int x, y, pressed;
  String compass = "Center";
  int x = analogRead(JoyStick_X);
  int y = analogRead(JoyStick_Y);
  int pressed = digitalRead(JoyStick_Pressed);

  if(x > 520 && x > y) {
    compass = "North";  
  } else if(x < 480 && x < y) {
    compass = "South";
  } else if(y > 520 && y > x) {
    compass = "East"; 
  } 
  if(y < 480 && y < x) {
    compass = "West";
  }

  Serial.print(compass + " - ");
  Serial.print(x, DEC);
  //Serial.print(x, DEC + ",");
  Serial.print(",");
  Serial.print(y, DEC);
  //Serial.print(y, DEC + ",");
  Serial.print(",");
  Serial.println(pressed, DEC);
  delay(200);
}
