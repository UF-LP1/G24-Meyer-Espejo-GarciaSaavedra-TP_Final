#include "cSesion.h"

cSesion::cSesion()
{
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
