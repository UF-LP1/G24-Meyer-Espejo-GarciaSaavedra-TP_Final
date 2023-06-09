#include "cOncologo.h"

cOncologo::cOncologo(string nombre, string apellido, unsigned int nro_matricula)
{
	this->Nombre = nombre;
	this->Apellido = apellido;
	this->Nro_Matricula = nro_matricula;
}

cOncologo::~cOncologo()
{}



void cOncologo::AtenderCliente(cPaciente &paciente)//determina segun los estudios que el paciente ya tiene hechos, las características de cada tumor (puede tener uno o mas)
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


		int opcion = rand() % 9;

		switch (opcion) {
		case 0:
			eUbicacion ubiaux = cabeza;
			break;
		case 1:
			eUbicacion ubiaux = pulmon;
			break;
		case 2:
			eUbicacion ubiaux = cuello;
			break;
		case 3:
			eUbicacion ubiaux = mama;
			break;
		case 4:
			eUbicacion ubiaux = utero;
			break;
		case 5:
			eUbicacion ubiaux = ojo;
			break;
		case 6:
			eUbicacion ubiaux = tiroides;
			break;
		case 7:
			eUbicacion ubiaux = prostata;
			break;
		default:
			eUbicacion ubiaux = intestino;
			break;

			PacienteTumores[i].set_Ubicacion(ubiaux);
		}

	}
	
	
}

void cOncologo::DosisXSesion()
{

	//llama al set de dosisxsesion de paciente o de ficha y le modifica la dosis por sesion
}

void cOncologo::TiempoTratamiento()
{
	//modifica el tiempo que va a estar el paciente en tratamiento, llamando al set de ficha
}

void cOncologo::VerificarFecha(cPaciente &paciente)
{
	//mira la fecha time de tratamiento y cuando se cumple el tiempo establecido, el oncologo debe ver al paciente denuevo
	//hay que ver de que manera el oncologo le avisa al paciente que debe volver 

	time_t fechatratamiento = paciente.get_miFicha().get_Tratamiento();
	time_t fechahoy = time(0);
	if (fechatratamiento > fechahoy)
		Evaluacion(paciente);

}

void cOncologo::Evaluacion(cPaciente &paciente)
{
	cFicha fichaaux = paciente.get_miFicha();
	vector<cTumor> tumoraux = fichaaux.get_Tumores();
	int i = 0;
	while (i < tumoraux.size()) {
		if (!tumoraux[i].get_sano()) {
			tumoraux.erase(tumoraux.begin() + i);
		}
		else {
			i++;
		}
	}
	if (tumoraux.empty())//si el vector no tiene mas tumores osea esta vacio, camnbio el estado de finalizacion a true
		fichaaux.set_Finalizado(true);
	else
	{


		fichaaux.set_Tratamiento();//alargar el tiempo de tratamiento
	}


	/*Si se elimina un elemento, no se incrementa i en ese caso,
		ya que el próximo elemento ocupa su posición.Solo se incrementa i si no se elimina un elemento.*/
		

}
