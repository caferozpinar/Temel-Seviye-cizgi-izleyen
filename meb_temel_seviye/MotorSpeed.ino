void MotorSpeed(int c, int s){
  //max 250 pwm
  if(c > 255)c=250;
  if(s > 255)s=250;
  if(c < -255)c=-255;
  if(s < -255)s=-255;


  if(c>0){
    analogWrite(leftMotorPWM,c);
    digitalWrite(leftMotor1,1);
    digitalWrite(leftMotor2,0);
  }
  else if (c==-1){
    analogWrite(leftMotorPWM,0);
    digitalWrite(leftMotor1,1);
    digitalWrite(leftMotor2,1);
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
  else if(s==-1){
    analogWrite(rightMotorPWM,0);
    digitalWrite(rightMotor1,1);
    digitalWrite(rightMotor2,1);
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
