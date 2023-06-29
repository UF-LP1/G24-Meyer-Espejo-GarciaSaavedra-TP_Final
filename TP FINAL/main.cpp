#include "Header.h"
#include "cOncologo.h"
#include "cPaciente.h"
#include "cDosimetrista.h"
#include "cCentroMedico.h"
#include "exception.h"


int main() {
	cPaciente* paciente1 = new cPaciente("marti", "F", "876", "A+", 0.1);
	cPaciente* paciente2 = new cPaciente("saul", "M", "1234", "0-", 0.1);



	//creo el centro medico
	cCentroMedico* CentroMedico = new cCentroMedico("Alfa", "Sarmiento 164", "1234");

	//agrego a estos pacientes con la sobrecarga +
	*CentroMedico + paciente1;
	*CentroMedico + paciente2;


	cOncologo* oncologo1 = new cOncologo("2345");
	cOncologo* oncologo2 = new cOncologo("0023");
	cDosimetrista* dosimetrista1 = new cDosimetrista("345");

	//corregidos
	oncologo1->AtenderPaciente(paciente2);
	dosimetrista1->TipoTerapiaRecibir(paciente2);
	oncologo1->DosisXSesion(paciente2);
	//CentroMedico->AsistenciaPaciente(paciente2);
 //  dosimetrista1->RadTotalPaciente(paciente2);





   //no puedo corroborar el try catch porque necesito los metodos que tienen problema en try catch
	try {
		oncologo1->VerificarSobredosis(paciente2);
	}
	catch (exception& e)
	{
		cout << e.what();
	}

	//CentroMedico->a5DeSobredosis(); //error salta de leer memoria que no existe
	oncologo1->VerificarFecha(paciente2); //no lo ppuede verificar porque no entro en el if para llamar a Evaluar

	//ver q funcionen
	//CentroMedico->buscarXTumor(utero, branquiterapia);
	CentroMedico->buscarXTumoryTerapia(utero, branquiterapia);

	//cout << *paciente1;
	cout << *paciente2;

	delete paciente1;
	delete paciente2;
	delete dosimetrista1;
	delete oncologo1;
	delete oncologo2;

	return 0;
}