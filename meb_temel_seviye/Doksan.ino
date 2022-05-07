void Doksan() {

  if (zemin)
  {
    if (sensor[0] < 300 && sensor[1] < 300 && sensor[2] < 300 && sensor[3] < 300 && sensor[6] > 600 && sensor[7] > 600) {
      sagdoksan = 1;
      while (sagdoksan == 1) {
        PidRead();
        MotorSpeed(-50, -50);
        if (sensor[7] > 600 && sensor[6] > 600 && sensor[5] > 600  && sensor[2] > 600 && sensor[1] > 600 && sensor[0] > 600) {
          sagdoksan = 2;
          while (sagdoksan == 2) {
            PidRead();
            MotorSpeed(80, -60);
            if (sensor[0] < 300 && sensor[1] < 300) {
              sagdoksan = 0;

            }
          }
        }
      }
    }


    if (sensor[7] < 300 && sensor[6] < 300 && sensor[5] < 300 && sensor[4] < 300 && sensor[1] > 600 && sensor[0] > 600) {
      soldoksan = 1;
      while (soldoksan == 1) {
        PidRead();
        MotorSpeed(-50, -50);
        if (sensor[7] > 600 && sensor[6] > 600 && sensor[5] > 600 &&  sensor[2] > 600 && sensor[1] > 600 && sensor[0] > 600) {
          soldoksan = 2;
          while (soldoksan == 2) {
            PidRead();
            MotorSpeed(-60, 80);
            if (sensor[7] < 300 && sensor[6] < 300) {
              soldoksan = 0;

            }
          }
        }
      }
    }


  }

  else
  {
    if (sensor[0] > 600 && sensor[1] > 600 && sensor[2] > 600 && sensor[3] > 600 && sensor[6] < 300 && sensor[7] < 300) {
      sagdoksan = 1;
      while (sagdoksan == 1) {
        PidRead();
        MotorSpeed(-50, -50);
        if (sensor[7] < 300 && sensor[6] < 300 && sensor[5] < 300  && sensor[2] < 300 && sensor[1] < 300 && sensor[0] < 300) {
          sagdoksan = 2;
          while (sagdoksan == 2) {
            PidRead();
            MotorSpeed(80, -60);
            if (sensor[0] > 600 && sensor[1] > 600) {
              sagdoksan = 0;

            }
          }
        }
      }
    }


    if (sensor[7] > 600 && sensor[6] > 600 && sensor[5] > 600 && sensor[4] > 600 && sensor[1] < 300 && sensor[0] < 300) {
      soldoksan = 1;
      while (soldoksan == 1) {
        PidRead();
        MotorSpeed(-50, -50);
        if (sensor[7] < 300 && sensor[6] < 300 && sensor[5] < 300 &&  sensor[2] < 300 && sensor[1] < 300 && sensor[0] < 300) {
          soldoksan = 2;
          while (soldoksan == 2) {
            PidRead();
            MotorSpeed(-60, 80);
            if (sensor[7] > 600 && sensor[6] > 600) {
              soldoksan = 0;

            }
          }
        }
      }
    }


  }



}
