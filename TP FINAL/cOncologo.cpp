#include "cOncologo.h"

cOncologo::cOncologo(unsigned int nro_matricula)
{
	this->Nro_Matricula = nro_matricula;
}

cOncologo::~cOncologo()
{}


void cOncologo::AtenderPaciente(cPaciente *paciente)
{

	vector<cTumor*> PacienteTumores = paciente->get_miFicha()->get_Tumores();
	int numT=0;
	
	for (int i = 0; i<PacienteTumores.size(); i++)
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
		PacienteTumores[i]->set_Ubicacion(ubiaux);

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
}

void cOncologo::DosisXSesion(cPaciente* paciente)
{
	float saludaux = paciente->get_Salud();
	vector<cSesion*> sesionaux = paciente->get_miFicha()->get_Sesiones();
	vector<cTerapia*>SusTerapias = paciente->get_miFicha()->get_Terapia();
	cTerapia* ptr_aux = nullptr;
	int i = 0;
	int r = 0;

	for (int j = 0; SusTerapias.size(); j++)
	{
		ptr_aux = SusTerapias[j];
	

		while (i < sesionaux.size() && saludaux < 0, 5) {//Salud """""mala""",
			//menor dosis
			if (dynamic_cast<cRTH*>(ptr_aux) != NULL) {
				sesionaux[i]->set_Dosis(1);
			}
			else {
				if (dynamic_cast<cBT*>(ptr_aux) != NULL) {
					sesionaux[i]->set_Dosis(6);
				}

				if (dynamic_cast<cRS*>(ptr_aux) != NULL) {
					sesionaux[i]->set_Dosis(2);
				}
			}

			paciente->get_miFicha()->set_Sesiones(sesionaux); // actualizo dosis x sesion
		}

		while (r < sesionaux.size() && saludaux > 0, 5) {//salud """"buena""""

			if (dynamic_cast<cRTH*>(ptr_aux) != NULL) {
				sesionaux[r]->set_Dosis(2);
			}
			else {
				if (dynamic_cast<cBT*>(ptr_aux) != NULL) {
					sesionaux[r]->set_Dosis(6);
				}
				if (dynamic_cast<cRS*>(ptr_aux) != NULL) {
					sesionaux[r]->set_Dosis(4);
				}
				paciente->get_miFicha()->set_Sesiones(sesionaux); // actualizo dosis xsesion
				r++;
			}

		}
	}
	
}

time_t cOncologo::TiempoTratamiento(cPaciente* paciente)
{
	vector<cTumor*> tumoresaux = paciente->get_miFicha()->get_Tumores();
	time_t tiempoActual = time(nullptr);	
	time_t nuevoTiempo=tiempoActual;
	int max=0;
	int dias =86400; //SEG en un dia
	int mes = dias * 31;

	if (paciente->get_miFicha()->get_Espera() == true) {//si esta en espera por radiacion .
		for (int i = 0; tumoresaux.size(); i++)
			if (tumoresaux[i]->get_Tamanio() == grande)//y su tumor es grande, espera mas
				nuevoTiempo + 31 * dias;
			else //tumor mediano o pequenio
				nuevoTiempo + 15 * dias; 

		paciente->get_miFicha()->set_Tratamiento(nuevoTiempo);
	}

	for (int i = 0; tumoresaux.size(); i++) {

		while (tumoresaux[i]->get_Tamanio() == grande) {
			if (tumoresaux[i]->get_Ubicacion() == cabeza || tumoresaux[i]->get_Ubicacion() == cuello) {
				max = 12 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == pulmon && max < 11 * mes) {
				max = 11 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == utero && max < 10 * mes + 15 * dias) {
				max = 10 * mes + 15 * dias;
			}
			else if (tumoresaux[i]->get_Ubicacion() == mama && max < 10 * mes) {
				max = 10 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == tiroides && max < 9 * mes) {
				max = 9 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == prostata && max < 8 * mes) {
				max = 8 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == intestino && max < 6 * mes) {
				max = 6 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == ojo && max < 4 * mes) {
				max = 4 * mes;
			}
		}
		while (tumoresaux[i]->get_Tamanio() == mediano) {
			if (tumoresaux[i]->get_Ubicacion() == cabeza || tumoresaux[i]->get_Ubicacion() == cuello) {
				max = 10 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == pulmon && max <9 * mes) {
				max = 9 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == utero && max < 8 * mes + 15 * dias) {
				max = 8 * mes + 15 * dias;
			}
			else if (tumoresaux[i]->get_Ubicacion() == mama && max < 8 * mes) {
				max = 8 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == tiroides && max < 7 * mes) {
				max = 7 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == prostata && max < 6 * mes) {
				max = 6 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == intestino && max < 5 * mes) {
				max = 5 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == ojo && max < 3 * mes) {
				max = 3 * mes;
			}
		}
		while (tumoresaux[i]->get_Tamanio() == pequenio) {
			if (tumoresaux[i]->get_Ubicacion() == cabeza || tumoresaux[i]->get_Ubicacion() == cuello) {
				max = 8 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == pulmon && max < 7 * mes) {
				max = 7 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == utero && max < 6 * mes + 15 * dias) {
				max = 6 * mes + 15 * dias;
			}
			else if (tumoresaux[i]->get_Ubicacion() == mama && max < 6 * mes) {
				max = 6 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == tiroides && max < 5 * mes) {
				max = 5 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == prostata && max < 5 * mes) {
				max = 5 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == intestino && max < 4 * mes) {
				max = 4 * mes;
			}
			else if (tumoresaux[i]->get_Ubicacion() == ojo && max < 2 * mes) {
				max = 2 * mes;
			}
		}
	}
	nuevoTiempo += max;
	paciente->get_miFicha()->set_Tratamiento(nuevoTiempo);
	return nuevoTiempo;
}

