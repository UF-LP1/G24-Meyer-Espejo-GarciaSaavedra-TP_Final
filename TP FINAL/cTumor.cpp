#include "cTumor.h"



cTumor::cTumor(){
	this->AcumRadiacion = 0; //se va a ir incrementando en cada sesion
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

bool cTumor::get_bedigno()
{
	return false;
}

void cTumor::set_bedigno(bool Sano)
{
	this->bedigno = Sano;
}
