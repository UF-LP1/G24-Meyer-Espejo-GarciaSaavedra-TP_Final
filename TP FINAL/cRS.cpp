#include "cRS.h"

cRS::cRS(eTamanio TAmanio, eUbicacion UBicacion):DosMaxP(100), DosMaxT(60)
{

}

cRS::cRS():DosMaxP(100), DosMaxT(60)
{
}

cRS::~cRS()
{
}

float cRS::multiplicidadTerapia()
{
	return (0.1);
}