void cOncologo::VerificarFecha(cPaciente *paciente)
{
	//mira la fecha time de tratamiento y cuando se cumple el tiempo establecido, el oncologo debe ver al paciente denuevo
	
	time_t fechatratamiento = paciente->get_miFicha()->get_Tratamiento();
	time_t fechahoy = time(0);
	if (fechatratamiento > fechahoy)
		Evaluacion(paciente);
}

void cOncologo::ReevaluacionTumores(cPaciente* paciente)
{
	vector<cTumor*>Tumores = paciente->get_miFicha()->get_Tumores();
	for (int i = 0; Tumores.size(); i++)
	{
		int num = rand() % 2 + 1;//si es 1 es true, si es 2 es false
		if (num == 1)//es true; tumor benigno
			Tumores[i]->set_benigno(true);
		else // num==2; tumor maligno
			Tumores[i]->set_benigno(false);
	}
}

unsigned int cOncologo::get_NroMatricula()
{
	return this->Nro_Matricula;
}

bool cOncologo::VerificarSobredosis(cPaciente* paciente) 
{
	int cont = 0;
	if (paciente->get_miFicha()->get_RadPaciente() > paciente->get_miFicha()->get_RadMaxPaciente())//se esta pasando de sobredosis
	{
		throw exceptionSobredosisP();
		//mandarlo a espera hasta que mejore su salud
		paciente->get_miFicha()->set_espera(true);
		cont++; //estaria con sobredosis
	}
	

	//tumores
	vector<cTumor*>listatumores = paciente->get_miFicha()->get_Tumores();
	cTerapia* ptr_aux = nullptr;
	
	for (int i = 0; listatumores.size(); i++) //recorro los tumores
	{
		ptr_aux = listatumores[i]->get_terapia();

		if (dynamic_cast<cBT*>(ptr_aux) != NULL)
		{
			//radiacion max por tumor en branquiterapia es de 150
			if (listatumores[i]->get_AcumRadiacion() > 150) {//Va a ver sobredosis en ese tumor
				cont++;
				paciente->get_miFicha()->set_espera(true);
				throw exSobredosisTumor();
			}
		}
		if (dynamic_cast<cRS*>(ptr_aux) != NULL|| dynamic_cast<cRTH*>(ptr_aux) != NULL)
		{
			//radiacion max por tumor es de 60
			if (listatumores[i]->get_AcumRadiacion() > 60) {//Va a ver sobredosis en ese tumor
				cont++;
				paciente->get_miFicha()->set_espera(true);
				throw exSobredosisTumor();

			}
		}
	}

	if (cont != 0)
		return true; //va a ver sobredosis
}



void cOncologo::Evaluacion(cPaciente* paciente)
{
	cFicha* fichaaux = paciente->get_miFicha();
	vector<cTumor*> tumoraux = fichaaux->get_Tumores();
	int i = 0;

	ReevaluacionTumores(paciente);

	for (int j = 0; tumoraux.size(); j++)
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