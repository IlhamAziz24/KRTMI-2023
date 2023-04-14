#include <PS2X_lib.h>
int pwm;

#define enA1 13
#define enB2 8
#define enA3 7
#define enB4 2

#define motor1pin1 12
#define motor1pin2 11
#define motor2pin1 10
#define motor2pin2 9
#define motor3pin1 6
#define motor3pin2 5
#define motor4pin1 4
#define motor4pin2 3
PS2X ps2x;

int error = 0;
byte type = 0;
byte vibrate = 0;
int LY, LX, RY, RX, LYold, LXold, RYold, RXold;


//============================================== SERVO ======================================================
//#include <AX12A.h>
//#define DirectionPin  (10u)
//#define BaudRate    (1000000ul)
//#define ID    12

#include <Servo.h>
Servo myservo1; //-----> Capit
Servo myservo2; //-----> Putar
Servo myservo3; //-----> Naik Turun


//=============================================  SET UP  ===================================================
void setup() {

  myservo1.attach(A1);
  myservo2.attach(A2);
  myservo3.attach(A3);
  
  myservo1.write(116);
  myservo2.write(180);
  myservo3.write(100);

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
  error = ps2x.config_gamepad(53, 51, 52, 50, true, true);
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



//===============================================  LOOPING  ======================================================
void loop()
{
  LY = (int) ps2x.Analog(PSS_LY);
  LX = (int) ps2x.Analog(PSS_LX);
  RY = (int) ps2x.Analog(PSS_RY);
  RX = (int) ps2x.Analog(PSS_RX);

  Serial.print(" Analog Kiri: ");
  Serial.print(ps2x.Analog(PSS_LY), DEC); //Left stick, Y axis. Other options: LX, RY, RX
  Serial.print(",");
  Serial.print(ps2x.Analog(PSS_LX), DEC);
  Serial.print(" ,");
  Serial.print(" Analog Kanan: ");
  Serial.print(ps2x.Analog(PSS_RY), DEC);
  Serial.print(", ");
  Serial.println(ps2x.Analog(PSS_RX), DEC);


 //================================= PEMBACAAN STIK =========================================
  ps2x.read_gamepad(false, vibrate);

  //SEGITIGA
  if (ps2x.Button(PSB_TRIANGLE))
  {
    analogWrite(enA1, 143);
    analogWrite(enB2, 140);
    analogWrite(enA3, 145);
    analogWrite(enB4, 140);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    
    digitalWrite(motor3pin1, LOW);
    digitalWrite(motor3pin2, HIGH);
    
    digitalWrite(motor4pin1, LOW);
    digitalWrite(motor4pin2, HIGH);
    Serial.print(" SEGITIGA DIPENCET ");
  }

  //X
  else if (ps2x.Button(PSB_CROSS))
  {
    analogWrite(enA1, 137);
    analogWrite(enB2, 130);
    analogWrite(enA3, 130);
    analogWrite(enB4, 130);
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);

    digitalWrite(motor3pin1, HIGH);
    digitalWrite(motor3pin2, LOW);

    digitalWrite(motor4pin1, HIGH);
    digitalWrite(motor4pin2, LOW);
    Serial.print(" X DIPENCET ");
  }
  
//=================================================  SERVO CAPIT  ===========================================================
  else if (ps2x.Button(PSB_L1))
  {
    Serial.print(" held this hard: ");
    myservo1.write(116);
    //move
  }
  else if (ps2x.Button(PSB_L2))
  {
    Serial.print(" held this hard: ");
    myservo1.write(25);
  }

//===================================================  SERVO PUTAR  ========================================================
  else if (ps2x.Button(PSB_R1))
  {
    myservo2.write(0);
  }
  
  else if (ps2x.Button(PSB_R2))
  {
    myservo2.write(155);
  }

  //BULET
  else if (ps2x.Button(PSB_CIRCLE))
  {
    pwm = 65;
    analogWrite(enA1, pwm);
    analogWrite(enB2, pwm);
    analogWrite(enA3, pwm);
    analogWrite(enB4, pwm);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);

    digitalWrite(motor3pin1, LOW);
    digitalWrite(motor3pin2, HIGH);

    digitalWrite(motor4pin1, HIGH);
    digitalWrite(motor4pin2, LOW);
    Serial.print(" BULAT DIPENCET ");
  }

  //KOTAK
  else if (ps2x.Button(PSB_SQUARE))
  {
    pwm = 65;
    analogWrite(enA1, pwm);
    analogWrite(enB2, pwm);
    analogWrite(enA3, pwm);
    analogWrite(enB4, pwm);
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);

    digitalWrite(motor3pin1, HIGH);
    digitalWrite(motor3pin2, LOW);

    digitalWrite(motor4pin1, LOW);
    digitalWrite(motor4pin2, HIGH);
    Serial.print(" KOTAK DIPENCET ");
  }


