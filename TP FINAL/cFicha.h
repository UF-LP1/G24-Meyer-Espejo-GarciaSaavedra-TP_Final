#pragma once
#include "Header.h"
#include"cSesion.h"
#include "cTerapia.h"
#include "cTumor.h"

class cFicha {
public:
	cFicha(string Oncologo, time_t FechaInicio, time_t& tratamiento,vector<cTerapia*>& tipotera, vector<cTumor>& tumores, vector<cSesion>& sesiones);
	cFicha(vector<cTerapia*>& tipotera, vector<cTumor>& tumores, vector<cSesion>& sesiones);
	cFicha();
	~cFicha();
	vector<cSesion> get_Sesiones();
	vector<cTumor> get_Tumores();
	unsigned int get_EstadoRad();
	bool get_Espera();
	time_t get_Tratamiento();
	vector<cTerapia*> get_Terapia();

	void set_Tratamiento(time_t fechatratamiento);
	void set_Sesiones(vector<cSesion> sesiones);
	void set_Tumores(vector<cTumor> tumores);
	void set_EstadoRad(unsigned int estadorad);
	void set_Finalizado(bool termino);
	
private:
	string Oncologo;
	time_t FechaInicio;//no tenemos set de esto porque se pasa cuando se crea
	unsigned int estadoRad;
	bool espera;
	time_t Tratamiento;
	int FrecSemanalTratamiento; 
	bool Finalizado;
	vector<cTerapia*>TipoT;
	vector<cTumor> Tumores;
	vector<cSesion> Sesiones;
	
};