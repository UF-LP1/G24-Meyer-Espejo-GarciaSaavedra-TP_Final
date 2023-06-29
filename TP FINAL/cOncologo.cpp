#include "cOncologo.h"

cOncologo::cOncologo(string nro_matricula)
{
	this->Nro_Matricula = nro_matricula;
}

cOncologo::~cOncologo()
{}


void cOncologo::AtenderPaciente(cPaciente* paciente)
{

	Indicador_Tumores(paciente);
	vector<cTumor*> PacienteTumores = paciente->get_miFicha()->get_Tumores();
	int numT=0;
	
	for (int i = 0; i < PacienteTumores.size(); i++)
	{
		//hago randoms para que determine las caracteristicas
		numT = rand() % 3;
		if (numT == 0) //pequenio
		{
			PacienteTumores[i]->set_Tamanio(pequenio);
		}
		else if (numT == 1) {
			PacienteTumores[i]->set_Tamanio(mediano);
		}
		else
			PacienteTumores[i]->set_Tamanio(grande);
	}
	

	//caracteristica de frecuenciasemanal
	//en base a su salud
	unsigned int frecuencia;
	if (paciente->get_Salud() < 0.30) {
		frecuencia = 3;
	}
	else if (paciente->get_Salud() < 0.60) {
		frecuencia = 2;
	}
	else {
		frecuencia = 1;
	}

	paciente->get_miFicha()->set_FrecSemanal(frecuencia); //actualizo en la ficha
	string num = this->Nro_Matricula;
	paciente->get_miFicha()->set_oncologo(num);//asigno oncolog al paciente
	Calcular_Sesiones(paciente, frecuencia);
}

void cOncologo::DosisXSesion(cPaciente* paciente)
{
	vector<cTumor*> tumoraux = paciente->get_miFicha()->get_Tumores();
	

	float dosisSesion;
	for (int i = 0; i < tumoraux.size(); i++)
	{
		dosisSesion = tumoraux[i]->get_terapia()->SetteoDox(tumoraux[i]->get_Tamanio());
		//actualizo en la terapia y en sesiones
		tumoraux[i]->get_terapia()->set_dosisxSesion(dosisSesion);

	}
}


time_t cOncologo::TiempoTratamiento(cPaciente* paciente)
{
	vector<cTumor*> tumoresaux = paciente->get_miFicha()->get_Tumores();
	time_t nuevoTiempo=0;
	int max=0;
	int dias =86400; //SEG en un dia
	int mes = dias * 31;

	if (paciente->get_miFicha()->get_Espera() == true) {//si esta en espera por radiacion .
		for (int i = 0; i < tumoresaux.size(); i++)
			if (tumoresaux[i]->get_Tamanio() == grande)//y su tumor es grande, espera mas
				(nuevoTiempo + 31 * dias);
			else //tumor mediano o pequenio
				(nuevoTiempo + 15 * dias); 

		paciente->get_miFicha()->set_Tratamiento(nuevoTiempo);
	}
	int i = 0;
	while(i < tumoresaux.size()) {
	
		while (tumoresaux[i]->get_Tamanio() == grande) {
			eUbicacion ubi = tumoresaux[i]->get_Ubicacion();
			if (ubi == cabeza || ubi == cuello) {
				max = 12 * mes;
			}
			else if (ubi == pulmon && max < 11 * mes) {
				max = 11 * mes;
			}
			else if (ubi == utero && max < 10 * mes + 15 * dias) {
				max = 10 * mes + 15 * dias;
			}
			else if (ubi == mama && max < 10 * mes) {
				max = 10 * mes;
			}
			else if (ubi == tiroides && max < 9 * mes) {
				max = 9 * mes;
			}
			else if (ubi == prostata && max < 8 * mes) {
				max = 8 * mes;
			}
			else if (ubi == intestino && max < 6 * mes) {
				max = 6 * mes;
			}
			else if (ubi == ojo && max < 4 * mes) {
				max = 4 * mes;
			}
			i++;
			if (i == tumoresaux.size())
				break;
		}
		if (i == tumoresaux.size())
			break;
		while (tumoresaux[i]->get_Tamanio() == mediano) {
			eUbicacion ubi = tumoresaux[i]->get_Ubicacion();
			if (ubi == cabeza || ubi == cuello) {
				max = 10 * mes;
			}
			else if (ubi == pulmon && max <9 * mes) {
				max = 9 * mes;
			}
			else if (ubi == utero && max < 8 * mes + 15 * dias) {
				max = 8 * mes + 15 * dias;
			}
			else if (ubi == mama && max < 8 * mes) {
				max = 8 * mes;
			}
			else if (ubi == tiroides && max < 7 * mes) {
				max = 7 * mes;
			}
			else if (ubi == prostata && max < 6 * mes) {
				max = 6 * mes;
			}
			else if (ubi == intestino && max < 5 * mes) {
				max = 5 * mes;
			}
			else if (ubi == ojo && max < 3 * mes) {
				max = 3 * mes;
			}
			i++;
			if (i == tumoresaux.size())
				break;
		}
		if (i == tumoresaux.size())
			break;

		while (tumoresaux[i]->get_Tamanio() == pequenio) {
			eUbicacion ubi = tumoresaux[i]->get_Ubicacion();
			if (ubi == cabeza || ubi == cuello) {
				max = 8 * mes;
			}
			else if (ubi == pulmon && max < 7 * mes) {
				max = 7 * mes;
			}
			else if (ubi == utero && max < 6 * mes + 15 * dias) {
				max = 6 * mes + 15 * dias;
			}
			else if (ubi == mama && max < 6 * mes) {
				max = 6 * mes;
			}
			else if (ubi == tiroides && max < 5 * mes) {
				max = 5 * mes;
			}
			else if (ubi == prostata && max < 5 * mes) {
				max = 5 * mes;
				break;
			}
			else if (ubi == intestino && max < 4 * mes) {
				max = 4 * mes;
			}
			else if (ubi == ojo && max < 2 * mes) {
				max = 2 * mes;
			}
			i++;
			if (i == tumoresaux.size())
				break;
		}
		if (i == tumoresaux.size())
			break;
	}
	nuevoTiempo += max;
	paciente->get_miFicha()->set_Tratamiento(nuevoTiempo);
	return nuevoTiempo;
}


