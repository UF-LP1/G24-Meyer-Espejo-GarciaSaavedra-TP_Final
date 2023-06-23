#pragma once
#include "Header.h"
#include "cTerapia.h"

class cRTH :public cTerapia {
	
public:
	cRTH(eTamanio TAmanio, eUbicacion UBicacion);
	cRTH();
	~cRTH();
	float multiplicidadTerapia();

	const unsigned int DosMaxP; //dosis maxima paciente
	const unsigned int DosMaxT; //dosis maxima tumor
};