#include "cFicha.h"



cFicha::cFicha()//constructor por defecto
{
	this->OncologoAsignado = nullptr;
	this->FechaInicio = 0;
	this->estadoRad = 0;
	this->espera = false;
	this->Finalizado = false;
	this->Tratamiento = 0;
	this-> FrecSemanalTratamiento = 0;
}

cFicha::~cFicha()
{
	for (cTerapia* aux : this->TipoT) {
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
		for (int i = 0; Sesiones.size(); i++)
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
		for (int i = 0; Tumores.size(); i++)
		{
			if (Tumores[i] == t) //lo busca
			{
				Tumores.erase(Tumores.begin() + i);
			}
		}
	}
}

void cFicha::operator+(cTerapia* t)
{
	if (t !=nullptr)
	{
		TipoT.push_back(t);
	}
}

void cFicha::operator-(cTerapia* t)
{
	if (t != nullptr)
	{
		for (int i = 0; TipoT.size(); i++)
		{
			if (TipoT[i] == t) //lo busca
			{
				TipoT.erase(TipoT.begin() + i);
			}
		}
	}
}

string cFicha::to_string()
{
	stringstream ss;
	ss << "Oncologo a cargo" << this->OncologoAsignado<<";Terapias";

	for (int i = 0; TipoT.size(); i++)
	{
		ss << "-" << TipoT[i];
	}

	ss << ";Tumores";

	for (int i = 0; Tumores.size(); i++)
	{
		ss << "-" << Tumores[i];
	}

	return ss.str();
}



time_t cFicha::get_Tratamiento()
{
	return this->Tratamiento;
}

void cFicha::set_Tratamiento(time_t fechatratamiento)
{
	this->Tratamiento = fechatratamiento;
}

vector<cTerapia*> cFicha::get_Terapia()
{
	return this-> TipoT;
}

cOncologo* cFicha::get_Oncologo()
{
	return this->OncologoAsignado;
}


void cFicha::set_Sesiones(vector<cSesion*> sesiones)
{
	this->Sesiones = sesiones;
}

void cFicha::set_Tumores(vector<cTumor*> tumores)
{
	this->Tumores = tumores;
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
void  cFicha:: set_Tipo_T(vector<cTerapia*>TipoS) {
		this->TipoT = TipoS;
	}
void cFicha::Agregar_Terapia(cTerapia* T) {
	if (T != NULL) {
		this->TipoT.push_back(T);
	}
}


ostream& operator<<(ostream& out, cFicha& c)
{
	out << c.to_string();
	return out;
}

