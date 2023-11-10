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



  //=============================================  PEMBACAAN STIK  ====================================================
  ps2x.read_gamepad(false, vibrate);

  //SEGITIGA
  if (ps2x.Button(PSB_TRIANGLE))
  {
    save += 10;
    if (save >= 1) {
      segitiga(50 + save);
    }
    if (save > 204) {
      segitiga(255);
    }

  }

  //X
  else if (ps2x.Button(PSB_CROSS))
  {
    cross();
  }



  //========================================================     SERVO     ===============================================================
  //------  CAPIT  ------
  else if (ps2x.Button(PSB_R1))
  {
    myservo1.write(40);
  }
  else if (ps2x.Button(PSB_R2))
  {
    myservo1.write(115);
  }

  //------  PUTAR  ------
  else if (ps2x.Button(PSB_L2 ))
  {
    myservo2.write(0);
  }

  else if (ps2x.Button(PSB_L1))
  {
    myservo2.write(83);
  }

  //------  NAIK TURUN  ------
  else if ((ps2x.Analog(PSS_RY) < 64) && ((ps2x.Analog(PSS_RX) >= 64) && (ps2x.Analog(PSS_RX) <= 192)))
  {
    myservo3.write(50);//atas
  }
  else if ((ps2x.Analog(PSS_RY) > 192) && ((ps2x.Analog(PSS_RX) >= 64) && (ps2x.Analog(PSS_RX) <= 192)))
  {
    myservo3.write(37); //bawah
  }



  //BULET
  else if (ps2x.Button(PSB_CIRCLE))
  {
    lingkaran();
  }

  //KOTAK
  else if (ps2x.Button(PSB_SQUARE))
  {
    kotak();
  }


  //======================================================    ANALOG KIRI   ================ ================================================
  //move forward ANALOG
  else if ((ps2x.Analog(PSS_LY) < 64) && ((ps2x.Analog(PSS_LX) >= 64) && (ps2x.Analog(PSS_LX) <= 192)))
  {
    analog_maju();
  }

  //move backward ANALOG
  else if ((ps2x.Analog(PSS_LY) > 192) && ((ps2x.Analog(PSS_LX) >= 64) && (ps2x.Analog(PSS_LX) <= 192)))
  {
    analog_mundur();
  }

  //move left ANALOG
  else if ((ps2x.Analog(PSS_LX) < 64) && ((ps2x.Analog(PSS_LY) >= 64) && (ps2x.Analog(PSS_LY) <= 192)))
  {
    analog_kiri();
  }

  //move right ANALOG
  else if ((ps2x.Analog(PSS_LX) > 192) && ((ps2x.Analog(PSS_LY) >= 64) && (ps2x.Analog(PSS_LY) <= 192)))
  {
    analog_kanan();
  }


  //====================================================    ANALOG KANAN    ====================================================================
  else if ((ps2x.Analog(PSS_RX) < 64) && ((ps2x.Analog(PSS_RY) >= 64) && (ps2x.Analog(PSS_RY) <= 192)))
  {
    muterka();
  }
  else if ((ps2x.Analog(PSS_RX) > 192) && ((ps2x.Analog(PSS_RY) >= 64) && (ps2x.Analog(PSS_RY) <= 192)))
  {
    muterki();
  }




  //====================================================     ANALOG KIRI DIAGONAL    ============================================================
  //MAJU KIRI
  else if ((ps2x.Analog(PSS_LY) < 50) && ((ps2x.Analog(PSS_LX) >= 0) && (ps2x.Analog(PSS_LX) <= 50)))
  {
    makir();
  }

  //MAJU KANAN
  else if ((ps2x.Analog(PSS_LY) < 64) && ((ps2x.Analog(PSS_LX) >= 200) && (ps2x.Analog(PSS_LX) <= 255)))
  {
    makan();
  }

  //MUNDUR KIRI
  else if ((ps2x.Analog(PSS_LY) < 257) && ((ps2x.Analog(PSS_LX) >= 0) && (ps2x.Analog(PSS_LX) <= 64)))
  {
    mukir();
  }

  //MUNDUR KANAN
  else if ((ps2x.Analog(PSS_LY) > 220) && ((ps2x.Analog(PSS_LX) >= 200) && (ps2x.Analog(PSS_LX) <= 255)))
  {
    mukan();
  }




//=================================================================    PAD TENGAH    ===============================================================
  //SELECT
  else if (ps2x.Button(PSB_SELECT))
  {
    
  }

  //START
  else if (ps2x.Button(PSB_START))
  {
    myservo1.write(40);
    myservo2.write(81);
    myservo3.write(35);
  }




//=================================================================    PAD KIRI    ===============================================================
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
    Serial.println(ps2x.Analog(PSB_PAD_RIGHT), DEC);
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



  //  //====================================================  SERVO AX  ===================================================
  //  else if ((ps2x.Analog(PSS_RY) < 64) && ((ps2x.Analog(PSS_RX) >= 64) && (ps2x.Analog(PSS_RX) <= 192)))
  //  {
  //    myservo3.write(0);
  //    //ax12a.ledStatus(ID, OFF);
  //    //ax12a.turn(ID, RIGHT, 500);
  //  }
  //  else if ((ps2x.Analog(PSS_RY) > 192) && ((ps2x.Analog(PSS_RX) >= 64) && (ps2x.Analog(PSS_RX) <= 192)))
  //  {
  //    myservo3.write(20);
  //    //ax12a.ledStatus(ID, ON);
  //    //ax12a.turn(ID, LEFT, 500);
  //  }





  //==================================================================   STOP   ==================================================================
  else
  {
    save = 0;
    hop();
    //ax12a.turn(ID, LEFT, 0);
  }





  //------------------------------------------------------------------  UWU  ------------------------------------------------------------------------
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
