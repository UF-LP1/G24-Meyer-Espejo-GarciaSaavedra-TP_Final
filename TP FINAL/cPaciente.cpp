#include "cPaciente.h"

cPaciente::cPaciente(string nombre, time_t nacimiento, string sexo, string contacto, string tiposangre, float salud)
{
	this->Nombre = nombre;
	this->Nacimiento = nacimiento;
	this->Sexo = sexo;
	this->Contacto = contacto;
	this->TipoSangre = tiposangre;
	this->Salud = salud;
	
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

cFicha cPaciente::get_miFicha()
{
	return this->miFicha;
}

string cPaciente::get_Contacto()
{
	return this->Contacto;
}

