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
	void set_Finalizado(bool termino);

private:
	string Oncologo;
	time_t FechaInicio;
	unsigned int estadoRad;
	bool espera;
	time_t Tratamiento;
	vector<cTerapia*>TipoT;
	vector<cTumor> Tumores;
	bool Finalizado;
	vector<cSesion> Sesiones;
	int FrecSemanalTratamiento;
};