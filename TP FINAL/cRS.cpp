#include "cRS.h"

cRS::cRS(int DosMaxP, int DosMaxT):cTerapia(){
	this->DosMaxP = 100;
	this->DosMaxT = 60;
}

cRS::~cRS()
{
}

int cRS::multiplicidadTerapia()
{
	return (0.1);
}


