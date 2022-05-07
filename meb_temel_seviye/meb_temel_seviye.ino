#include <QTRSensors.h>

QTRSensors qtr;
#define sensorSayisi  8
#define zemin 0
/*
  * siyah zemin "1"
  * beyaz zemin "0"
*/
int sensor[sensorSayisi];
int durum[8];


#define Kp 0.082
#define Kd 0.885
#define rightBaseSpeed 70//150
#define leftBaseSpeed 70//150

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
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]) {
    A7, A6, A5, A4, A3, A2, A1, A0
  }, sensorSayisi);
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
  digitalWrite(LED_BUILTIN, HIGH); delay(1200);
  Kalibrasyon();
  digitalWrite(LED_BUILTIN, LOW); delay(120);
  digitalWrite(LED_BUILTIN, HIGH); delay(120);
  digitalWrite(LED_BUILTIN, LOW); delay(3000);


}

void loop() {
  Pid();
  Doksan();
  Duz_Cizgi();

}
