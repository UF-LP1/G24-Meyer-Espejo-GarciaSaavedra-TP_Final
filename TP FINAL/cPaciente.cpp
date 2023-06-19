#include "cPaciente.h"

cPaciente::cPaciente(string nombre, time_t nacimiento, string sexo, string contacto, string tiposangre){
	
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

bool cPaciente::operator==(cOncologo& oncologo)
{
	bool a = this->miFicha->get_Oncologo()->get_NroMatricula() == oncologo.get_NroMatricula();
	return a;
}
	
ostream& operator<<(ostream& out, cPaciente& c)
{
	out << c.to_string();
	return out;
}
