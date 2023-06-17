#include "cRS.h"

cRS::cRS(int DosMaxP, int DosMaxT)
		:cTerapia(DosMaxP, DosMaxT){

}

cRS::~cRS()
{
}

void cRS::curar() {
	cout << "curo con Radioterapia Sistemica" << endl;
}
