#include "cCentroMedico.h"

cCentroMedico::cCentroMedico() {

}

cCentroMedico::~cCentroMedico(){}

void cCentroMedico::AsistenciaPaciente(cPaciente miPaciente) {
	vector<cSesion> SesionesPaciente = miPaciente.get_miFicha().get_Sesiones();
	int contInasistencia = 0;
	for (int i = 0; i < SesionesPaciente.size(); i++)
	{
		if (SesionesPaciente[i].get_Asist() == false)
		{
			contInasistencia++;
		}
	}

	if (contInasistencia != 0)//falto por lo menos una vez
	{
		//comunicarme con el paciente y ver si continua con el tratamiento
		miPaciente.get_Contacto();

	}

}