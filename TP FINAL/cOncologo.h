#pragma once
#include "Header.h"
#include"exception.h"

#include "cRS.h"
#include "cBT.h"
#include "cRTH.h"
#include "cPaciente.h"
class cOncologo
{
public:
	cOncologo(string nro_matricula);
	~cOncologo();
	void AtenderPaciente(cPaciente* paciente);//determina segun los estudios que el paciente ya tiene hechos, las características de cada tumor y frec semanal
	void DosisXSesion(cPaciente* paciente);
	time_t TiempoTratamiento(cPaciente* paciente);//modifica el tiempo que va a estar el paciente en tratamiento
	void Evaluacion(cPaciente* paciente);
	void ReevaluacionTumores(cPaciente* paciente);
	string get_NroMatricula();
	void Indicador_Tumores(cPaciente* paciente);
	void Calcular_Sesiones(cPaciente* paciente, unsigned int frecuencia);
	void VerifySesion(cPaciente* paciente);
	void UpdateAcumRadiacion(cPaciente* paciente);



private:
	string Nombre;
	string Apellido;
	string Nro_Matricula;
};

