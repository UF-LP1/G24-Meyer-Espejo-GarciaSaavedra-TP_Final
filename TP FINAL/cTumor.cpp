#include "cTumor.h"

 cTumor ::cTumor(eUbicacion ubicacion) {
	this->Ubicacion = ubicacion;
	this->AcumRadiacion = 0;
	this->benigno = false;
	this->Tamanio = pequenio;
	this->terapia = nullptr;
 }

cTumor::~cTumor()
{
	delete this->terapia;
}

void cTumor::set_AcumRadiacion(int radiacion)
{
	this->AcumRadiacion = radiacion;
}

int cTumor::get_AcumRadiacion()
{
	return this->AcumRadiacion;
}

eUbicacion cTumor::get_Ubicacion()
{
	return this->Ubicacion;
}

void cTumor::set_Ubicacion(eUbicacion ubicacion)
{
	this->Ubicacion = ubicacion;
}

eTamanio cTumor::get_Tamanio()
{
	return this->Tamanio;
}

void cTumor::set_Tamanio(eTamanio tamanio)
{
	this->Tamanio = tamanio;
}

bool cTumor::get_benigno()
{
	return false;
}

void cTumor::set_benigno(bool Sano)
{
	this->benigno = Sano;
}

cTerapia* cTumor::get_terapia()
{
	return this->terapia;
}
void  cTumor::set_Terapia(cTerapia* TipoTs) {
	this->terapia = TipoTs;
}
string cTumor:: to_string() {
	stringstream ss;
	
	ss << "Ubicacion" << this->Ubicacion << ",Tamanio" << this->Tamanio << ",Terapia" << this->terapia << ",Acumulacion de radiacion" << this->AcumRadiacion;
	return(ss.str());
}

eTratamiento cTumor::get_expecificoTerapia()
{
	return this->tratamiento;
}
