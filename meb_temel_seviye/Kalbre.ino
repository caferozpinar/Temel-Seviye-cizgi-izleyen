void Kalibrasyon() {
  for (int i = 0; i < 200; i++)//20 defa sensörler kalibre ediliyor
  {
    qtr.calibrate();
  }
}
void Kalibre() {

  //  Serial.println(error);
  int left = 0, right = 0;
  for (int calibrationCase = 0; calibrationCase < 7; calibrationCase++) {
    while (analogRead(A0) > 600) {
      qtr.calibrate();
      MotorSpeed(65, -65);
    }
    while (analogRead(A7) > 600) {
      qtr.calibrate();
      MotorSpeed(-65, 65);
    }
  }

  while (1) {
    MotorSpeed(65, -65);
    if ( (analogRead(A3) < 250 && analogRead(A4) < 250) || (analogRead(A5) < 250 && analogRead(A4) < 250)  ) {
      MotorSpeed(0, 0);
      delay(500);
      break;
    }
  }


}
