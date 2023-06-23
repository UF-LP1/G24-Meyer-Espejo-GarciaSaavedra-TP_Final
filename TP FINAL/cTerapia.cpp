#include "cTerapia.h"

cTerapia::cTerapia()
{

}
cTerapia::~cTerapia()
{
}
void cTerapia::set_frecuencia(int frecue)
{
	this->frecuencia_semanal = frecue;
}
int cTerapia::get_frecuencia()
{
	return frecuencia_semanal;
}
eTratamiento cTerapia::get_expecificoTratamiento()
{
	return this->tratamiento;
}
