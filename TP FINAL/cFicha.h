#pragma once
#include "Header.h"
#include"cSesion.h"
#include "cTerapia.h"
#include "cTumor.h"

class cFicha {
public:
	cFicha(string Oncologo, time_t FechaInicio);
	~cFicha();
	vector<cSesion> get_Sesiones();
	vector<cTumor> get_Tumores();
	void set_Finalizado(bool termino);
	time_t get_Tratamiento();
	void set_Tratamiento(time_t fechatratamiento);
	vector<cTerapia*> get_Terapia();
	void set_Sesiones(vector<cSesion> sesiones);
	void set_Tumores(vector<cTumor> tumores);
	void set_EstadoRad(unsigned int estadorad);
	unsigned int get_EstadoRad();
	bool get_Espera();
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