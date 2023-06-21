#pragma once
#include "Header.h"

class cSesion {
public:
	cSesion(bool asistencia, int dosis);
	~cSesion();
	bool get_Asist();
	void set_Dosis(float dosis);
	int get_Dosis();

private:
	bool Asistencia;
	int Dosis;
};