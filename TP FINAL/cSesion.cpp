#include "cSesion.h"

cSesion::cSesion()
{
	int n = rand() % 2 + 1;
	if (n == 1) {
		this->Asistencia = true;
	}
	else
	this->Asistencia = false;

	this->Dosis = 0;//se actualiza luego en el metodo dosisXsesion
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