//=============================================== ANALOG KIRI ================================================
  //move forward ANALOG
  else if ((ps2x.Analog(PSS_LY) < 64) && ((ps2x.Analog(PSS_LX) >= 64) && (ps2x.Analog(PSS_LX) <= 192)))
  {
    analogWrite(enA1, 125);
    analogWrite(enB2, 95);
    analogWrite(enA3, 105);
    analogWrite(enB4, 115);
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);

    digitalWrite(motor3pin1, HIGH);
    digitalWrite(motor3pin2, LOW);

    digitalWrite(motor4pin1, HIGH);
    digitalWrite(motor4pin2, LOW);
  }

  //move backward ANALOG
  else if ((ps2x.Analog(PSS_LY) > 192) && ((ps2x.Analog(PSS_LX) >= 64) && (ps2x.Analog(PSS_LX) <= 192)))
  {
    analogWrite(enA1, 125);
    analogWrite(enB2, 95);
    analogWrite(enA3, 105);
    analogWrite(enB4, 115);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);

    digitalWrite(motor3pin1, LOW);
    digitalWrite(motor3pin2, HIGH);

    digitalWrite(motor4pin1, LOW);
    digitalWrite(motor4pin2, HIGH);
  }

  //move left ANALOG
  else if ((ps2x.Analog(PSS_LX) < 64) && ((ps2x.Analog(PSS_LY) >= 64) && (ps2x.Analog(PSS_LY) <= 192)))
  {
    analogWrite(enA1, 140);
    analogWrite(enB2, 105);
    analogWrite(enA3, 101);
    analogWrite(enB4, 111);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);

    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);

    digitalWrite(motor3pin1, HIGH);
    digitalWrite(motor3pin2, LOW);

    digitalWrite(motor4pin1, LOW);
    digitalWrite(motor4pin2, HIGH);
  }

  //move right ANALOG
  else if ((ps2x.Analog(PSS_LX) > 192) && ((ps2x.Analog(PSS_LY) >= 64) && (ps2x.Analog(PSS_LY) <= 192)))
  {
    analogWrite(enA1, 131);
    analogWrite(enB2, 101);
    analogWrite(enA3, 101);
    analogWrite(enB4, 111);
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);

    digitalWrite(motor3pin1, LOW);
    digitalWrite(motor3pin2, HIGH);

    digitalWrite(motor4pin1, HIGH);
    digitalWrite(motor4pin2, LOW);
  }


//================================================  ANALOG KANAN  ======================================================
  else if ((ps2x.Analog(PSS_RX) < 64) && ((ps2x.Analog(PSS_RY) >= 64) && (ps2x.Analog(PSS_RY) <= 192)))
  {
    muterka();
  }
  else if ((ps2x.Analog(PSS_RX) > 192) && ((ps2x.Analog(PSS_RY) >= 64) && (ps2x.Analog(PSS_RY) <= 192)))
  {
    muter();
  }


//============================================= ANALOG KIRI DIAGONAL ======================================================
  //MAJU KIRI
  else if ((ps2x.Analog(PSS_LY) < 50) && ((ps2x.Analog(PSS_LX) >= 0) && (ps2x.Analog(PSS_LX) <= 50)))
  {
    //analogWrite(enA1, pwm);
    analogWrite(enB2, 130);
    analogWrite(enA3, 130);
    //analogWrite(enB4, pwm);
    digitalWrite(motor2pin1, HIGH); digitalWrite(motor2pin2, LOW);
    digitalWrite(motor3pin1, LOW);  digitalWrite(motor3pin2, HIGH);
  }
  
  //MAJU KANAN
  else if ((ps2x.Analog(PSS_LY) < 64) && ((ps2x.Analog(PSS_LX) >= 200) && (ps2x.Analog(PSS_LX) <= 255)))
  {
    analogWrite(enA1, 130);
    //analogWrite(enB2, pwm);
    //analogWrite(enA3, pwm);
    analogWrite(enB4, 130);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);

    digitalWrite(motor4pin1, LOW);
    digitalWrite(motor4pin2, HIGH);
  }
  
  //MUNDUR KIRI
  else if ((ps2x.Analog(PSS_LY) < 257) && ((ps2x.Analog(PSS_LX) >= 0) && (ps2x.Analog(PSS_LX) <= 64)))
  {
    analogWrite(enA1, 130);
    //analogWrite(enB2, pwm);
    //analogWrite(enA3, pwm);
    analogWrite(enB4, 130);
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor4pin1, HIGH);
    digitalWrite(motor4pin2, LOW);
  }
  
  //MUNDUR KANAN
  else if ((ps2x.Analog(PSS_LY) > 220) && ((ps2x.Analog(PSS_LX) >= 200) && (ps2x.Analog(PSS_LX) <= 255)))
  {
    //analogWrite(enA1, pwm);
    //analogWrite(enB2, 75);
    //analogWrite(enA3, 75);
    //analogWrite(enB4, pwm);
    //digitalWrite(motor2pin1, LOW);
    //digitalWrite(motor2pin2, HIGH);
    //digitalWrite(motor3pin1, HIGH);
    //digitalWrite(motor3pin2, LOW);

  }



