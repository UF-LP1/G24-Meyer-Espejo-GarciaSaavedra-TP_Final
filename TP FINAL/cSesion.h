#pragma once
#include "Header.h"

class cSesion {
public:
	cSesion();
	~cSesion();
	bool get_Asist();
	void set_Dosis(int dosis);

private:
	bool Asistencia;
	float Dosis;
};