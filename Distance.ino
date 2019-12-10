// Pin numbers:
int trig = 11; // pin: digital 11
int echo = 10; // pin: echo 10

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(10);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);  
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  // Lengden i CM:
  int distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" CM");  
  delay(200);
}
