#define Red 8 
#define Green 10
#define buzzer 5
int sensorPin = 0;
int sensorPin_2 = 1;
int sensorVal = 0;
int sensorVal_2 = 0;
int number_of_persons = 0;
void setup() { Serial.begin(9600);
pinMode(Green,OUTPUT);
pinMode(Red,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
}
void loop() {
Serial.print(number_of_persons,"\n");
sensorVal = analogRead(sensorPin);
sensorVal_2 = analogRead(sensorPin_2);
if ( sensorVal < 300){
  digitalWrite(Green, HIGH);
  number_of_persons ++;
  delay(1500);
} else{
  digitalWrite(Green, LOW);
}
if ( sensorVal_2 < 400){
  digitalWrite( Red, HIGH);
  number_of_persons --;
  delay(1500);
} else{
  digitalWrite(Red, LOW);
}
 if (number_of_persons > 5){
      Serial.print("ERROR: Number of persons exceeded 5 persons in the room!\n");
      tone(buzzer, 1000);
    }
    else{
      noTone(buzzer);
    }
    delay(20);
}
