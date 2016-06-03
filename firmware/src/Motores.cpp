// 
// 
// 

#include "Motores.h"


/** Constructor with the pwm parameters
* \param pwmA Valor de calibracion para el motor A
* \param pwmB Valor de calibracion para el motor B
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

Motores::~Motores()
{
}

void Motores::begin()
{
	//Inicialización de pines
	pinMode(pinPWM_A, OUTPUT);
	pinMode(pinAIN1, OUTPUT);
	pinMode(pinAIN2, OUTPUT);

	pinMode(pinPWM_B, OUTPUT);
	pinMode(pinBIN1, OUTPUT);
	pinMode(pinBIN2, OUTPUT);

	configurar(255, 255);	//Inicializa a full PWM
}

void Motores::configurarA(int pwm)
{
	pwm_motorA = pwm;
}

int Motores::retroA()
{
	return pwm_motorA;
}

void Motores::configurarB(int pwm)
{
	pwm_motorB = pwm;
}

int Motores::retroB()
{
	return pwm_motorB;
}

void Motores::configurar(int pwmA, int pwmB)
{
	configurarA(pwmA);	//Asigna el pwm del motor A
	configurarB(pwmB);	//Asigna el pwm del motor B

}


void Motores::avanza()
{
	//Acciona el motor A hacia adelante con el PWM definido para A
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2, LOW);
	analogWrite(PWM_A, retroA());

	//Acciona el motor B hacia adelante con el PWM definido para B
	digitalWrite(BIN1, HIGH);
	digitalWrite(BIN2, LOW);
	analogWrite(PWM_B, retroB());
}

void Motores::retrocede()
{
	//Acciona el motor A hacia atrás con el PWM definido para A
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, HIGH);
	analogWrite(PWM_A, retroA());

	//Acciona el motor B hacia atrás con el PWM definido para B
	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, HIGH);
	analogWrite(PWM_B, retroB());
}

void Motores::detiene()
{
	//Acciona el motor A hacia atrás con el PWM definido para A
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, LOW);
	analogWrite(PWM_A, retroA());

	//Acciona el motor B hacia atrás con el PWM definido para B
	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, LOW);
	analogWrite(PWM_B, retroB());
}

void Motores::girarIzq()
{
	int valA = map(MUCHO, 0, 100, 0, retroA());
	int valB = map(POCO, 0, 100, 0, retroB());

	//Acciona el motor A hacia adelante con el PWM definido por el mapeo MUCHO
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2, LOW);
	analogWrite(PWM_A, valA);

	//Acciona el motor B hacia atrás con el PWM definido por el mapeo POCO
	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, HIGH);
	analogWrite(PWM_B, valB);
}

void Motores::girarDer()
{
	int valA = map(POCO, 0, 100, 0, retroA());
	int valB = map(MUCHO, 0, 100, 0, retroB());
	
	//Acciona el motor A hacia adelante con el PWM definido por el mapeo POCO
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, HIGH);
	analogWrite(PWM_A, valA);

	//Acciona el motor B hacia atrás con el PWM definido por el mapeo MUCHO
	digitalWrite(BIN1, HIGH);
	digitalWrite(BIN2, LOW);
	analogWrite(PWM_B, valB);
}

/* Cambiar val y mapeo a ValIzq Mucho valderpoco, valdermucho*/