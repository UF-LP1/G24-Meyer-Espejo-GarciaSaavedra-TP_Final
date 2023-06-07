#pragma once
#include "Header.h"

class cSesion {
public:
	cSesion(); //podriamos hacer por defecto la asistencia y por parametro la dosis
	~cSesion();
	bool get_Asist();
	void set_Dosis(int dosis);

private:
	bool Asistencia;
	int Dosis;
};