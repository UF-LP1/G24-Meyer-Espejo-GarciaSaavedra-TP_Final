#pragma once
#include "Header.h"
#include "cTerapia.h"

class cRS :public cTerapia {
public: 
	cRS(eTamanio TAmanio, eUbicacion UBicacion);
	cRS();
	~cRS();
	int multiplicidadTerapia(); 

};
