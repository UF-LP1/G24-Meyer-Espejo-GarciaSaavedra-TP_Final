#pragma once
#include "cTumor.h"
#include "eUbicacion.h"
#include "eTamanio.h"

class cTumor {
public:
	cTumor();
	~cTumor();
	void set_AcumRadiacion(int radiacion);
	int get_AcumRadiacion();
	eUbicacion get_Ubicacion();
	void set_Ubicacion(eUbicacion ubicacion);
	eTamanio get_Tamanio();
	void set_Tamanio(eTamanio tamanio);
	bool get_bedigno();
	void set_bedigno(bool Sano);

private:
	eUbicacion Ubicacion;
	eTamanio Tamanio;
	int AcumRadiacion;
	bool bedigno;
};