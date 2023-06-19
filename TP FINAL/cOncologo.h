#pragma once
#include "Header.h"
#include "cPaciente.h"

#include "cRS.h"
#include "cBT.h"
#include "cRTH.h"
class cOncologo
{
public:
	cOncologo(string nombre, string apellido, unsigned int nro_matricula);
	~cOncologo();
	void AtenderCliente(cPaciente* paciente);
	void DosisXSesion(cPaciente* paciente);
	time_t TiempoTratamiento(cPaciente* paciente);
	void VerificarFecha(cPaciente* paciente);
	void Evaluacion(cPaciente* paciente);
	void ReevaluacionTumores(cPaciente* paciente);
	unsigned int get_NroMatricula();

private:
	string Nombre;
	string Apellido;
	unsigned int Nro_Matricula;
};

