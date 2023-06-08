#include "cFicha.h"

vector<cSesion> cFicha::get_Sesiones()
{
	return this-> Sesiones;
}

vector<cTumor> cFicha::get_Tumores()
{
	return this->Tumores;
}

void cFicha::set_Finalizado(bool termino)
{
	this->Finalizado = termino;
}
