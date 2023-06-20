#pragma once
#include "eUbicacion.h"
#include "eTamanio.h"
#include "cTerapia.h"

class cTumor {
public:
	cTumor(eUbicacion ubicacion, eTamanio tamanio, int acumRadiacion, bool Benigno);
	cTumor();
	~cTumor();
	void set_AcumRadiacion(int radiacion);
	int get_AcumRadiacion();
	eUbicacion get_Ubicacion();
	void set_Ubicacion(eUbicacion ubicacion);
	eTamanio get_Tamanio();
	void set_Tamanio(eTamanio tamanio);
	bool get_benigno();
	void set_benigno(bool Sano);
	cTerapia* get_terapia();

private:
	eUbicacion Ubicacion;
	eTamanio Tamanio;
	int AcumRadiacion;
	bool benigno;
	cTerapia* terapia;
};