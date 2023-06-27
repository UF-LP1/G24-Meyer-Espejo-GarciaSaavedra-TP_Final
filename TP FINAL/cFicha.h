#pragma once
#include "Header.h"
#include"cSesion.h"
#include"cRS.h"
#include "cBT.h"
#include "cRTH.h"
#include "cTumor.h"


class cFicha {
public:
	cFicha(string oncologodni);
	~cFicha();
	vector<cSesion*> get_Sesiones();
	vector<cTumor*> get_Tumores();
	unsigned int get_EstadoRad();
	bool get_Espera();
	time_t get_Tratamiento();
	string get_Oncologo();
	void set_Tratamiento(time_t fechatratamiento);
	void set_Sesiones(vector<cSesion*> sesiones);
	void set_Tumores(vector<cTumor*> tumores);
	void set_Terapia(vector<cTerapia*>terapias);

	

	void set_EstadoRad(unsigned int estadorad);

	void set_Finalizado(bool termino);
	void set_RadiacionMaxP(int r);
	void set_espera(bool e);
	void set_oncologo(string o);
	int get_RadMaxPaciente();
	void CalcRadPaciente(); //incluido el set y la cuenta dada en la consigna
	int get_RadPaciente();
	void actualizar_Terapia();
	vector<cTerapia*> get_Terapia();
	void set_FrecSemanal(int f);

	//sobrecargas 
	void operator+(cSesion* s); 
	void operator- (cSesion* s);
	void operator+(cTumor* t);
	void operator- (cTumor* t);
	friend ostream& operator<<(ostream& out, cFicha& c);

	string to_string();
	

	
private:
    string  OncologoAsignadoID;
	time_t FechaInicio;//no tenemos set de esto porque se pasa cuando se crea
	unsigned int estadoRad;
	bool espera;
	vector<cTerapia*>Terapias;
	time_t Tratamiento;
	bool Finalizado;
	int FrecTratamiento;
	vector<cTumor*> Tumores; //se necesita imprimir 
	vector<cSesion*> Sesiones;
	int RadiacionMaxPaciente; //esta es el limite; la calcula el dosimetrista en el metodo RadTotalPaciente
	int RadiacionPaciente;
};