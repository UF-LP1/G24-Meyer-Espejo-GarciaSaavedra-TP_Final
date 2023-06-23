#pragma once
#include "Header.h"
#include"eUbicacion.h"
#include"eTamanio.h"
#include "eTratamiento.h"
class cTerapia {
public:
	cTerapia();
	~cTerapia();
	
	void set_frecuencia(int frecue);
	int get_frecuencia();
	virtual float multiplicidadTerapia() = 0;
	eTratamiento get_expecificoTratamiento();

protected:
	int frecuencia_semanal;
	eTratamiento tratamiento;
};

