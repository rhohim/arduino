#include <Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
Servo servo;
int trigPin = 10;
int echoPin = 13;
//int trigPin2 = 6;
//int echoPin2 = 7;
int LED = 11;
int Celcius = 81;




void setup() {
  Serial.begin(9600);
  servo.attach(8);
  pinMode(3, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  sensors.begin();
  pinMode(LED,OUTPUT);
  
}

void loop() {
  sensors.requestTemperatures();
  Celcius = sensors.getTempCByIndex(0);
  Serial.print(" C : ");
  Serial.println(Celcius);
  if (Celcius >= 80 && Celcius <=90){
    digitalWrite(3,LOW);
    digitalWrite(LED,HIGH);
    delay(1000);
    Serial.print("Suhu = ");
    Serial.println(Celcius);
    ultrasonic1(trigPin,echoPin);
  }else {
    digitalWrite(3, HIGH);
    digitalWrite(LED,LOW);
    delay(1000);
  }
  //ultrasonic2(LED,trigPin2,echoPin2);
}

void ultrasonic1(int trigPin, int echoPin){
  float durasi, jarak;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durasi = pulseIn(echoPin, HIGH);
  jarak = (durasi/2)*0.0344;
  if (jarak < 12) {
    Serial.println("OPEN!!!");
    int dg;
    for(dg = 10;dg<=180; dg++){
      servo.write(dg);
      delay(15);
    }
    delay(3000);
    servo.write(0);
  }
  else {
    Serial.println("CLOSED!!!");
    servo.write(0);

    
  }
  delay(1000);
}

//void ultrasonic2 (int LED,int trigPin, int echoPin){
//  float durasi, jarak;
//  Serial.println("ultrasonic 2");
//  digitalWrite(trigPin,LOW);
//  delayMicroseconds(2);
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//  durasi = pulseIn(echoPin, HIGH);
//  jarak = (durasi/2)*0.0344;
//  //Serial.println(durasi);
//  Serial.println(jarak);
//  if (jarak < 5) {
//    Serial.println("ON!!!");
//    delay(1000);
//    digitalWrite(LED,HIGH);
//    delay(1000);
//    digitalWrite(LED,LOW);
//  }
//  else {
//    Serial.println("OFF!!!");
//    digitalWrite(LED,LOW);
//  }
  
//}
