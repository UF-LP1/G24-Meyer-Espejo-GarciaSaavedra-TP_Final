#pragma once
#include "Header.h"
#include "cPaciente.h"

class cCentroMedico {
public:
	cCentroMedico();
	~cCentroMedico();
	void AsistenciaPaciente(cPaciente *miPaciente);

private:
	string Nombre; 
	string Direccion;
	string Telefono;
	

};