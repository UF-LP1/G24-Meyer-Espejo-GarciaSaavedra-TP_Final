#pragma once
#include "Header.h"
#include "cTerapia.h"


class cBT :public cTerapia {
public: 
	cBT(eTamanio TAmanio,eUbicacion UBicacion);
	cBT();
	~cBT();
	int multiplicidadTerapia();
};
