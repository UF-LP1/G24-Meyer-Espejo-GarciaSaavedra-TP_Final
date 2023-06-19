#include "cBT.h"

cBT::cBT():cTerapia()
{
	this->DosMaxP = 180;
	this->DosMaxT = 150;
}

cBT::~cBT()
{
}

int cBT::multiplicidadTerapia()
{
	return (0.6);
}

