#pragma once
#include "Header.h"
#include "cTerapia.h"


class cBT :public cTerapia {
public: 
	cBT(eTamanio Tamanio);
	~cBT();
	float multiplicidadTerapia();
	float SetteoDox(eTamanio tamanio);

	const unsigned int DosMaxP=180; //dosis maxima paciente
	const unsigned int DosMaxT=150; //dosis maxima tumor
};
