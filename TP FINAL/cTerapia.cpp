#include "cTerapia.h"


cTerapia::cTerapia(eTratamiento tratamiento, eTamanio tamanio):tratamiento(tratamiento)
{
	this->dosisxSesion = 0;
}
cTerapia::~cTerapia()
{
}

eTratamiento cTerapia::get_expecificoTratamiento()
{
	return this->tratamiento;
}

void cTerapia::set_dosisxSesion(float dosis)
{
	this->dosisxSesion = dosis;
}
