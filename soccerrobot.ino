#include <AFMotor.h>
#include <Servo.h> 

Servo myservo;  // create servo object to control a servo
int pos = 0;  // variable to store the servo position

AF_DCMotor motor(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);

char val;
void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT);

  motor.setSpeed(200);
  motor2.setSpeed(200);
   myservo.attach(9);   
   myservo.write(90);
}

void loop(){
  if (Serial.available() >0 ){
    val = Serial.read();
    Serial.println(val); 
  }
  if (val == '0'){
    motor.run(RELEASE);
    motor2.run(RELEASE);
  }
    if (val == '1'){
     motor.run(FORWARD);
     motor2.run(FORWARD);
  }
    if (val == '2'){
     motor.run(FORWARD);
     motor2.run(BACKWARD);
  }
      if (val == '3'){
     motor.run(BACKWARD);
     motor2.run(FORWARD);
  }
      if (val == '4'){
     motor.run(BACKWARD);
     motor2.run(BACKWARD);
  }
     if (val == '5'){
     myservo.write(0);
  }
       if (val == '6'){
     myservo.write(90);
  }
}
