#include "cSesion.h"

cSesion::cSesion()
{
	int n = rand() % 2 + 1;
	if (n == 1) {
		this->Asistencia = true;
	}
	else
	this->Asistencia = false;


}

cSesion::~cSesion()
{
}

bool cSesion::get_Asist()
{
	return this->Asistencia;
}

