//==============================================  TOMBOL KANAN  ==================================================
void segitiga(int b) {

  analogWrite(enA1, b);
  analogWrite(enB2, b);
  analogWrite(enA3, b);
  analogWrite(enB4, b);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  Serial.print(" SEGITIGA DIPENCET ");
}

void cross() {
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

void lingkaran() {
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

void kotak() {
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



//==============================================  ANALOG KIRI  ==================================================
void analog_maju() {
  analogWrite(enA1, 255);
  analogWrite(enB2, 255);
  analogWrite(enA3, 255);
  analogWrite(enB4, 255);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
}

void analog_mundur() {
  analogWrite(enA1, 255);
  analogWrite(enB2, 255);
  analogWrite(enA3, 255);
  analogWrite(enB4, 255);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);

  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
}

void analog_kiri() {
  analogWrite(enA1, 255);
  analogWrite(enB2, 255);
  analogWrite(enA3, 255);
  analogWrite(enB4, 255);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
}

void analog_kanan() {
  analogWrite(enA1, 255);
  analogWrite(enB2, 255);
  analogWrite(enA3, 255);
  analogWrite(enB4, 255);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);

  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
}




//==============================================  TOMBOL KIRI  ==================================================
void maju() {
  analogWrite(enA1, 150);
  analogWrite(enB2, 150);
  analogWrite(enA3, 150);
  analogWrite(enB4, 150);
  digitalWrite(motor1pin1, HIGH); //DEPAN
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  Serial.print(" MAJU ");
}

void mundur () {
  analogWrite(enA1, 150);
  analogWrite(enB2, 150);
  analogWrite(enA3, 150);
  analogWrite(enB4, 150);
  digitalWrite(motor1pin1, LOW);  //BELAKANG
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);

  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
  Serial.print(" MUNDUR ");
}

void belokkanan () {
  analogWrite(enA1, 150);
  analogWrite(enB2, 150);
  analogWrite(enA3, 150);
  analogWrite(enB4, 150);
  digitalWrite(motor1pin1, HIGH); //KANAN
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);

  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  Serial.print(" KANAN ");
}

void belokkiri () {
  analogWrite(enA1, 150);
  analogWrite(enB2, 150);
  analogWrite(enA3, 150);
  analogWrite(enB4, 150);
  digitalWrite(motor1pin1, LOW); //KIRI
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
  Serial.print(" KIRI ");
}



//==============================================  ANALOG KANAN  ==================================================
void muterki() {
  analogWrite(enA1, 255);
  analogWrite(enB2, 255);
  analogWrite(enA3, 255);
  analogWrite(enB4, 255);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
}


void muterka () {
  analogWrite(enA1, 255);
  analogWrite(enB2, 255);
  analogWrite(enA3, 255);
  analogWrite(enB4, 255);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);

  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
}




//==============================================  ANALOG KIRI DIAGONAL  ==================================================
void makir() {
  //analogWrite(enA1, pwm);
  analogWrite(enB2, 130);
  analogWrite(enA3, 130);
  //analogWrite(enB4, pwm);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
}

void makan() {
  analogWrite(enA1, 130);
  //analogWrite(enB2, pwm);
  //analogWrite(enA3, pwm);
  analogWrite(enB4, 130);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
}

void mukir() {
  analogWrite(enA1, 130);
  //analogWrite(enB2, pwm);
  //analogWrite(enA3, pwm);
  analogWrite(enB4, 130);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
}

void mukan() {
  //analogWrite(enA1, pwm);
  analogWrite(enB2, 130);
  analogWrite(enA3, 130);
  //analogWrite(enB4, pwm);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
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
