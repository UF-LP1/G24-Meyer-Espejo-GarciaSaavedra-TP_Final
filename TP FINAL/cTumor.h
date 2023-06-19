#pragma once
#include "cTumor.h"
#include "eUbicacion.h"
#include "eTamanio.h"

class cTumor {
public:
	cTumor(eUbicacion ubicacion, eTamanio tamanio, int acumRadiacion, bool Benigno);
	~cTumor();
	void set_AcumRadiacion(int radiacion);
	int get_AcumRadiacion();
	eUbicacion get_Ubicacion();
	void set_Ubicacion(eUbicacion ubicacion);
	eTamanio get_Tamanio();
	void set_Tamanio(eTamanio tamanio);
	bool get_benigno();
	void set_benigno(bool Sano);

private:
	eUbicacion Ubicacion;
	eTamanio Tamanio;
	static int AcumRadiacion;
	bool benigno;

};