#include "cTumor.h"



cTumor::cTumor()
{
}

cTumor::~cTumor()
{
}

void cTumor::set_AcumRadiacion(int radiacion)
{
}

int cTumor::get_AcumRadiacion()
{
	return this->AcumRadiacion;
}

eUbicacion cTumor::get_Ubicacion()
{
	return eUbicacion();
}

void cTumor::set_Ubicacion(eUbicacion ubicacion)
{
	this->Ubicacion = ubicacion;
}

eTamanio cTumor::get_Tamanio()
{
	return eTamanio();
}

void cTumor::set_Tamanio(eTamanio tamanio)
{
	this->Tamanio = tamanio;
}

bool cTumor::get_sano()
{
	return false;
}
