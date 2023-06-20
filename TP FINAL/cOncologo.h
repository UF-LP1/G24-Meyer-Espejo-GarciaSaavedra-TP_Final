#pragma once
#include "Header.h"
#include "cPaciente.h"
#include"exception.h"

#include "cRS.h"
#include "cBT.h"
#include "cRTH.h"
class cOncologo
{
public:
	cOncologo(unsigned int nro_matricula);
	~cOncologo();
	void AtenderPaciente(cPaciente* paciente);//determina segun los estudios que el paciente ya tiene hechos, las características de cada tumor y frec semanal
	void DosisXSesion(cPaciente* paciente);
	time_t TiempoTratamiento(cPaciente* paciente);//modifica el tiempo que va a estar el paciente en tratamiento
	void VerificarFecha(cPaciente* paciente);
	void Evaluacion(cPaciente* paciente);
	void ReevaluacionTumores(cPaciente* paciente);
	unsigned int get_NroMatricula();
	bool VerificarSobredosis(cPaciente* paciente);
private:
	string Nombre;
	string Apellido;
	unsigned int Nro_Matricula;
};

