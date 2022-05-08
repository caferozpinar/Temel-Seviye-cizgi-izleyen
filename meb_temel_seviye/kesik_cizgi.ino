void Kesik_Cizgi() {

  if (zemin)
  {
    if (sensor[0] > 600 && sensor[1] > 600 && sensor[2] > 600 && sensor[3] > 600 && sensor[4] > 600 && sensor[5] > 600 && sensor[6] > 600 && sensor[7] > 600 ) {
      while (1) {
        PidRead();
        MotorSpeed((leftBaseSpeed * 1) , (rightBaseSpeed * 1));
        if (sensor[0] < 300 || sensor[1] < 300 || sensor[2] < 300 || sensor[3] < 300 || sensor[4] < 300 || sensor[5] < 300 || sensor[6] < 300 || sensor[7] < 300) {
          break;
        }
      }
    }
  }
  else
  {
    if (sensor[0] < 300 && sensor[1] < 300 && sensor[2] < 300 && sensor[3] < 300 && sensor[4] < 300 && sensor[5] < 300 && sensor[6] < 300 && sensor[7] < 300 ) {
      while (1) {
        PidRead();
        MotorSpeed((leftBaseSpeed * 1) , (rightBaseSpeed * 1));
        if (sensor[0] > 600 || sensor[1] > 600 || sensor[2] > 600 || sensor[3] > 600 || sensor[4] > 600 || sensor[5] > 600 || sensor[6] > 600 || sensor[7] > 600) {
          break;
        }
      }
    }
  }





}
