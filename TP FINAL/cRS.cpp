#include "cRS.h"


cRS::cRS(eTamanio TAmanio):cTerapia(sistematica,TAmanio)
{
}

cRS::~cRS()
{
}

float cRS::multiplicidadTerapia()
{
	return (0.1);
}

float cRS::SetteoDox(eTamanio tamanio)
{
	//2 a 4 Gy
		//maximo 150
		//minimo 50
		float aux = float(rand() % 150 + 50); //con random
		float dosis = 0;
		if (tamanio == pequenio) {

			dosis = aux + 150;
		}
		else if (tamanio == mediano) {
			dosis = aux + 175;
		}
		else if (tamanio == grande)
			dosis = aux + 200;

		return(dosis / 100);
	
}


