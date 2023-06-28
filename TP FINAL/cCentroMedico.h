#pragma once
#include "Header.h"
#pragma once
#include "Header.h"
#include "cPaciente.h"
#include "eUbicacion.h"
#include"eTratamiento.h"
#include "exception.h"


class cCentroMedico {
public:
	cCentroMedico(string nombre, string direccion, string telefono);
	~cCentroMedico();
	void AsistenciaPaciente(cPaciente* miPaciente);
	string to_string();
	vector<cPaciente*> get_Pacientes();
	void buscar(cPaciente* paciente);
	void operator+(cPaciente* paciente);

	//pedidos expecificos en consigna
	vector<cPaciente*> buscarXTumoryTerapia(eUbicacion ubi, eTratamiento tratamiento);
	vector<cPaciente*> a5DeSobredosis();

private:
	string Nombre;
	string Direccion;
	string Telefono;
	vector<cPaciente*>Pacientes;
};