//=================================================== PAD BUTTON ==================================================
  //SELECT
  else if (ps2x.Button(PSB_SELECT))
  {
    myservo2.write(180);
  }

  //MOVE FORWARD
  else if (ps2x.Button(PSB_PAD_UP))
  {
    Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
    maju();
  }

  //MOVE RIGHT
  else if (ps2x.Button(PSB_PAD_RIGHT))
  {
    belokkanan();
    Serial.println(ps2x.Analog(PSB_PAD_RIGHT), DEC);      //move right
  }

  //MOVE LEFT
  else if (ps2x.Button(PSB_PAD_LEFT))
  {
    belokkiri();
    Serial.println(ps2x.Analog(PSB_PAD_LEFT), DEC);
  }

  //MOVE BACKWARD
  else if (ps2x.Button(PSB_PAD_DOWN))
  {
    mundur();
    Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
  }

  
//=======================================================  SERVO AX  ===================================================
  else if ((ps2x.Analog(PSS_RY) < 64) && ((ps2x.Analog(PSS_RX) >= 64) && (ps2x.Analog(PSS_RX) <= 192)))
  {
    myservo3.write(110);
    //ax12a.ledStatus(ID, OFF);
    //ax12a.turn(ID, RIGHT, 500);
  }
  else if ((ps2x.Analog(PSS_RY) > 192) && ((ps2x.Analog(PSS_RX) >= 64) && (ps2x.Analog(PSS_RX) <= 192)))
  {
    myservo3.write(75);
    //ax12a.ledStatus(ID, ON);
    //ax12a.turn(ID, LEFT, 500);
  }





//====================================================  STOP  ============================================================
  else
  {
    hop();
    //ax12a.turn(ID, LEFT, 0);
  }



//---------------------------------------------------  UWU  ------------------------------------------------------------
  if (LX != LXold || LY != LYold)
  {
    Serial.print("L Stick Values:");
    Serial.print(LY, DEC);
    Serial.print(",");
    Serial.println(LX, DEC);
  }
  if (RX != RXold || RY != RYold)
  {
    Serial.print("R Stick Values:");
    Serial.print(RY, DEC);
    Serial.print(",");
    Serial.println(RX, DEC);
  }

  LYold = LY;
  LXold = LX;
  RYold = RY;
  RXold = RX;
  
  delay(20);
}



//=========================================================  VOID  ===========================================================

void makan() {
  pwm = 100;
  analogWrite(enA1, pwm);
  //analogWrite(enB2, pwm);
  //analogWrite(enA3, pwm);
  analogWrite(enB4, pwm);
  digitalWrite(motor1pin1, LOW); //DEPAN
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
}

void makir() {
  pwm = 100;
  //analogWrite(enA1, pwm);
  analogWrite(enB2, pwm);
  analogWrite(enA3, pwm);
  //analogWrite(enB4, pwm);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
}

void mukir() {
  pwm = 100;
  analogWrite(enA1, pwm);
  //analogWrite(enB2, pwm);
  //analogWrite(enA3, pwm);
  analogWrite(enB4, pwm);
  digitalWrite(motor1pin1, HIGH); //DEPAN
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
}

void mukan() {
  pwm = 100;
  //analogWrite(enA1, pwm);
  analogWrite(enB2, pwm);
  analogWrite(enA3, pwm);
  //analogWrite(enB4, pwm);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
}

//----------------------------------------------  VOID PAD  -----------------------------------------------------
void maju() {
  pwm = 50;
  analogWrite(enA1, 125);
  analogWrite(enB2, 95);
  analogWrite(enA3, 105);
  analogWrite(enB4, 115);
  digitalWrite(motor1pin1, HIGH); //DEPAN
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
}

void mundur () {
  pwm = 100;
  analogWrite(enA1, 125);
  analogWrite(enB2, 95);
  analogWrite(enA3, 105);
  analogWrite(enB4, 115);
  digitalWrite(motor1pin1, LOW);  //BELAKANG
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);

  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
}

void belokkanan () {
  pwm = 100;
  analogWrite(enA1, 131);
  analogWrite(enB2, 101);
  analogWrite(enA3, 101);
  analogWrite(enB4, 111);
  digitalWrite(motor1pin1, HIGH); //KANAN
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);

  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);

}

void belokkiri () {
  analogWrite(enA1, 140);
  analogWrite(enB2, 105);
  analogWrite(enA3, 101);
  analogWrite(enB4, 111);
  digitalWrite(motor1pin1, LOW); //KIRI
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
}

void muter () {
  pwm = 130;
  analogWrite(enA1, pwm);
  analogWrite(enB2, pwm);
  analogWrite(enA3, pwm);
  analogWrite(enB4, pwm);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);

  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
}

void muterka () {
  pwm = 130;
  analogWrite(enA1, pwm);
  analogWrite(enB2, pwm);
  analogWrite(enA3, pwm);
  analogWrite(enB4, pwm);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
}

void hop () {
  analogWrite(enA1, 0);
  analogWrite(enB2, 0);
  analogWrite(enA3, 0);
  analogWrite(enB4, 0);
  digitalWrite(motor1pin1, LOW); //HENTI
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);

  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, LOW);
}
