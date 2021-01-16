#include<SoftPWM.h> //used to generate PWM signal for motor control

#define echoPin 2 //attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define PWM_Freq = 50 //PWM for FS5106B motor

float duration; //for pulse duration
int c = 0;

float sense(){
  //Send pulse out
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //Read return wave and calculate distance
  return pulseIn(echoPin, HIGH) * (0.0343/2);
}

void setup() {
  Serial.begin(9600);
  //initialize and select PWM pins
  SoftPWMBegin(50);
  SoftPWMSet(13,0);
  SoftPWMSet(12,0);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
}

void loop() {
  c = c + 5;
  if(c>99) c = 0;
  //Serial.print("Dist: ");
  //Serial.print(sense(), 4);
  Serial.print('\n');
  SoftPWMSet(13,c);
  Serial.print(c);
  delay(2000);
}
