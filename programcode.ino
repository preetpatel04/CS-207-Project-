#include<Servo.h>


const int trigPin = 10;

const int echoPin = 9;

const int servoPin = 8; 

const int motorPin = 7;

//void motorTwoSpeed();

double SetDelay, Input, Output, ServoOutput; 
Servo myServo; //Initialize Servo.


void setup() {

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output

pinMode(echoPin, INPUT); // Sets the echoPin as an Input

Serial.begin(9600); // Starts the serial communication

myServo.attach(servoPin); //Attach Servo

 pinMode(motorPin, OUTPUT);
  motorTwoSpeed();
Input = readPosition(); 

}


void loop() {

  Input = readPosition(); 
  ServoOutput=Input;
  myServo.write(ServoOutput);

  if(ServoOutput ==140) 

    {

      SetDelay=150;
    
    }

    else{

      SetDelay=100;
      {
   motorTwoSpeed();
}

    } 

  delay(200); 

}
float readPosition() {

  delay(40); 

  long duration, var;

  int distance; 

  // Clears the trigPin

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  

  // Sets the trigPin on HIGH state for 10 micro seconds

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  

  // Reads the echoPin

  duration = pulseIn(echoPin, HIGH);

  

  // Calculating the distance

   distance = duration/(29*2); 

  

  // Prints the distance on the Serial Monitor

  Serial.print("Distance: ");

  Serial.println(distance);

 

  if(distance <68) {

    var=140;

  }

  else{

    var=50;

  } 

  //Returns distance value.

  return var; 
  }
void motorTwoSpeed()
{
  const int onSpeed = 200; // a number between 0 (stopped) and 255 (full speed)
  const int onTime = 1000; //the number of milliseconds for the motor to turn on for

  const int offSpeed = 27; // a number between 0 (stopped) and 255 (full speed)
  const int offTime = 1000; //the number of milliseconds for the motor to turn off for

  analogWrite(motorPin, onSpeed); // turns the motor 
  delay(onTime); // waits for onTime milliseconds
  analogWrite(motorPin, offSpeed); // turns the motor Off
  delay(offTime); // waits for offTime milliseconds
}
