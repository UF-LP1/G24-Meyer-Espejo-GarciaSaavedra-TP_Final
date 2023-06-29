#include "Header.h"
#include "cOncologo.h"
#include "cPaciente.h"
#include "cDosimetrista.h"
#include "cCentroMedico.h"
#include "exception.h"


int main() {
	cPaciente* paciente1 = new cPaciente("marti", "F", "876", "A+", 0.1);
	cPaciente* paciente2 = new cPaciente("saul", "M", "1234", "0-", 0.1);
	cPaciente* paciente3 = new cPaciente("nica", "M", "1233", "AB+",0.6);
	cPaciente* paciente4 = new cPaciente("mate", "M", "456", "0+", 0.7);



	//creo el centro medico
	cCentroMedico* CentroMedico = new cCentroMedico("Alfa", "Sarmiento 164", "1234");

	//agrego a estos pacientes con la sobrecarga +
	*CentroMedico + paciente1;
	*CentroMedico + paciente2;
	*CentroMedico + paciente3;
	*CentroMedico + paciente4;

	cOncologo* oncologo1 = new cOncologo("2345");
	cOncologo* oncologo2 = new cOncologo("0023");
	cDosimetrista* dosimetrista1 = new cDosimetrista("345");

	//corregidos
	oncologo1->AtenderPaciente(paciente2);
	dosimetrista1->TipoTerapiaRecibir(paciente2);
	oncologo1->DosisXSesion(paciente2);
	oncologo1->Evaluacion(paciente2);
	//CentroMedico->AsistenciaPaciente(paciente2);
 //  dosimetrista1->RadTotalPaciente(paciente2);
	oncologo1->VerifySesion(paciente2);
	CentroMedico->buscarXTumoryTerapia(utero, branquiterapia);

	CentroMedico->a5DeSobredosis(); 
	
	cout << *paciente2;

	///////////////////////////////////////////////////////
	//primer paciente
	oncologo2->AtenderPaciente(paciente1);
	dosimetrista1->TipoTerapiaRecibir(paciente1);
	oncologo2->DosisXSesion(paciente1);
	oncologo2->Evaluacion(paciente1);
	//CentroMedico->AsistenciaPaciente(paciente1);
 //  dosimetrista1->RadTotalPaciente(paciente1);
	oncologo2->VerifySesion(paciente1);
	///////////////////////////////////////////
	//tercer paciente
	oncologo1->AtenderPaciente(paciente3);
	dosimetrista1->TipoTerapiaRecibir(paciente3);
	oncologo1->DosisXSesion(paciente3);
	oncologo1->Evaluacion(paciente3);
	//CentroMedico->AsistenciaPaciente(paciente2);
 //  dosimetrista1->RadTotalPaciente(paciente2);
	oncologo1->VerifySesion(paciente3);
	//////////////////////////////////////////////
	//cuarto paciente
	oncologo2->AtenderPaciente(paciente4);
	dosimetrista1->TipoTerapiaRecibir(paciente4);
	oncologo2->DosisXSesion(paciente4);
	oncologo2->Evaluacion(paciente4);
	//CentroMedico->AsistenciaPaciente(paciente1);
 //  dosimetrista1->RadTotalPaciente(paciente1);
	oncologo2->VerifySesion(paciente4);






	delete paciente1;
	delete paciente2;
	delete paciente3;
	delete paciente4;
	delete dosimetrista1;
	delete oncologo1;
	delete oncologo2;

	return 0;
}