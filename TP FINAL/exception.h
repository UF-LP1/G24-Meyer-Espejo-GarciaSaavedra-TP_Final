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

class exPacienteNoEncontrado :public exception {
public:
	const char* what() const throw() {
		return "No se a encontrado el paciente";
	}
};

class exSobredosis5porciento :public exception {
public:
	const char* what() const throw() {
		return "NO hay ningun paciente con limite de sobredosis del 5%";
	}
};

class exNohayNingunCaso:public exception {
public:
	const char* what() const throw() {
		return "NO hay ningun paciente con estas indicaciones";
	}
};