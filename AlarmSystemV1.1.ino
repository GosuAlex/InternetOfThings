#include <Keypad.h>

String password = "1234";
String input = "";

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6,};
byte colPins[COLS] = {5, 4, 3, 2,};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

int trigPin = 11;
int echoPin = 10;
int buzzPin = 12;

bool distanceIsSet = false;
bool beepingSoundOn = false;
long duration, cm;
long originalDistance;

void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop() 
{
  char customKey = customKeypad.getKey();
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
 
  // Konverter tid til distance
  cm = (duration/2) / 29.1;


  //Sjekk om det er en forskjell i distansen
  if (!(distanceIsSet)) {
    originalDistance = cm;
    distanceIsSet = true; 
    Serial.println("DISTANSE SATT: ");
    Serial.print(originalDistance);
  }

  if (cm < originalDistance) 
  {
    beepingSoundOn = true;
  }

  if (customKey)
  {
    Serial.println(customKey);
    input = input + String(customKey);
    Serial.println("Input: "+ input);
    Serial.println("Password: " + password);
  }

  //HVIS PASSORD ER LIK INPUT, SKRU AV ALARM
  if (input == password) {
    beepingSoundOn = false;
  }
  
  if (beepingSoundOn)
  {
      delay(100);
      digitalWrite(buzzPin, HIGH);
      delay(100);
      digitalWrite(buzzPin, LOW);
      delay(100);
      digitalWrite(buzzPin, HIGH);
  } 

  else if (!(beepingSoundOn)) 
  {
    digitalWrite(buzzPin, LOW);
  }
  delay(100);
}
