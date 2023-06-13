#pragma once
#include "Header.h"
class cDosimetrista
{
public:
	cDosimetrista();
	~cDosimetrista();
	void TipoTerapiaRecibir(cPaciente MiPaciente);
	string get_Nombre();
	string get_Apellido();
	string get_ID();
	int CalcularDosisMax(cPaciente MiPaciente);
	int CalcularRadiacionTotal();

private:
	string Nombre; //registro de los pacientes en el centro
	string Apellido;
	string ID;
};




