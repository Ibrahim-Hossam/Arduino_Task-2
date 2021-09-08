#define Red 8 // Red led pin
#define Green 10  // Green led pin
#define buzzer 5  // buzzer pin
int EntrPin = 0;  // Enterance light sensor input pin
int ExitPin = 1;  // Exit light sensor input pin
int EntrVal = 0;  // initializing the light sensor value
int ExitVal = 0;
int number_of_persons = 0;   // initializing the number of persons variable to count the number of persons in a  room
void setup() { Serial.begin(9600); // In wetup we Gave each pin it's information as input or output
pinMode(Green,OUTPUT);
pinMode(Red,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
}
void loop() {
EntrVal = analogRead(EntrPin);  // A variable to read the entrance light sensor value 
ExitVal = analogRead(ExitPin);  // A variable to read the entrance light sensor value 
if ( EntrVal < 300){  // A condition to count the number of persons entered if the light sensor value is less than the room light and to make the green led turn on to know that a person entered(the maximum value of the sensor is 550)
  digitalWrite(Green, HIGH);
  number_of_persons ++;
  delay(1500);
} else{
  digitalWrite(Green, LOW);
}
if ( ExitVal < 400){  // A condition to count the number of persons exited if the light sensor value is less than the room light and to make the red led turn on to know that a person exited(the maximum value of the sensor is 650)
  digitalWrite( Red, HIGH);
  number_of_persons --;
  delay(1500);
} else{
  digitalWrite(Red, LOW);
}
 if (number_of_persons > 5){  // A condition to make the buzzer make sound and to show an error message if the number of persons in a room is more than 5
      Serial.print("ERROR: Number of persons exceeded 5 persons in the room!\n");
      tone(buzzer, 1000);
    }
    else{
      noTone(buzzer);
    }
    delay(20);
}
