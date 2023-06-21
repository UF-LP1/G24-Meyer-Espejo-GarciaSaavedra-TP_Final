#include "cCentroMedico.h"

cCentroMedico::cCentroMedico(string nombre, string direccion, string telefono) {
	this->Nombre = nombre;
	this->Direccion = direccion;
	this->Telefono = telefono;
}

cCentroMedico::~cCentroMedico(){}

void cCentroMedico::AsistenciaPaciente(cPaciente *miPaciente) {
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
ostream& operator<<(ostream& OUT, cCentroMedico& centroM) {
	OUT << centroM.to_string() << endl;
	return OUT;
}

