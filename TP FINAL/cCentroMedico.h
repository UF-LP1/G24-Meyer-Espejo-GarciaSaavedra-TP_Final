#pragma once
#include "Header.h"
#include "cPaciente.h"

class cCentroMedico {
public:
	cCentroMedico(string nombre, string direccion, string telefono);
	~cCentroMedico();
	void AsistenciaPaciente(cPaciente *miPaciente);
	string to_string();
	



private:
	string Nombre; 
	string Direccion;
	string Telefono;
};