void cOncologo::ReevaluacionTumores(cPaciente* paciente)
{
	vector<cTumor*>Tumores = paciente->get_miFicha()->get_Tumores();
	for (int i = 0; i < Tumores.size(); i++)
	{
		int num = rand() % 2 + 1;//si es 1 es true, si es 2 es false
		if (num == 1)//es true; tumor benigno
			Tumores[i]->set_benigno(true);
		else // num==2; tumor maligno
			Tumores[i]->set_benigno(false);
	}
}

string cOncologo::get_NroMatricula()
{
	return this->Nro_Matricula;
}





void cOncologo::Evaluacion(cPaciente* paciente)
{
	ReevaluacionTumores(paciente);
	cFicha* fichaaux = paciente->get_miFicha();
	vector<cTumor*> tumoraux = fichaaux->get_Tumores();

	int i = 0;



	for (int j = 0; j < tumoraux.size(); j++)
	{

		while (i < tumoraux.size()) {
			if (tumoraux[i]->get_benigno() == true) { //si el tumor esta sano; lo saco de la lista de tumores
				tumoraux.erase(tumoraux.begin() + i);
			}
			else
				i++;
		}

		if (tumoraux.empty())//si el vector no tiene mas tumores osea esta vacio, cambio el estado de finalizacion a true
			//se considera que termino el tratamiento
			fichaaux->set_Finalizado(true);
		else
		{
			paciente->get_miFicha()->set_espera(false); //cumplio ya el tiempo de espera solicitado (esta dentro del calculo de TiempoTratamiento)
			time_t TimeTratamientoUpdate = TiempoTratamiento(paciente);
			fichaaux->set_Tratamiento(TimeTratamientoUpdate);//alargar el tiempo de tratamiento
		}
	}
}

void cOncologo:: Indicador_Tumores(cPaciente* paciente) {


	int ntumores = rand() % 3 + 1;
	vector<cTumor*>aux;
	eUbicacion Ubi;
	for (int i = 0; i < ntumores; i++) {
	Ubi =eUbicacion(rand() % 8);
	cTumor* nuevo = new cTumor(Ubi);
	aux.push_back(nuevo);

	}
	paciente->get_miFicha()->set_Tumores(aux);

}

void cOncologo::Calcular_Sesiones(cPaciente* paciente, unsigned int frecuencia)
{
	time_t auxtiempo = TiempoTratamiento(paciente);
	int semanas = (int)auxtiempo / 604800;
	vector<cSesion*> sesionesaux;

	int sesiones = semanas * frecuencia;
	for (int i = 0; i < sesiones; i++) {
		cSesion* aux = new cSesion();
		sesionesaux.push_back(aux);
	}
	paciente->get_miFicha()->set_Sesiones(sesionesaux);
}

void  cOncologo::VerifySesion(cPaciente* paciente) {
	int aux =rand()% 1;//random entre 0 y 1
	if (aux != 1) {
	
		Evaluacion(paciente);
	}

}

void cOncologo::UpdateAcumRadiacion(cPaciente* paciente)
{
	DosisXSesion(paciente);
	vector<cSesion*>sesiones = paciente->get_miFicha()->get_Sesiones();
	vector<cTumor*>tumores = paciente->get_miFicha()->get_Tumores();
	int acum = 0;
	for (int j = 0; j < tumores.size(); j++)
	{
		
		for (int i = 0; i < sesiones.size(); i++)
		{
			acum = acum + tumores[j]->get_terapia()->get_dosisxSesion();
		}
		tumores[j]->set_AcumRadiacion(acum);
	}
	
}
