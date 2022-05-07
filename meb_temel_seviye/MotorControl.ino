
  void RightForward(int c){
  analogWrite(rightMotorPWM,c);
  digitalWrite(rightMotor1,1);
  digitalWrite(rightMotor2,0);
}

void RightBack(int c){
  analogWrite(rightMotorPWM,c);
  digitalWrite(rightMotor1,0);
  digitalWrite(rightMotor2,1);
}

void LeftForward(int c){
  analogWrite(leftMotorPWM,c);
  digitalWrite(leftMotor1,1);
  digitalWrite(leftMotor2,0);
}

void LeftBack(int c){
  analogWrite(leftMotorPWM,c);
  digitalWrite(leftMotor1,0);
  digitalWrite(leftMotor2,1);
}
