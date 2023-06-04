#pragma once
#include "Header.h"
#include "cPaciente.h"//????????????? iria asi la reclacion???????



class cOncologo
{
public:
	cOncologo(string nombre, string apellido, unsigned int Nro_Matricula);
	~cOncologo();

	int get_Nro_Matricula();// nose si es necesario

	void AtenderCliente();
	void DosisXSesion();
	void FrecuenciaTratamiento();//se llama asi pero enrealidad seria cuanto tiempo va a estar el paciente en tratamiento, habria que cmabiarle el nombre
	void VerificarFercha();
	void Evaluacion(cPaciente);
private:
	string Nombre;
	string Apellido;
	unsigned int Nro_Matricula;
};

