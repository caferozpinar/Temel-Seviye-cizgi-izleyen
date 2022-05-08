#include <QTRSensors.h>

QTRSensors qtr;
#define sensorSayisi  8
//qtrdeki sensor sayısı
#define zemin 0
/*
  * siyah zemin "1"
  * beyaz zemin "0"
*/
int sensor[sensorSayisi];
int durum[8];


#define Kp 0.082
#define Kd 0.885
//PID çarpanları

#define rightBaseSpeed 120//120
#define leftBaseSpeed 120//120

#define rightMotor1 8
#define rightMotor2 9
#define rightMotorPWM 10
#define leftMotor1 6
#define leftMotor2 7
#define leftMotorPWM 5

#define rightMaxSpeed 255
#define leftMaxSpeed 255

int error = 0;
int lastError = 0;
int extraSpeed;
uint16_t say;
int sagdoksan = 0;
int soldoksan = 0;


void setup() {
  qtr.setTypeAnalog();//sensor tipi analog
  qtr.setSensorPins((const uint8_t[]) {
    A7, A6, A5, A4, A3, A2, A1, A0
  }, sensorSayisi);//sensor pinlleri
  //qtr.setEmitterPin(0);
  Serial.begin(9600);

  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); delay(120);
  digitalWrite(LED_BUILTIN, LOW); delay(120);
  digitalWrite(LED_BUILTIN, HIGH); delay(120);
  digitalWrite(LED_BUILTIN, LOW); delay(120);
  digitalWrite(LED_BUILTIN, HIGH); delay(1200);//kalibrasyona başlamadan led yanıp söner ve kalibre süresinde yanık kalır
  Kalibrasyon();
  digitalWrite(LED_BUILTIN, LOW); delay(120);//kalibrasyon bittiğinde yanıp söner ve sönük kalır.
  digitalWrite(LED_BUILTIN, HIGH); delay(120);
  digitalWrite(LED_BUILTIN, LOW); delay(3000);


}

void loop() {
  Pid();
  Doksan();
  Duz_Cizgi();
  //Kesik_Cizgi();
  //kesikli çizgi kodu çalışıyor gerektiğinde açılabilir.
}
