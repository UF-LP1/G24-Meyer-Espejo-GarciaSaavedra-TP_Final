#include "cTumor.h"

 cTumor ::cTumor(eUbicacion ubicacion) {

	 calculoRadiacion();
	this->Ubicacion = ubicacion;
	this->benigno = false;
	this->Tamanio = pequenio;
	this->terapia = nullptr;
 }

cTumor::~cTumor()
{
	delete this->terapia;
}

void cTumor::set_AcumRadiacion(float radiacion)
{
	this->AcumRadiacion = radiacion;
}

float cTumor::get_AcumRadiacion()
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
	return this->benigno;
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
	
	ss << "Ubicacion: " << this->Ubicacion << "\nTamanio " << this->Tamanio << "\nTerapia " << this->terapia << "Enfermo: " << this->benigno <<endl;
	return ss.str();
}

void cTumor::calculoRadiacion()
{
	srand(time(NULL));
	float numero = rand() % 600 + 10;
	numero = numero / 10;
	int num = rand() % 3+1;
	if (num == 2) {
		this->AcumRadiacion = 58.0;
	}
	else
		this->AcumRadiacion = numero;
}

