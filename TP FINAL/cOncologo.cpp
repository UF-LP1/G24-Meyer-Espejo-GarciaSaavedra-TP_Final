#include "cOncologo.h"

cOncologo::cOncologo(string nombre, string apellido, unsigned int nro_matricula)
{
	this->Nombre = nombre;
	this->Apellido = apellido;
	this->Nro_Matricula = nro_matricula;
}

cOncologo::~cOncologo()
{
}

int cOncologo::get_Nro_Matricula()
{
	return this->Nro_Matricula;
}

void cOncologo::AtenderCliente()//determina segun los estudios que el paciente ya tiene hechos, las características de cada tumor (puede tener uno o mas)
{

}

void cOncologo::DosisXSesion()
{

	//llama al set de dosisxsesion de paciente o de ficha y le modifica la dosis por sesion
}

void cOncologo::FrecuenciaTratamiento()
{
	//modifica el tiempo que va a estar el paciente en tratamiento, llamando al set de paciente o de ficha, nose en cual quedamos
}

void cOncologo::VerificarFercha()
{
	//mira la fecha time de tratamiento y cuando se cumple el tiempo establecido, el oncologo debe ver al paciente denuevo
	//hay que ver de que manera el oncologo le avisa al paciente que debe volver 
}

void cOncologo::Evaluacion(cPaciente)
{

}
