#include "cPaciente.h"

cPaciente::cPaciente(string nombre, string nacimiento, string sexo, string contacto, string tiposangre, float salud, bool tumor)
{
	this->Nombre = nombre;
	this->Nacimiento = nacimiento;
	this->Sexo = sexo;
	this->Contacto = contacto;
	this->TipoSangre = tiposangre;
	this->Salud = salud;
	this->Tumor = tumor;
}

cPaciente::~cPaciente()
{
}

float cPaciente::get_Salud()
{
	return this->Salud;
}

void cPaciente::set_Salud(float salud)
{
	this->Salud = salud;
}

bool cPaciente::get_Tumor()
{
	return this->Tumor;
}

void cPaciente::set_Tumor(bool tumor)
{
	this->Tumor = tumor;
}
