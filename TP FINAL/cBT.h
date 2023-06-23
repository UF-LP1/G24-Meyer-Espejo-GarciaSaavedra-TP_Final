#pragma once
#include "Header.h"
#include "cTerapia.h"


class cBT :public cTerapia {
public: 
	cBT(eTamanio TAmanio,eUbicacion UBicacion);
	cBT();
	~cBT();
	float multiplicidadTerapia();

	const unsigned int DosMaxP; //dosis maxima paciente
	const unsigned int DosMaxT; //dosis maxima tumor
};
