// C++ code


const int trigPin = 10; 
const int echoPin = 9; 
const int motorPin = 3; 
int t ;
int d ;
int speed ;



void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  t= pulseIn(echoPin, HIGH);
  d=0.0343*(t/2);
  if(d>20 && d<200){
    speed = map(d,20,200,255,0);
    analogWrite(motorPin,speed);
  }
  else{
     analogWrite(motorPin,0);
    
  }
}