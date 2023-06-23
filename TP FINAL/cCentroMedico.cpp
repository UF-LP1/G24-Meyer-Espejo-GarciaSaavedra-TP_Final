#include "cCentroMedico.h"

cCentroMedico::cCentroMedico(string nombre, string direccion, string telefono) {
	this->Nombre = nombre;
	this->Direccion = direccion;
	this->Telefono = telefono;
}

cCentroMedico::~cCentroMedico() {
	for (cPaciente* aux : this->Pacientes) {
		if (aux != NULL)
		{
			delete aux;
		}
	}
}

void cCentroMedico::AsistenciaPaciente(cPaciente* miPaciente) {
	vector<cSesion*> SesionesPaciente = miPaciente->get_miFicha()->get_Sesiones();
	int contInasistencia = 0;
	for (int i = 0; i < SesionesPaciente.size(); i++)
	{
		if (SesionesPaciente[i]->get_Asist() == false)
		{
			contInasistencia++;
		}
	}

	if (contInasistencia != 0)//falto por lo menos una vez
	{
		//comunicarme con el paciente y ver si continua con el tratamiento
		miPaciente->get_Contacto();
		int aux = rand() % 2;
		if (aux == 2) // considero que no va a seguir con el tratamiento
		{
			//le doy por finalizado el tratamiento
			miPaciente->get_miFicha()->set_Finalizado(true);
		}
	}

}
string cCentroMedico::to_string() {
	{
		stringstream ss;
		ss << "El centro medico" << this->Nombre << "se encuentra en" << this->Direccion << ",para contactarse puede utilizar este numero:" << this->Telefono;
		return(ss.str());
	}
}
vector<cPaciente*> cCentroMedico::get_Pacientes()
{
	return this->Pacientes;
}

void cCentroMedico::buscar(cPaciente* paciente)
{
	bool encontrado = false;

	for (int i = 0; i < Pacientes.size(); i++)
	{
		if (Pacientes[i] == paciente)
		{
			encontrado = true;
		}

	}
	if (encontrado == false)
	{
		throw exPacienteNoEncontrado();
	}

}

void cCentroMedico::operator+(cPaciente* paciente)
{
		this->Pacientes.push_back(paciente);
}


vector<cPaciente*> cCentroMedico::buscarXTumor(eUbicacion ubi)
{
	vector<cPaciente*>encontrados;
	for (int i = 0; i < Pacientes.size(); i++) //recorro pacientes
	{
		int tam = Pacientes[i]->get_miFicha()->get_Tumores().size();
		for (int j = 0; j < tam; j++) //recorro su lista de tumores
		{
			vector<cTumor*>Tumores = Pacientes[i]->get_miFicha()->get_Tumores();
			eUbicacion suUbicacion = Tumores[i]->get_Ubicacion();
			if (suUbicacion == ubi)
			{
				encontrados.push_back(Pacientes[i]);
			}
		}
	}
	return encontrados;

}

vector<cPaciente*> cCentroMedico::buscarXTratamiento(eTratamiento tratamiento)
{
	vector<cPaciente*>encontrados;
	for (int i = 0; i < Pacientes.size(); i++) //recorro pacientes
	{
		int tam = Pacientes[i]->get_miFicha()->get_Tumores().size();
		for (int j = 0; j < tam; j++) //recorro su lista de tumores
		{
			vector<cTumor*>Tumores = Pacientes[i]->get_miFicha()->get_Tumores();
			eTratamiento suTratamiento = Tumores[i]->get_terapia()->get_expecificoTratamiento();
			if (suTratamiento == tratamiento)
			{
				encontrados.push_back(Pacientes[i]);
			}
		}
	}
	return encontrados;

}

vector<cPaciente*> cCentroMedico::a5DeSobredosis()
{
	vector<cPaciente*>encontrados;

	float acum = 0;
	for (int i = 0; i < Pacientes.size(); i++) //recorro a los pacientes
	{
		int tam = Pacientes[i]->get_miFicha()->get_Tumores().size();

		for (int j = 0; j < tam; j++)
		{
			vector<cTumor*>tumores = Pacientes[i]->get_miFicha()->get_Tumores();
			cTerapia* tratamiento = tumores[j]->get_terapia();
			if (dynamic_cast<cRTH*>(tratamiento) != NULL) {
				acum = (float)tumores[j]->get_AcumRadiacion() * 100 / 60; //60 dosis max en tumores para cRTH
			}
			else if (dynamic_cast<cBT*>(tratamiento) != NULL) {
				acum = (float)tumores[j]->get_AcumRadiacion() * 100 / 150; //150 dosis max en tumores para cBT
			}
			else if (dynamic_cast<cRS*>(tratamiento) != NULL) {
				acum = (float)tumores[j]->get_AcumRadiacion() * 100 / 60; //60 dosis max en tumores para cRS
			}

			if (acum > 95) //esta por alcanzar ese 5%
			{
				encontrados.push_back(Pacientes[i]);
			}
		}
	}

	return encontrados;
}

ostream& operator<<(ostream& OUT, cCentroMedico& centroM) {
	OUT << centroM.to_string() << endl;
	return OUT;

}

