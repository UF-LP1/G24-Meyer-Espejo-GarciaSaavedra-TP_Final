#include "cRTH.h"

cRTH::cRTH(eTamanio TAmanio, eUbicacion UBicacion):DosMaxP(100), DosMaxT(60) 
{
}

cRTH::~cRTH()
{}

cRTH::cRTH():DosMaxP(100), DosMaxT(60)
{
}

float cRTH::multiplicidadTerapia()
{
	return (0.3);
}


