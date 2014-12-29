#include <Servo.h> 
 
Servo myservo;  
int pingPin = 13;
int inPin = 12;
long microseconds;
int curvaServo;



void setup() {

Serial.begin(9600);
myservo.attach(5);

}

void loop() {
long duration, inches, cm;
pinMode(pingPin, OUTPUT);

digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);

pinMode(inPin, INPUT); 
duration = pulseIn(inPin, HIGH);
cm = microsecondsToCentimeters(duration);

//TESTE
if(Serial.read() == 'A'){
  Serial.println("RECEBIDO");
}
//TODO: FAZER CONSEGUIR LER AS INFORMACOES E DISPONIBILIZA-LAS DIREITO, ALEM DE FAZER A INTERFACE COM O TWIITER.
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(500); 


curvaServo = map(cm,0,160,0,180);


  myservo.write(curvaServo);



}


long microsecondsToCentimeters(long microseconds) { return microseconds / 29 / 2;}
