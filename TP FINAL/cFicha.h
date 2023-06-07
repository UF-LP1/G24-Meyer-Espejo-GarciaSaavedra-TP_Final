#pragma once
#include "Header.h"
#include"cSesion.h"
#include "cTerapia.h"
#include "cTumor.h"

class cFicha {
public:
	cFicha();
	~cFicha();
	vector<cSesion> get_Sesiones();
	vector<cTumor> get_Tumores();

private:
	string Oncologo;
	time_t FechaInicio;
	unsigned int estadoRad;
	bool espera;
	time_t Tratamiento;
	vector<cTerapia*>TipoT;
	vector<cTumor> Tumores;
	bool Alta;
	vector<cSesion> Sesiones;
	int FrecSemanalTratamiento;
};