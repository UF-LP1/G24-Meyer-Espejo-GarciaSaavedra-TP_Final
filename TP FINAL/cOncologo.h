#pragma once
#include "Header.h"
#include "cPaciente.h"



class cOncologo
{
public:
	cOncologo(string nombre, string apellido, unsigned int Nro_Matricula);
	~cOncologo();
	void AtenderCliente(cPaciente paciente);
	void DosisXSesion();
	void TiempoTratamiento(); 
	void VerificarFecha();
	void Evaluacion(cPaciente paciente);
private:
	string Nombre;
	string Apellido;
	unsigned int Nro_Matricula;
};

