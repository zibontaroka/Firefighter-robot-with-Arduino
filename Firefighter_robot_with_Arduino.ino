#include <Servo.h>

// Motor Connections
#define enA 11
#define in1 10
#define in2 9
#define in3 8
#define in4 7
#define enB 6

// Sensor Connections
#define Ir_Right A0
#define ir_F A1
#define ir_L A2

// Servo & Pump
#define servo 3
#define pump 2

// Fire detection threshold (calibrated dynamically)

int fireThreshold = 800;
int nearFireThreshold = 30; // When fire is close enough to turn on the pump
int servotimer = 400; // Servo changge directtion delay
int Speed = 140; // Motor Speed
Servo myServo;



void setup() {
    Serial.begin(9600);

    pinMode(Ir_Right, INPUT);
    pinMode(ir_F, INPUT);
    pinMode(ir_L, INPUT);

    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(enB, OUTPUT);

    pinMode(pump, OUTPUT);
    myServo.attach(servo);

    myServo.write(90); // Initial servo position
    analogWrite(enA, Speed);
    analogWrite(enB, Speed);

    delay(10);
}

void loop() {
    int rightSensor = analogRead(Ir_Right);
    int frontSensor = analogRead(ir_F);
    int leftSensor = analogRead(ir_L);

    Serial.print("Right: "); Serial.print(rightSensor);
    Serial.print(" | Front: "); Serial.print(frontSensor);
    Serial.print(" | Left: "); Serial.println(leftSensor);


         if (frontSensor < 20) {
        Stop();
        moveBackward(); // Move closer to fire
    } 

        else if (rightSensor < 20) {
        Stop();
        moveBackward(); // Move closer to fire
    } 

        else if (leftSensor < 20) {
        Stop();
        moveBackward(); // Move closer to fire
    } 

    // Fire Detection Logic
   else if (frontSensor < nearFireThreshold) {
        Stop();
        extinguishFire();
    } 


   else if (rightSensor < nearFireThreshold) {
      Stop();
      delay(30);
      moveBackward();
      delay(300);
      turnRight();
      delay(120);
   
        
    } 
    
  else if (leftSensor < nearFireThreshold) {
      Stop();
      delay(30);
          Stop();
      moveBackward();
      delay(300);
      turnLeft();
      delay(120);
        
    } 




    else if (frontSensor < fireThreshold) {
        Stop();
        moveForward(); // Move closer to fire
    } 



    else if (rightSensor < fireThreshold) {
      Stop();
      moveBackward();
      delay(900);
      turnRight();
      delay(150);
      if ( rightSensor < 150){
        Speed = 80;
      }

    } 


    else if (leftSensor < fireThreshold) {
      Stop();
      moveBackward();
      delay(900);
      turnLeft();
      delay(150);
      if ( rightSensor < 150){
        Speed = 80;
      }

    } 


    else {
        Stop();
    }


}



void moveForward() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void moveBackward() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void turnRight() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void turnLeft() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void Stop() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

void extinguishFire() {
    digitalWrite(pump, HIGH);
    
    for (int i = 0; i < 3; i++) {
        myServo.write(0);
        delay(servotimer);
        
        myServo.write(90);
        delay(servotimer);

        myServo.write(180);
        delay(servotimer);

        myServo.write(90);
        delay(servotimer);
        
        myServo.write(0);

    }

    digitalWrite(pump, LOW);
}
