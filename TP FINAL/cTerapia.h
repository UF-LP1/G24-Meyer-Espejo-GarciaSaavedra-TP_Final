#pragma once
#include "Header.h"

class cTerapia {
public:
	cTerapia(int dosmaxp,int dosmaxt);
	cTerapia();
	~cTerapia();
	unsigned int get_DosisMaxP();
	unsigned int get_DosisMaxt();
	void set_DosisMaxP(unsigned int dosisP);
	void set_DosisMaxt(unsigned int dosisT);
	virtual void curar()=0;

protected:
	unsigned int DosMaxP; //dosis maxima paciente
	unsigned int DosMaxT; //dosis maxima tumor

};