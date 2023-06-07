#pragma once
#include "cTumor.h"
#include "eUbicacion.h"
#include "eTamanio.h"

class cTumor {
public:
	cTumor();
	~cTumor();
	void set_AcumRadiacion(int radiacion);
	eUbicacion get_Ubicacion();
	void set_Ubicacion(eUbicacion ubicacion);
	eTamanio get_Tamanio();
	void set_Tamanio(eTamanio tamanio);


private:
	eUbicacion Ubicacion;
	eTamanio Tamanio;
	int AcumRadiacion:
};