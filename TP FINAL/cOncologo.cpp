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
	
	for (int i = 0; i<PacienteTumores.size(); i++)
	{
		//hago randoms para que determine las caracteristicas
		numT = rand() % 3;
		if (numT == 0) //pequenio
		{
			PacienteTumores[i].set_Tamanio(pequenio);
		}
		else if (numT == 1) {
			PacienteTumores[i].set_Tamanio(mediano);
		}
		else
			PacienteTumores[i].set_Tamanio(grande);

		//caracteristicas de ubicacion
		int opcion = rand() % 9;
		eUbicacion ubiaux;
		switch (opcion) {
		case 0:
			ubiaux = cabeza;
			break;
		case 1:
			ubiaux = pulmon;
			break;
		case 2:
			ubiaux = cuello;
			break;
		case 3:
			ubiaux = mama;
			break;
		case 4:
			ubiaux = utero;
			break;
		case 5:
			ubiaux = ojo;
			break;
		case 6:
			ubiaux = tiroides;
			break;
		case 7:
			ubiaux = prostata;
			break;
		default:
			ubiaux = intestino;
			break;
		}
		PacienteTumores[i].set_Ubicacion(ubiaux);
	}
}

void cOncologo::DosisXSesion(cPaciente& paciente)
{
	float saludaux = paciente.get_Salud();
	vector<cSesion> sesionaux = paciente.get_miFicha().get_Sesiones();
	int i = 0;
	int r = 0;
	while (i < sesionaux.size() && saludaux > 0, 5) {

		if (/*el tipo de terapia*/ ==/*haz externo*/) {
			sesionaux[i].set_Dosis(1);
		}
		else if (/*el tipo de terapia*/ ==/*Braquiterapia*/) {
			sesionaux[i].set_Dosis(6);
		}
		else
			sesionaux[i].set_Dosis(2);
		i++;
		paciente.get_miFicha().set_Sesiones(sesionaux);
	}

	while (r < sesionaux.size() && saludaux < 0, 5) {

		if (/*el tipo de terapia*/ ==/*haz externo*/) {
			sesionaux[r].set_Dosis(2);
		}
		else if (/*el tipo de terapia*/ ==/*Braquiterapia*/) {
			sesionaux[r].set_Dosis(6);
		}
		else
			sesionaux[r].set_Dosis(4);
		r++;
		paciente.get_miFicha().set_Sesiones(sesionaux);
	}
	
	//llama al set de dosisxsesion de sesion y le modifica la dosis por sesion. Ademas cambia con un set el vector de sesiones actualizandolo
}

void cOncologo::TiempoTratamiento(cPaciente& paciente)
{
	//modifica el tiempo que va a estar el paciente en tratamiento, llamando al set de ficha
	vector<cTerapia*> Tpiaaux = paciente.get_miFicha().get_Terapia();
	//un if que de acuerdo al tipo de terapia que recibe, modifica la fecha de distinta manera (anotado en Notion)


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
