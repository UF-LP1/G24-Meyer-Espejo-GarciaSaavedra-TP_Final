#pragma once
#include "Header.h"
#include "cPaciente.h"

#include "cTerapia.h"

class cDosimetrista
{
public:
	cDosimetrista(string id);
	~cDosimetrista();
	void TipoTerapiaRecibir(cPaciente* MiPaciente);
	string get_Nombre();
	string get_Apellido();
	string get_ID();
	int RadTotalPaciente(cPaciente* MiPaciente); //calcula la radiacion maxima posible en el paciente
	float RadTotalTumores(cPaciente* MiPaciente); 
	



private:
	string Nombre; //registro de los pacientes en el centro
	string Apellido;
	const string ID;
};




