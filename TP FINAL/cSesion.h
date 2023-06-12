#pragma once
#include "Header.h"

class cSesion {
public:
	cSesion(bool asistencia, float dosis);
	~cSesion();
	bool get_Asist();
	void set_Dosis(int dosis);

private:
	bool Asistencia;
	float Dosis;
};