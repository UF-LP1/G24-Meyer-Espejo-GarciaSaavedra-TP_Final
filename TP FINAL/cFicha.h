#pragma once
#include "Header.h"
#include"cSesion.h"
#include "cTerapia.h"
#include "cTumor.h"
#include "cOncologo.h"

class cFicha {
public:
	cFicha();
	~cFicha();
	vector<cSesion*> get_Sesiones();
	vector<cTumor*> get_Tumores();
	unsigned int get_EstadoRad();
	bool get_Espera();
	time_t get_Tratamiento();
	vector<cTerapia*> get_Terapia();
	cOncologo* get_Oncologo();
	void set_Tratamiento(time_t fechatratamiento);
	void set_Sesiones(vector<cSesion*> sesiones);
	void set_Tumores(vector<cTumor*> tumores);
	void set_EstadoRad(unsigned int estadorad);
	void set_Finalizado(bool termino);
	void set_Tipo_T(vector<cTerapia*>TipoS);
	void Agregar_Terapia(cTerapia* T);
	

	//sobrecargas 
	void operator+(cSesion* s); 
	void operator- (cSesion* s);
	void operator+(cTumor* t);
	void operator- (cTumor* t);
	void operator+ (cTerapia* t);
	void operator-(cTerapia* t);
	friend ostream& operator<<(ostream& out, cFicha& c);

	string to_string();
	

	
private:
	cOncologo* OncologoAsignado;
	time_t FechaInicio;//no tenemos set de esto porque se pasa cuando se crea
	unsigned int estadoRad;
	bool espera;
	time_t Tratamiento;
	int FrecSemanalTratamiento; 
	bool Finalizado;
	vector<cTerapia*>TipoT; //se necesita imprimir
	vector<cTumor*> Tumores; //se necesita imprimir 
	vector<cSesion*> Sesiones;
	
};