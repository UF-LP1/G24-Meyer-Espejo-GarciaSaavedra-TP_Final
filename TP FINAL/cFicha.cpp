#include "cFicha.h"

cFicha::cFicha()
{
}

cFicha::~cFicha()
{
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
