#pragma once
#include "Header.h"
#include "cTerapia.h"

class cRS :public cTerapia {
public: 
	cRS(eTamanio TAmanio);
	~cRS();
	float multiplicidadTerapia(); 
	float SetteoDox(eTamanio tamanio);
	string to_string();

	const unsigned int DosMaxP=100; //dosis maxima paciente
	const unsigned int DosMaxT=60; //dosis maxima tumor
};
