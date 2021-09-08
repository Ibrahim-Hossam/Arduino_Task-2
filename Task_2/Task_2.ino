#define Red 8
#define Green 10
#define Buz 5
int sensorPin = 0;
int sensorPin_2 = 1;
int sensorVal = 0;
int sensorVal_2 = 0;
int counter = 0;
void setup() { Serial.begin(9600);
pinMode(Green,OUTPUT);
pinMode(Red,OUTPUT);
pinMode(Buz,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
}
void loop() {
sensorVal = analogRead(sensorPin);
sensorVal_2 = analogRead(sensorPin_2);
if ( sensorVal < 300){
  digitalWrite(Green, HIGH);
  counter ++;
  delay(1500);
} else{
  digitalWrite(Green, LOW);
}
if ( sensorVal_2 < 400){
  digitalWrite( Red, HIGH);
  counter --;
  delay(1500);
} else{
  digitalWrite(Red, LOW);
}
}
