#pragma once
#include "Header.h"
#include "cPaciente.h"

#include "cRS.h"
#include "cBT.h"
#include "cRTH.h"
class cDosimetrista
{
public:
	cDosimetrista();
	~cDosimetrista();
	void TipoTerapiaRecibir(cPaciente* MiPaciente);
	string get_Nombre();
	string get_Apellido();
	string get_ID();
	//bool CalcularDosisTotalTumor(cPaciente* MiPaciente);
	int RadTotalPaciente(cPaciente* MiPaciente); //calcula la radiacion maxima posible en el paciente
	//int RadTotalTumores(cPaciente* MiPaciente); 

private:
	string Nombre; //registro de los pacientes en el centro
	string Apellido;
	string ID;
};




