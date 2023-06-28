#include "cTerapia.h"

cTerapia::cTerapia()
{
	this->tratamiento = branquiterapia;
}
cTerapia::~cTerapia()
{
}

eTratamiento cTerapia::get_expecificoTratamiento()
{
	return this->tratamiento;
}
