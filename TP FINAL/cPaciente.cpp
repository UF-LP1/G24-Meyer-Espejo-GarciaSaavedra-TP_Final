#include "cPaciente.h"

int cPaciente::CantidadPacientes = 0;

cPaciente::cPaciente(string nombre, string sexo, string contacto, string tiposangre, float salud ){
	this->Nombre = nombre;
	this->Sexo = sexo;
	this->Contacto = contacto;
	this->TipoSangre = tiposangre;
	this->Salud = salud;
	CantidadPacientes++;
}

cPaciente::~cPaciente()
{
	delete this->miFicha;
}

float cPaciente::get_Salud()
{
	return this->Salud;
}

void cPaciente::set_Salud(float salud)
{
	this->Salud = salud;
}

cFicha* cPaciente::get_miFicha()
{
	return this->miFicha;
}

string cPaciente::get_Contacto()
{
	return this->Contacto;
}

void cPaciente::set_miFicha(cFicha* fichaActualizada)
{
	this->miFicha = fichaActualizada;
}
string cPaciente::to_string() {
	stringstream ss;
	ss << "Nombre del paciente:" << this->Nombre << ",Naciemiento:" << this->Nacimiento << ",Sexo:" << this->Sexo << ",Tipo de Sangre:" << this->TipoSangre << "Porcentaje de salud" << (this->Salud) * 100 << "%"<<endl;
	return( ss.str());
}

bool cPaciente::operator==(string oncologo)
{
	
	return (this->miFicha->get_Oncologo()==oncologo);
}
	
ostream& operator<<(ostream& out, cPaciente& c)
{
	out << c.to_string();
	return out;
}
