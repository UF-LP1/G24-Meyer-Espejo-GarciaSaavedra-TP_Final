#pragma once
#include "Header.h"
#include"eUbicacion.h"
#include"eTamanio.h"
#include "eTratamiento.h"
class cTerapia {
public:
	cTerapia(eTratamiento tratamiento,eTamanio tamanio);
	~cTerapia();
	
	virtual float multiplicidadTerapia() = 0;
	eTratamiento get_expecificoTratamiento();
	virtual float SetteoDox(eTamanio tamanio)=0; //random calcula cual seria su dosis en base al tama�o y la terapia
	void set_dosisxSesion(float dosis);

protected:
	const eTratamiento tratamiento;
	float dosisxSesion; 
};

