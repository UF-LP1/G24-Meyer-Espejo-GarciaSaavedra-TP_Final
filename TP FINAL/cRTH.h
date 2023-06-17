#pragma once
#include "Header.h"
#include "cTerapia.h"

class cRTH :public cTerapia {
	
public:
	cRTH(int DosMaxP, int DosMaxT);
	~cRTH();
	void curar();
};