#pragma once
#include "Header.h"
#include "cPaciente.h"

#include "cRS.h"
#include "cBT.h"
#include "cRTH.h"
class cDosimetrista
{
public:
	cDosimetrista(string nombre, string apellido, string id);
	~cDosimetrista();
	void TipoTerapiaRecibir(cPaciente *MiPaciente);
	string get_Nombre();
	string get_Apellido();
	string get_ID();
	bool CalcularDosisMax(cPaciente* MiPaciente);
	int CalcularRadiacionTotal(cPaciente* MiPaciente);

private:
	string Nombre; //registro de los pacientes en el centro
	string Apellido;
	string ID;
};




