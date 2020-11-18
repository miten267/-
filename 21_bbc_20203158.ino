// Arduino pin assignment
#include <Servo.h>
#define PIN_IR A0
#define PIN_LED 9
#define PIN_SERVO 10
#define _DIST_ALPHA 0.3
int a, b; // unit: mm
Servo myservo;

void setup() {
// initialize GPIO pins
  myservo.attach(PIN_SERVO); 
  myservo.writeMicroseconds(1500);
  pinMode(PIN_LED,OUTPUT);
  digitalWrite(PIN_LED, 1);
// initialize serial port
  Serial.begin(57600);
  a = 33;
  b = 90;
}
float ir_distance(void){ // return value unit: mm
  float val;
  float volt = float(analogRead(PIN_IR));
  val = pow((volt / 1893.9), -1.087) * 10;
  return val;
}
void loop() {
  float raw_dist = ir_distance();
  float dist_cali = 100 + 300.0 / (b - a) * (raw_dist - a);
  Serial.print("min:0,max:500,dist:");
  Serial.print(raw_dist);
  Serial.print(",dist_cali:");
  Serial.println(dist_cali);
  if(dist_cali > 255)
    myservo.writeMicroseconds(1350);
  else
    myservo.writeMicroseconds(1650);
}
