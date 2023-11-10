void setup() {

  //---------  PIN SERVO   --------
  myservo1.attach(A0);
  myservo2.attach(A2);
  myservo3.attach(A3);

  //-----  SUDUT AWAL SERVO ------
  myservo1.write(140);
  myservo2.write(81);
  myservo3.write(35);


  //ax12a.begin(BaudRate, DirectionPin, &Serial2);
  //ax12a.setEndless(ID, ON);

  pinMode(enA1, OUTPUT);
  pinMode(enB2, OUTPUT);
  pinMode(enA3, OUTPUT);
  pinMode(enB4, OUTPUT);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);

  
  Serial.begin(115200);
  delay(500);

//============================ 53 clock, 51 command, 52 attention, 50 data, Pressures?, Rumble? ====================================
  error = ps2x.config_gamepad(13, 11, 10, 12, true, true); //(13, 11, 10, 12,
  if (error == 0) {
    Serial.println("Found Controller, configured successful dan bismillah juara 1");
  }

  else if (error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
  else if (error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");
  else if (error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");

  type = ps2x.readType();
  switch (type) {
    case 0:
      Serial.println("Unknown Controller type");
      break;
    case 1:
      Serial.println("DualShock Controller Found");
      break;
    case 2:
      Serial.println("GuitarHero Controller Found");
      break;
  }
}
