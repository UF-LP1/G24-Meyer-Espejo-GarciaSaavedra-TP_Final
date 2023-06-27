#include "cSesion.h"

cSesion::cSesion(bool asistencia,int dosis)
{
	this->Asistencia = asistencia;
	this->Dosis = dosis;
}

cSesion::cSesion()
{
	this->Dosis = 0;
}

cSesion::~cSesion()
{
}

bool cSesion::get_Asist()
{
	return this->Asistencia;
}

void cSesion::set_Dosis(float dosis)
{
	this->Dosis = dosis;
}

int cSesion::get_Dosis()
{
	return this->Dosis;
}

