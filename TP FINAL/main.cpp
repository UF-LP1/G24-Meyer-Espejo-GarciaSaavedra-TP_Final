#include "Header.h"
#include "cOncologo.h"
#include "cPaciente.h"
#include "cDosimetrista.h"
#include "cCentroMedico.h"


int main() {
	cPaciente* paciente1 = new cPaciente("marti", "F", "876", "A+", 0.1);
	cPaciente* paciente2 = new cPaciente("saul", "M", "1234", "0-", 0.7);



	//creo el centro medico
	cCentroMedico* CentroMedico = new cCentroMedico("Alfa", "Sarmiento 164", "1234");

	//agrego a estos pacientes con la sobrecarga +
	*CentroMedico + paciente1;
	*CentroMedico + paciente2;


	cOncologo* oncologo1 = new cOncologo("2345");
	cOncologo* oncologo2 = new cOncologo("0023");
	cDosimetrista* dosimetrista1 = new cDosimetrista("345"); 

	oncologo1->AtenderPaciente(paciente2); //actualiza los tumores;y sus caraceristicas en la ficha; en base a estudios
	
	//ver q funcionen
	oncologo1->DosisXSesion(paciente2);
	dosimetrista1->TipoTerapiaRecibir(paciente2);
	dosimetrista1->RadTotalPaciente(paciente2);
	oncologo1->VerificarSobredosis(paciente2); //tiene que estar dentro de un bloque de try catch
	oncologo1->VerificarFecha(paciente2);


	





	//cout << *paciente1;
	cout << *paciente2;




	delete paciente1;
	delete paciente2;
	delete dosimetrista1;
	delete oncologo1;
	delete oncologo2;

	return 0;
}