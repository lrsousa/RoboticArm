#include <Servo.h>

Servo motorBase;
Servo motorArt1;
Servo motorArt2;
Servo motorGarra;

int const servoMotorPinBase = 9;
int const servoMotorPinArt1 = 6;
int const servoMotorPinArt2 = 5;
int const servoMotorPinGarra = 3;

int const potenciometroPinBase = 3;
int valPotenciometroBase;
int const potenciometroPinArt1 = 2;
int valPotenciometroArt1;
int const potenciometroPinArt2 = 1;
int valPotenciometroArt2;
int const potenciometroPinGarra = 0;
int valPotenciometroGarra;

void setup()
{
  Serial.begin(9600);
  motorBase.attach(servoMotorPinBase);
  motorBase.write(61);
  delay(100);
  motorArt1.attach(servoMotorPinArt1);
  motorArt1.write(15);
  delay(100);
  motorArt2.attach(servoMotorPinArt2);
  motorArt2.write(15);
  motorGarra.attach(servoMotorPinGarra);
  motorGarra.write(130);
  delay(2000);
}
void loop()
{
  int antBase = valPotenciometroBase;
  int antArt1 = valPotenciometroArt1;
  int antArt2 = valPotenciometroArt2;
  int antGarra = valPotenciometroGarra;

  //Leitura Pot Base
  valPotenciometroBase = analogRead(potenciometroPinBase);
  valPotenciometroBase = map(valPotenciometroBase, 0, 1023, 0, 180);
  if (valPotenciometroBase != antBase) {
    if (valPotenciometroBase < 13) {
      motorBase.write(13);
    } else if (valPotenciometroBase > 110) {
      motorBase.write(110);
    } else {
      motorBase.write(valPotenciometroBase);
    }
  }

  //Leitura Pot Art1
  valPotenciometroArt1 = analogRead(potenciometroPinArt1);
  valPotenciometroArt1 = map(valPotenciometroArt1, 0, 1023, 0, 180);
  if (valPotenciometroArt1 != antArt1) {
    if (valPotenciometroArt1 < 10) {
      motorArt1.write(10);
    } else if (valPotenciometroArt1 > 95) {
      motorArt1.write(95);
    } else {
      motorArt1.write(valPotenciometroArt1);
    }
  }

  //Leitura Pot Art2
  valPotenciometroArt2 = analogRead(potenciometroPinArt2);
  valPotenciometroArt2 = map(valPotenciometroArt2, 0, 1023, 0, 180);
  if (valPotenciometroArt2 != antArt2) {
    if (valPotenciometroArt2 < 15) {
      motorArt2.write(15);
    } else if (valPotenciometroArt2 > 90) {
      motorArt2.write(90);
    } else {
      motorArt2.write(valPotenciometroArt2);
    }
  }

  //Leitura Pot Garra
  valPotenciometroGarra = analogRead(potenciometroPinGarra);
  valPotenciometroGarra = map(valPotenciometroGarra, 0, 1023, 0, 180);
  if (valPotenciometroGarra != antGarra) {
    if (valPotenciometroGarra < 115) {
      motorGarra.write(115);
    } else if (valPotenciometroGarra > 150) {
      motorGarra.write(150);
    } else {
      motorGarra.write(valPotenciometroGarra);
    }
  }

  Serial.println("Base: " + valPotenciometroBase);
  Serial.println("Pot1: " + valPotenciometroArt1);
  Serial.println("Pot2: " + valPotenciometroArt2);
  Serial.println("Garra: " + valPotenciometroArt2);
  delay(15);
}
