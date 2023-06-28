#include "cBT.h"





cBT::cBT(eTamanio Tamanio):cTerapia(branquiterapia,Tamanio)
{
	
}



cBT::~cBT()
{
}

float cBT::multiplicidadTerapia()
{
	return (0.6);
}

float cBT::SetteoDox(eTamanio tamanio)
{
	//dosis normal por sesión varía de 6 a 8 Gy

	srand(time(NULL));
	float dosis = 0;
	//random valor max 6
	//random min 5
	float aux =float (rand()%6+ 5); //con random
	if (tamanio == pequenio){
		
		dosis = aux + 1;
	}
	else if (tamanio == mediano) {
		dosis = aux + 1.4;
	}
	else if (tamanio == grande)
		dosis = aux + 2;

	return dosis;
}

