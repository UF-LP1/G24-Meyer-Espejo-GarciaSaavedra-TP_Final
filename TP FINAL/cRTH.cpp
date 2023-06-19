#include "cRTH.h"

cRTH::cRTH(int DosMaxP,int DosMaxT):cTerapia()
{
	this->DosMaxP = 100;
	this->DosMaxT = 60;
}

cRTH::~cRTH()
{
	
}

int cRTH::multiplicidadTerapia()
{
	return (0.3);
}


