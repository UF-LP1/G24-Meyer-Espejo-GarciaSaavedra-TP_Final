#include "cTerapia.h"

cTerapia::cTerapia(unsigned int dosmaxp,unsigned int dosmaxt)
{
	this->DosMaxP = dosmaxp;
	this->DosMaxT = dosmaxt;
}

cTerapia::~cTerapia()
{
}

unsigned int cTerapia::get_DosisMaxP()
{
	return this->DosMaxP;
}

unsigned int cTerapia::get_DosisMaxt()
{
	return this->DosMaxT;
}

void cTerapia::set_DosisMaxP(unsigned int dosisP)
{
	this->DosMaxP = dosisP;
}

void cTerapia::set_DosisMaxt(unsigned int dosisT)
{
	this->DosMaxT = dosisT;
}
