#pragma once
#include"Header.h"
class cPaciente
{
public:
	cPaciente(string nombre, string nacimiento, string sexo, string contacto, string tiposangre, float salud, bool tumor);
	~cPaciente();	
	float get_Salud();
	void set_Salud(float salud);
	bool get_Tumor();
	void set_Tumor(bool tumor);



private: 
	string Nombre;
	string Nacimiento;
	string Sexo;
	string Contacto;
	string TipoSangre;
	float  Salud;
	bool Tumor;

};

