#include <PS2X_lib.h>
int pwm;

#define enA1 5
#define enB2 6
#define enA3 7
#define enB4 2

#define motor1pin1 3
#define motor1pin2 4
#define motor2pin1 7
#define motor2pin2 8
#define motor3pin1 1
#define motor3pin2 9
#define motor4pin1 A4
#define motor4pin2 A5
PS2X ps2x;

int error = 0;
byte type = 0;
byte vibrate = 0;
int LY, LX, RY, RX, LYold, LXold, RYold, RXold;

int save=0;

//============================================== SERVO ======================================================
//#include <AX12A.h>
//#define DirectionPin  (10u)
//#define BaudRate    (1000000ul)
//#define ID    12

#include <Servo.h>
Servo myservo1; //-----> Capit
Servo myservo2; //-----> Putar
Servo myservo3; //-----> Naik Turun
