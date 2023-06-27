#pragma once
#include "Header.h"
#include"eUbicacion.h"
#include"eTamanio.h"
#include "eTratamiento.h"
class cTerapia {
public:
	cTerapia();
	~cTerapia();
	
	virtual float multiplicidadTerapia() = 0;
	eTratamiento get_expecificoTratamiento();

protected:
	eTratamiento tratamiento;
};

