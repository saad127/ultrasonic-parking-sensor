const int greenLedPin = 2;
const int orangeLedPin = 3;
const int redLedPin = 4;
const int BuzzerPin = 5;
const int trigPin = 6;
const int echoPin = 7;
void setup(){
	pinMode(greenLedPin,OUTPUT);
  	pinMode(orangeLedPin,OUTPUT);
  	pinMode(redLedPin,OUTPUT);
	pinMode(BuzzerPin,OUTPUT);
  	pinMode(trigPin,OUTPUT);
  	pinMode(echoPin,INPUT);
}
void loop(){
 digitalWrite(trigPin,LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
 float duration = pulseIn(echoPin,HIGH);
 float Distance = ((duration*0.034)/2);
   if(Distance > 100)
 {
 	digitalWrite(greenLedPin,HIGH);
    digitalWrite(orangeLedPin,LOW);
    digitalWrite(redLedPin,LOW);
    digitalWrite(BuzzerPin,LOW);
 
 }else if(Distance <= 100 && Distance > 50)
 {
 	digitalWrite(greenLedPin,LOW);
    digitalWrite(orangeLedPin,HIGH);
    digitalWrite(redLedPin,LOW);
    digitalWrite(BuzzerPin,HIGH);
 	delay(100);
    digitalWrite(BuzzerPin,LOW);
 	delay(200); 
 }else if(Distance <= 50){
 
 	digitalWrite(greenLedPin,LOW);
    digitalWrite(orangeLedPin,LOW);
    digitalWrite(redLedPin,HIGH);
    digitalWrite(BuzzerPin,HIGH);
 	delay(50);
    digitalWrite(BuzzerPin,LOW);
 	delay(50); 
 }
}
