#include "cRTH.h"



cRTH::~cRTH()
{}

cRTH::cRTH(eTamanio TAmanio):cTerapia(hazExterno, TAmanio)
{
}



float cRTH::multiplicidadTerapia()
{
	return (0.3);
}

float cRTH::SetteoDox(eTamanio tamanio)
{
	
	//dosis normal entre 1 y 2 GY
	//minimo 100
//maximo 50

	float aux = float(rand() % 100 + 50); //con random
	float dosis = 0;

		if (tamanio == pequenio) {

			dosis = aux + 50;
		}
		else if (tamanio == mediano) {
			dosis = aux + 75;
		}
		else if (tamanio == grande)
			dosis = aux + 100;

		return (dosis / 100);
	

}


