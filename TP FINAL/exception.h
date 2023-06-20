#pragma once
#include "Header.h"

class exceptionSobredosisP :public exception {
public:
	const char* what() const throw() {
		return "La dosis maxima del paciente sera alcanzada, se recomienda mejorar la salud del paciente";
	}
};

class exSobredosisTumor :public exception {
public:
	const char* what() const throw() {
		return "La dosis maxima del tumor sera alcanzada,recomienda mejorar la salud del paciente";
	}
};
