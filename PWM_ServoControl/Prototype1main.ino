//PRM IMPLEMENTED CODE
//Evan Kerr
//--------------------------------------
// analogWrite(pin, DutyCycle)
// Duty Cycle - 0 --> 255 (2^8 -1)
//--------------------------------------

//We want the arduino to read the duty cycle, not define the duty cycle
//This means that there needs to be a signal (external) that reads this

int Pot_Pos = 6; //Potentionmeter position
int Act_Pos = 7; //Servo position (Actuator)
int pos = 0 //Initial actuator angular distance

void setup() {

  pinMode(Pot_Pos, INPUT);//PWM Signal is read through a potentiometer (or in the future, wireless communication equipment)
  pinMode(Act_Pos, OUTPUT);//Output corresponds to voltage sent to actuator

  myServo.attach(Act_Pos)//Initialize actuator position

  Serial.begin(9600); //Opens serial monitor
}

void loop() {

  int analogvalue = analogRead(6); //Potentiometer value is read

  analog_to_voltage = (255. / 1023.) * analogvalue; //Converted to voltage, determines the amount of voltage sent to the actuator
  voltage_to_act = analogWrite(Act_Pos, analog_to_voltage);
  voltage_to_act;

  if (voltage_to_act < 0) {

    Serial.println("Signal Detected");
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degreesin steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }

  } else {
    Serial.println("Signal Not Detected");
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                      // waits 15ms for the servo to reach the position
    }
  }
}
