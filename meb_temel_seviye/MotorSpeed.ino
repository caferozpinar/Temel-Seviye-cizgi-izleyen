void MotorSpeed(int c, int s){



  if(c>0){
    analogWrite(leftMotorPWM,c);
    digitalWrite(leftMotor1,1);
    digitalWrite(leftMotor2,0);
  }
  else if(c<0){
    analogWrite(leftMotorPWM,abs(c));
    digitalWrite(leftMotor1,0);
    digitalWrite(leftMotor2,1);
  }
  else if(c==0){
    analogWrite(leftMotorPWM,0);
    digitalWrite(leftMotor1,0);
    digitalWrite(leftMotor2,0);
  }

  if(s>0){
    analogWrite(rightMotorPWM,s);
    digitalWrite(rightMotor1,1);
    digitalWrite(rightMotor2,0);
  }
  else if(s<0){
    analogWrite(rightMotorPWM,abs(s));
    digitalWrite(rightMotor1,0);
    digitalWrite(rightMotor2,1);
  }
  else if(s==0){
    analogWrite(rightMotorPWM,0);
    digitalWrite(rightMotor1,0);
    digitalWrite(rightMotor2,0);
  }
}
