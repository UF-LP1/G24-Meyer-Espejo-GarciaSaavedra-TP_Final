#include "cFicha.h"



cFicha::cFicha(string oncologodni)
{
	this->FechaInicio = time(0);
	this->NextSesion = time(0);
	this->estadoRad = 0;
	this->espera = false;
	this->Finalizado = false;
	this->Tratamiento = 0;
	this->RadiacionMaxPaciente = 0;
	this->RadiacionPaciente = 0;
	this->OncologoAsignadoID = oncologodni;
}

cFicha::~cFicha()
{
	for (cTerapia* aux : this->Terapias) {
		if (aux != nullptr)
		{
			delete aux;
		}
	}
	for (cTumor* aux : this->Tumores) {
		if (aux != nullptr)
		{
			delete aux;
		}
	}
	for (cSesion* aux : this->Sesiones) {
		if (aux != nullptr)
		{
			delete aux;
		}
	}
}

vector<cSesion*> cFicha::get_Sesiones()
{
	return this-> Sesiones;
}

vector<cTumor*> cFicha::get_Tumores()
{
	return this->Tumores;
}

void cFicha::set_Finalizado(bool termino)
{
	this->Finalizado = termino;
}

void cFicha::operator+(cSesion* s)
{
	if (s != nullptr)
		this->Sesiones.push_back(s);
}

void cFicha::operator-(cSesion* s)
{
	if (s != nullptr)
	{
		for (int i = 0; i < Sesiones.size(); i++)
		{
			if (Sesiones[i] == s) //lo busca
			{
				Sesiones.erase(Sesiones.begin() + i);//el principio del vector mas la posicion en la que encontro el elemento a eliminar
			}
		}
	}
}

void cFicha::operator+(cTumor* t)
{
	if (t != nullptr)
		this->Tumores.push_back(t);
}

void cFicha::operator-(cTumor* t)
{
	if (t != nullptr)
	{
		for (int i = 0; i < Tumores.size(); i++)
		{
			if (Tumores[i] == t) //lo busca
			{
				Tumores.erase(Tumores.begin() + i);
			}
		}
	}
}


string cFicha::to_string()
{
	stringstream ss;
	ss << "Oncologo a cargo: " << this->OncologoAsignadoID << "\nEstado de espera: " << this->espera << "\nEstado de finalizacion" << this->Finalizado << "\nFrecuencia de tratamiento: " << this->FrecTratamiento << "\nRadiacion maxima de paciente: " << this->RadiacionMaxPaciente << "\nRadiacion paciente: " << this->RadiacionPaciente << endl;
	return ss.str();
}

ostream& operator<<(ostream& out, cFicha& c)
{
	out << c.to_string();

	return out;
}

time_t cFicha::get_Tratamiento()
{
	return this->Tratamiento;
}

void cFicha::set_Tratamiento(time_t fechatratamiento)
{
	this->Tratamiento = fechatratamiento;
}

string cFicha::get_Oncologo()
{
	return this->OncologoAsignadoID;
}


void cFicha::set_Sesiones(vector<cSesion*> sesiones)
{
	this->Sesiones = sesiones;
}

void cFicha::set_Tumores(vector<cTumor*> tumores)
{
	this->Tumores = tumores;
}

void cFicha::set_Terapia(vector<cTerapia*> terapias)
{
	this->Terapias = terapias;
}


void cFicha::set_EstadoRad(unsigned int estadorad)
{
	this->estadoRad = estadoRad;
}

unsigned int cFicha::get_EstadoRad()
{
	return this->estadoRad;
}

bool cFicha::get_Espera()
{
	return this->espera;
}


void cFicha::set_RadiacionMaxP(int r)
{
	this->RadiacionMaxPaciente = r;
}

void cFicha::set_espera(bool e)
{
	this->espera = e;
}

int cFicha::get_RadMaxPaciente()
{
	return this->RadiacionMaxPaciente;
}

void cFicha::CalcRadPaciente()
{
		//Radiacion_paciente = Tumores_RTPHazExterno * 0.3 + Tumores_Braquiterapia * 0.6+Tumores_Sistemico * 0.1
		int RadPaciente = 0;
		cTerapia* ptr_aux = nullptr;
		for (int i = 0; i < Tumores.size(); i++)
		{
			ptr_aux = Tumores[i]->get_terapia();

			if (dynamic_cast<cBT*>(ptr_aux) != NULL)
			{
				RadPaciente = RadPaciente + ((float)Tumores[i]->get_AcumRadiacion() * 0.6);
			}
			else if (dynamic_cast<cRTH*>(ptr_aux) != NULL)
			{
				RadPaciente = RadPaciente + ((float)Tumores[i]->get_AcumRadiacion() * 0.3);
			}
			else if (dynamic_cast<cRS*>(ptr_aux) != NULL)
			{
				RadPaciente = RadPaciente + ((float)Tumores[i]->get_AcumRadiacion() * 0.1);
			}

		}

		this->RadiacionPaciente = RadPaciente; //actualizando
	
}

int cFicha::get_RadPaciente()
{
	return this->RadiacionPaciente;
}

void cFicha::actualizar_Terapia()
{
	vector<cTerapia*>Auxiliar;
	cTerapia* aux = NULL;

	for (int i = 0; i < Tumores.size(); i++) {
		
		aux = Tumores[i]->get_terapia();
		Auxiliar.push_back(aux);
}
	this->Terapias = Auxiliar;
}

vector<cTerapia*> cFicha::get_Terapias()
{
	return this->Terapias; 
}

void cFicha::set_FrecSemanal(int f)
{
	this->FrecTratamiento = f;

}

time_t cFicha::get_FechaInicio()
{
	return this->FechaInicio;
}

void cFicha::setteoProxSesion()
{
	int diaseg = 86400;
	//en el metodo AtenderPaciente (cOncologo) admitimos que la frecuencia podia ser o 1,2 o 3
	if (this->FrecTratamiento == 1) //le faltan 7 dias
		this->NextSesion = time(NULL) + 7 * diaseg;
	else if (this->FrecTratamiento == 2)
		this->NextSesion = time(NULL) + 4 * diaseg;
	else 
		this->NextSesion= time(NULL) + 2 * diaseg;
}



void cFicha:: set_oncologo(string o) {


	this->OncologoAsignadoID = o;
}
