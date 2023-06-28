#pragma once
#include "Header.h"
#include "cTerapia.h"

class cRTH :public cTerapia {
	
public:
	cRTH(eTamanio TAmanio);
	~cRTH();
	float multiplicidadTerapia();
	float SetteoDox(eTamanio tamanio);

	const unsigned int DosMaxP=100; //dosis maxima paciente
	const unsigned int DosMaxT = 60;; //dosis maxima tumor
};
