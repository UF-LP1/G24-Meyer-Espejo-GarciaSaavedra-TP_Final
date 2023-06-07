#pragma once
#include"Header.h"
#include "cFicha.h"

class cPaciente
{
public:
	cPaciente(string nombre, time_t nacimiento, string sexo, string contacto, string tiposangre, float salud);
	~cPaciente();	
	float get_Salud();
	void set_Salud(float salud);
	cFicha get_miFicha();
	string get_Contacto();

private: 
	string Nombre;
	time_t Nacimiento;
	string Sexo;
	string Contacto;
	string TipoSangre;
	float  Salud;
	cFicha miFicha;

};

