#pragma once"
#include "Header.h"
#include "cPaciente.h"
#include "cTerapia.h"
class cDosimetrista
{
public:
	cDosimetrista();
	~cDosimetrista();
	void TipoTerapiaRecibir(cPaciente *MiPaciente);
	string get_Nombre();
	string get_Apellido();
	string get_ID();
	bool CalcularDosisMax(cPaciente *MiPaciente);
	int CalcularRadiacionTotal();

private:
	string Nombre; //registro de los pacientes en el centro
	string Apellido;
	string ID;
};




