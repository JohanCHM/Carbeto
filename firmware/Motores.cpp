// 
// 
// 

#include "Motores.h"

/** Constructor with the pins for the motors
* \param pwmA pin pwm del motor A
* \param motA1 pin 1 del motor A
* \param motA2 pin 2 del motor A
* \param pwmB pin pwm del motor B
* \param motB1 pin 1 del motor A
* \param motB2 pin 2 del motor A
*/
Motores::Motores(int pwmA, int motA1, int motA2, int pwmB, int motB1, int motB2)
{
	//Define los pines de salida para el motor A
	pinPWM_A = pwmA;
	pinAIN1 = motA1;
	pinAIN2 = motA2;

	//Define los pines de salida para el motor A
	pinPWM_B = pwmB;
	pinBIN1 = motB1;
	pinBIN2 = motB2;

}


/** Inicializa los motores */
void Motores::begin()
{
	//Inicialización de pines
	pinMode(pinPWM_A, OUTPUT);
	pinMode(pinAIN1, OUTPUT);
	pinMode(pinAIN2, OUTPUT);

	pinMode(pinPWM_B, OUTPUT);
	pinMode(pinBIN1, OUTPUT);
	pinMode(pinBIN2, OUTPUT);

	configurar(254, 254);	//Inicializa a full PWM
}

/** Configurar el pwm del motor A
* \param pwmA Valor de calibracion para el motor A
*/
void Motores::configurarA(int pwm)
{
	pwm_motorA = pwm;
	valAPoco = map(POCO, 0, 100, 0, pwm);
	valAMucho = map(MUCHO, 0, 100, 0, pwm);
}

/** Regresa el valor del pwm del motor A
* \return pwmA Valor de calibracion para el motor A
*/
int Motores::retroA()
{
	return pwm_motorA;
}

/** Configurar el pwm del motor B
* \param pwmB Valor de calibracion para el motor B
*/
void Motores::configurarB(int pwm)
{
	pwm_motorB = pwm;
	valBPoco = map(POCO, 0, 100, 0, pwm);
	valBMucho = map(MUCHO, 0, 100, 0, pwm);
}

/** Regresa el valor del pwm del motor B
* \return pwmB Valor de calibracion para el motor B
*/
int Motores::retroB()
{
	return pwm_motorB;
}

/** Configurar el pwm tanto del motor A como del motor B
* \param pwmA Valor de calibracion para el motor A
* \param pwmB Valor de calibracion para el motor B
*/
void Motores::configurar(int pwmA, int pwmB)
{
	configurarA(pwmA);	//Asigna el pwm del motor A
	configurarB(pwmB);	//Asigna el pwm del motor B

}

/** Mueve los dos motores hacia adelante */
void Motores::avanza()
{
	//Acciona el motor A hacia adelante con el PWM definido para A
	digitalWrite(pinAIN1, HIGH);
	digitalWrite(pinAIN2, LOW);
	analogWrite(pinPWM_A, retroA());

	//Acciona el motor B hacia adelante con el PWM definido para B
	digitalWrite(pinBIN1, HIGH);
	digitalWrite(pinBIN2, LOW);
	analogWrite(pinPWM_B, retroB());
}

/** Mueve los dos motores hacia adelante */
void Motores::retrocede()
{
	//Acciona el motor A hacia atrás con el PWM definido para A
	digitalWrite(pinAIN1, LOW);
	digitalWrite(pinAIN2, HIGH);
	analogWrite(pinPWM_A, retroA());

	//Acciona el motor B hacia atrás con el PWM definido para B
	digitalWrite(pinBIN1, LOW);
	digitalWrite(pinBIN2, HIGH);
	analogWrite(pinPWM_B, retroB());
}

/** Detiene los motores */
void Motores::detiene()
{
	//Acciona el motor A hacia atrás con el PWM definido para A
	digitalWrite(pinAIN1, LOW);
	digitalWrite(pinAIN2, LOW);
	analogWrite(pinPWM_A, retroA());

	//Acciona el motor B hacia atrás con el PWM definido para B
	digitalWrite(pinBIN1, LOW);
	digitalWrite(pinBIN2, LOW);
	analogWrite(pinPWM_B, retroB());
}

/** Gira a la Izquierda */
void Motores::girarIzq()
{
	//Acciona el motor A hacia adelante con el PWM definido por el mapeo MUCHO
	digitalWrite(pinAIN1, HIGH);
	digitalWrite(pinAIN2, LOW);
	analogWrite(pinPWM_A, valAMucho);

	//Acciona el motor B hacia atrás con el PWM definido por el mapeo POCO
	digitalWrite(pinBIN1, LOW);
	digitalWrite(pinBIN2, HIGH);
	analogWrite(pinPWM_B, valBPoco);
}

/** gira a la Derecha*/
void Motores::girarDer()
{
	//Acciona el motor A hacia adelante con el PWM definido por el mapeo POCO
	digitalWrite(pinAIN1, LOW);
	digitalWrite(pinAIN2, HIGH);
	analogWrite(pinPWM_A, valAPoco);

	//Acciona el motor B hacia atrás con el PWM definido por el mapeo MUCHO
	digitalWrite(pinBIN1, HIGH);
	digitalWrite(pinBIN2, LOW);
	analogWrite(pinPWM_B, valBMucho);
}

