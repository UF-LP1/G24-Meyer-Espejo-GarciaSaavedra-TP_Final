#include "cRTH.h"

cRTH::cRTH(int DosMaxP,int DosMaxT):cTerapia(DosMaxP, DosMaxT)
{
	this->DosMaxP = 0;
	this->DosMaxT = 0;
}

cRTH::~cRTH()
{
}

void cRTH::curar() {
	cout << "curo con Radioterapia de Haz Externo" << endl;
}