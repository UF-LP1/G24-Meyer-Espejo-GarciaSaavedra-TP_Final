#pragma once
#include "Header.h"
#include"eUbicacion.h"
#include"eTamanio.h"
#include "eTratamiento.h"
class cTerapia {
public:
	cTerapia();
	~cTerapia();
	unsigned int get_DosisMaxP();
	unsigned int get_DosisMaxt();
	void set_DosisMaxP(unsigned int dosisP);
	void set_DosisMaxt(unsigned int dosisT);
	virtual float multiplicidadTerapia() = 0;
	eTratamiento get_expecificoTratamiento();

protected:
	unsigned int DosMaxP; //dosis maxima paciente
	unsigned int DosMaxT; //dosis maxima tumor
	eTratamiento tratamiento;


};

