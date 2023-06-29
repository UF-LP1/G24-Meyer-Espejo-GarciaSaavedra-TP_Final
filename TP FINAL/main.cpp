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

	
	oncologo1->AtenderPaciente(paciente2);
	dosimetrista1->TipoTerapiaRecibir(paciente2);
	oncologo1->DosisXSesion(paciente2);
	oncologo1->Evaluacion(paciente2);
	CentroMedico->AsistenciaPaciente(paciente2);
	dosimetrista1->RadTotalPaciente(paciente2);
	oncologo1->VerifySesion(paciente2);
	
	
	cout << *paciente2;

	///////////////////////////////////////////////////////
	//primer paciente
	oncologo2->AtenderPaciente(paciente1);
	dosimetrista1->TipoTerapiaRecibir(paciente1);
	oncologo2->DosisXSesion(paciente1);
	oncologo2->Evaluacion(paciente1);
	CentroMedico->AsistenciaPaciente(paciente1);
	dosimetrista1->RadTotalPaciente(paciente1);
	oncologo2->VerifySesion(paciente1);



	///////////////////////////////////////////
	//tercer paciente
	oncologo1->AtenderPaciente(paciente3);
	dosimetrista1->TipoTerapiaRecibir(paciente3);
	oncologo1->DosisXSesion(paciente3);
	oncologo1->Evaluacion(paciente3);
	CentroMedico->AsistenciaPaciente(paciente2);
	dosimetrista1->RadTotalPaciente(paciente2);
	oncologo1->VerifySesion(paciente3);

	//////////////////////////////////////////////
	//cuarto paciente
	oncologo2->AtenderPaciente(paciente4);
	dosimetrista1->TipoTerapiaRecibir(paciente4);
	oncologo2->DosisXSesion(paciente4);
	oncologo2->Evaluacion(paciente4);
	CentroMedico->AsistenciaPaciente(paciente1);
	dosimetrista1->RadTotalPaciente(paciente1);
	oncologo2->VerifySesion(paciente4);

	try {
		cout << "La lista de Pacientes que estan a 5% de sobredosis son:" << endl;
		vector<cPaciente*>Pacientesexpecificos=CentroMedico->a5DeSobredosis();
		for (int i = 0; i < Pacientesexpecificos.size(); i++)
		{
			cout << Pacientesexpecificos[i]->get_Nombre()<<endl;
		}
		
	}
	catch (exSobredosis5porciento& e) {
		cout << e.what() << endl;
		}

	/*try {
		cout << "La lista de Pacientes que estan con las indicaciones de ubicacion utero y tratamiento branquiterapia" << endl;
		vector<cPaciente*>Pacientesexpecificos;

		Pacientesexpecificos=CentroMedico->buscarXTumoryTerapia(cuello, branquiterapia);

		for (int i = 0; i < Pacientesexpecificos.size(); i++)
		{
			cout << Pacientesexpecificos[i]->get_Nombre() << endl;
		}

	}*/
	/*catch(exNohayNingunCaso&e){
		cout << e.what() << endl;
	}*/
	

	cPaciente* paciente5 = new cPaciente("cata", "F", "9875", "0-", 0.9); //no lo agrego al centro asi veo si salta el error
	try {
		CentroMedico->buscar(paciente5);

	}
	catch (exPacienteNoEncontrado& e)
	{
		cout << e.what() << endl;

	}

	*CentroMedico - paciente1;
	*CentroMedico - paciente2;
	*CentroMedico - paciente3;
	*CentroMedico - paciente4;

	delete paciente1;
	delete paciente2;
	delete paciente3;
	delete paciente4;
	delete paciente5;
	delete dosimetrista1;
	delete oncologo1;
	delete oncologo2;
	delete CentroMedico;

	return 0;
}