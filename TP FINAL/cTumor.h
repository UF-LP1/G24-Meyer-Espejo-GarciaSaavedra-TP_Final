#pragma once
#include "eUbicacion.h"
#include "eTamanio.h"
#include "cTerapia.h"

class cTumor {
public:
	cTumor(eUbicacion ubicacion);
	~cTumor();
	void set_AcumRadiacion(float radiacion);
	float get_AcumRadiacion();
	eUbicacion get_Ubicacion();
	void set_Ubicacion(eUbicacion ubicacion);
	eTamanio get_Tamanio();
	void set_Tamanio(eTamanio tamanio);
	bool get_benigno();
	void set_benigno(bool Sano);
    void set_Terapia(cTerapia* TipoTs);
	cTerapia* get_terapia();
	string to_string();
	

private:
	eUbicacion Ubicacion;
	eTamanio Tamanio;
	float AcumRadiacion;
	bool benigno;
	cTerapia* terapia;
	
};