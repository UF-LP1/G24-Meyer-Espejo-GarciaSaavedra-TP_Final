#pragma once
#include "Header.h"
#include "cPaciente.h"
#include "eUbicacion.h"
#include"eTratamiento.h"


class cCentroMedico {
public:
	cCentroMedico(string nombre, string direccion, string telefono);
	~cCentroMedico();
	void AsistenciaPaciente(cPaciente *miPaciente);
	string to_string();
	vector<cPaciente*> get_Pacientes();

	//pedidos expecificos en consigna
	vector<cPaciente*> buscarXTumor(eUbicacion ubi);
	vector<cPaciente*> buscarXTratamiento(eTratamiento tratamiento);
	vector<cPaciente*> a5DeSobredosis();


private:
	string Nombre; 
	string Direccion;
	string Telefono;
	vector<cPaciente*> Pacientes;
};