int buzzpin = 4;
int ledpin = 8;
int yellowpin = 2;
int Flame_sensor_analogpin = A0;
int Flame_sensor_digitalpin= 12;
int delay_time = 500;
int pitch;

int Flame_sensor_analog_reading;
int Flame_sensor_digital_reading;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buzzpin, OUTPUT);
pinMode(ledpin, OUTPUT);
pinMode(Flame_sensor_analogpin, INPUT);
pinMode(Flame_sensor_digitalpin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Flame_sensor_analog_reading = analogRead(Flame_sensor_analogpin);
Flame_sensor_digital_reading = digitalRead(Flame_sensor_digitalpin);


if (Flame_sensor_analog_reading < 500){
  pitch = map(Flame_sensor_analog_reading, 0, 500, 400, 2000);

  tone(buzzpin, pitch);
  digitalWrite(ledpin, HIGH);
  delay(delay_time);
  digitalWrite(ledpin, LOW);
  delay(delay_time);

  Serial.println("Fire occuring!!!");
}
else{
  noTone(buzzpin);
  digitalWrite(ledpin, LOW);
}


if(Flame_sensor_digital_reading == 0){
    digitalWrite(yellowpin, HIGH);
    delay(delay_time);
    digitalWrite(yellowpin, LOW);
    delay(delay_time);
  }
  else{
    digitalWrite(yellowpin, LOW);
  }

Serial.print("The current reading of the flame analog_reading is ");
Serial.println(Flame_sensor_analog_reading);

Serial.print("The current reading of the flame digital_reading is ");
Serial.println(Flame_sensor_digital_reading);
delay(delay_time);


}
