#include "cSesion.h"

cSesion::cSesion(bool asistencia,float dosis)
{
	this->Asistencia = asistencia;
	this->Dosis = dosis;
}

cSesion::~cSesion()
{
}

bool cSesion::get_Asist()
{
	return this->Asistencia;
}

void cSesion::set_Dosis(int dosis)
{
	this->Dosis = dosis;
}
