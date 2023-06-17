#include "cFicha.h"

cFicha::cFicha(string oncologo, time_t fechainicio, time_t& tratamiento, vector<cTerapia*>& tipotera, vector<cTumor>& tumores, vector<cSesion>& sesiones)
{
	this->Oncologo = oncologo;
	this->FechaInicio = fechainicio;
	this->estadoRad = 0;
	this->espera = false;
	this->Finalizado = false;
	Tratamiento = tratamiento;
	//this->Tratamiento = 0;
	FrecSemanalTratamiento = 0;
	this->TipoT = tipotera;
	this->Tumores = tumores;
	this->Sesiones = sesiones;
}


cFicha::cFicha(vector<cTerapia*>& tipotera, vector<cTumor>& tumores, vector<cSesion>& sesiones)//constructor por defecto por parametro
{
	this->Oncologo = "";
	this->FechaInicio = 0;
	this->estadoRad = 0;
	this->espera = false;
	this->Finalizado = false;
	Tratamiento = 0;
	//this->Tratamiento = 0;
	FrecSemanalTratamiento = 0;
	this->TipoT = tipotera;
	this->Tumores = tumores;
	this->Sesiones = sesiones;
}

cFicha::cFicha()//constructor por defecto
{
	this->Oncologo = "";
	this->FechaInicio = 0;
	this->estadoRad = 0;
	this->espera = false;
	this->Finalizado = false;
	Tratamiento = 0;
	//this->Tratamiento = 0;
	FrecSemanalTratamiento = 0;
}

cFicha::~cFicha()
{
	for (cTerapia* aux : this->TipoT) {
		if (aux != nullptr)
		{
			delete aux;
		}
	}
}

vector<cSesion> cFicha::get_Sesiones()
{
	return this-> Sesiones;
}

vector<cTumor> cFicha::get_Tumores()
{
	return this->Tumores;
}

void cFicha::set_Finalizado(bool termino)
{
	this->Finalizado = termino;
}

time_t cFicha::get_Tratamiento()
{
	return this->Tratamiento;
}

void cFicha::set_Tratamiento(time_t fechatratamiento)
{
	this->Tratamiento = fechatratamiento;
}

vector<cTerapia*> cFicha::get_Terapia()
{
	return this-> TipoT;
}

void cFicha::set_Sesiones(vector<cSesion> sesiones)
{
	this->Sesiones = sesiones;
}

void cFicha::set_Tumores(vector<cTumor> tumores)
{
	this->Tumores = tumores;
}

void cFicha::set_EstadoRad(unsigned int estadorad)
{
	this->estadoRad = estadoRad;
}

unsigned int cFicha::get_EstadoRad()
{
	return this->estadoRad;
}

bool cFicha::get_Espera()
{
	return this->espera;
}