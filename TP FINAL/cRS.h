#pragma once
#include "Header.h"
#include "cTerapia.h"

class cRS :public cTerapia {
public: 
	cRS(eTamanio TAmanio, eUbicacion UBicacion);
	cRS();
	~cRS();
	float multiplicidadTerapia(); 

	const unsigned int DosMaxP; //dosis maxima paciente
	const unsigned int DosMaxT; //dosis maxima tumor
};
