void Doksan() {

  if (zemin)//zemine göre doksan
  {
    if (sensor[0] < 300 && sensor[1] < 300 && sensor[2] < 300 && sensor[3] < 300 && sensor[6] > 600 && sensor[7] > 600) {
      sagdoksan = 1;
      //en uçtaki sensorler birbirinden farklı görüyorsa 
      while (sagdoksan == 1) {
        PidRead();
        //kaymayı önlemek için fren yapar
        MotorSpeed((leftBaseSpeed  * -1.2) , (rightBaseSpeed * -1));
        delay((rightBaseSpeed + leftBaseSpeed) * 0.082);
        if (sensor[7] > 600 && sensor[6] > 600 && sensor[5] > 600  && sensor[2] > 600 && sensor[1] > 600 && sensor[0] > 600) {
          sagdoksan = 2;
          while (sagdoksan == 2) {
            PidRead();
            //çizgiyi bulana kadar çizginin olduğu tarafa doğru döner
            MotorSpeed((leftBaseSpeed  * 0.95) , (rightBaseSpeed * -0.45));
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
        MotorSpeed((leftBaseSpeed  * -1) , (rightBaseSpeed * -1.2));
        delay((rightBaseSpeed + leftBaseSpeed) * 0.082);
        if (sensor[7] > 600 && sensor[6] > 600 && sensor[5] > 600 &&  sensor[2] > 600 && sensor[1] > 600 && sensor[0] > 600) {
          soldoksan = 2;
          while (soldoksan == 2) {
            PidRead();
            MotorSpeed((leftBaseSpeed  * -0.45) , (rightBaseSpeed * 0.95));
            if (sensor[7] < 300 && sensor[6] < 300) {
              soldoksan = 0;

            }
          }
        }
      }
    }


  }

  else//zeminin else'i
  {
    if (sensor[0] > 600 && sensor[1] > 600 && sensor[2] > 600 && sensor[3] > 600 && sensor[6] < 300 && sensor[7] < 300) {
      sagdoksan = 1;
      while (sagdoksan == 1) {
        PidRead();
        MotorSpeed((leftBaseSpeed  * -1.2) , (rightBaseSpeed * -1.2));
        delay((rightBaseSpeed + leftBaseSpeed) * 0.082);
        if (sensor[7] < 300 && sensor[6] < 300 && sensor[5] < 300  && sensor[2] < 300 && sensor[1] < 300 && sensor[0] < 300) {
          sagdoksan = 2;
          while (sagdoksan == 2) {
            PidRead();
            MotorSpeed((leftBaseSpeed  * 0.95) , (rightBaseSpeed * -0.45));
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
        MotorSpeed((leftBaseSpeed  * -1) , (rightBaseSpeed * -1.2));
        delay((rightBaseSpeed + leftBaseSpeed) * 0.082);
        if (sensor[7] < 300 && sensor[6] < 300 && sensor[5] < 300 &&  sensor[2] < 300 && sensor[1] < 300 && sensor[0] < 300) {
          soldoksan = 2;
          while (soldoksan == 2) {
            PidRead();
            MotorSpeed((leftBaseSpeed  * -0.45) , (rightBaseSpeed * 0.95));
            if (sensor[0] > 600 && sensor[1] > 600) {
              soldoksan = 0;

            }
          }
        }
      }
    }


  }



}
