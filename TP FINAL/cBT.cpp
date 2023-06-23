#include "cBT.h"



cBT::cBT(eTamanio TAmanio, eUbicacion UBicacion) :DosMaxP(180),DosMaxT(150)
{ 
}

cBT::cBT():DosMaxP(180), DosMaxT(150)
{
}

cBT::~cBT()
{
}

float cBT::multiplicidadTerapia()
{
	return (0.6);
}

