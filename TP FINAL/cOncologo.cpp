#include "cOncologo.h"

cOncologo::cOncologo(string nombre, string apellido, unsigned int nro_matricula)
{
	this->Nombre = nombre;
	this->Apellido = apellido;
	this->Nro_Matricula = nro_matricula;
}

cOncologo::~cOncologo()
{}



void cOncologo::AtenderCliente(cPaciente &paciente)//determina segun los estudios que el paciente ya tiene hechos, las caracter�sticas de cada tumor (puede tener uno o mas)
{
	vector<cTumor> PacienteTumores = paciente.get_miFicha().get_Tumores();
	int numT=0;
	int numU = 0;
	
	for (int i = 0; PacienteTumores.size(); i++)
	{
		//hago randoms para que determine las caracteristicas
		numT = rand() % 3;
		if (numT == 0) //pequenio
		{
			PacienteTumores[i].set_Tamanio(pequenio);

		}
	}
	
}

void cOncologo::DosisXSesion()
{

	//llama al set de dosisxsesion de paciente o de ficha y le modifica la dosis por sesion
}

void cOncologo::TiempoTratamiento()
{
	//modifica el tiempo que va a estar el paciente en tratamiento, llamando al set de paciente o de ficha, nose en cual quedamos
}

void cOncologo::VerificarFecha()
{
	//mira la fecha time de tratamiento y cuando se cumple el tiempo establecido, el oncologo debe ver al paciente denuevo
	//hay que ver de que manera el oncologo le avisa al paciente que debe volver 
}

void cOncologo::Evaluacion(cPaciente &paciente)
{

}
