#pragma once
#include "Header.h"
class cCentro {

public:
	cCentro(string nombre, string direccion, string telefono);
	~cCentro();
	string to_string() ;

private:
	string Nombre;
	string Direccion;
	string Telefono;
};
