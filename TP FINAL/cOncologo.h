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
	void AtenderCliente(cPaciente* paciente);//determina segun los estudios que el paciente ya tiene hechos, las características de cada tumor (puede tener uno o mas)
	void DosisXSesion(cPaciente* paciente);
	void TiempoTratamiento(cPaciente* paciente);//modifica el tiempo que va a estar el paciente en tratamiento
	void VerificarFecha(cPaciente* paciente);
	void Evaluacion(cPaciente* paciente);
	void ReevaluacionTumores(cPaciente* paciente);
	unsigned int get_NroMatricula();

private:
	string Nombre;
	string Apellido;
	unsigned int Nro_Matricula;
};

