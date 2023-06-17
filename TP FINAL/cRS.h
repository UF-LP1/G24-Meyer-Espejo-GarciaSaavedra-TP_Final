#pragma once
#include "Header.h"
#include "cTerapia.h"

class cRS :public cTerapia {
public: 
	cRS(int DosMaxP, int DosMaxT);
	~cRS();
	void curar();
};