#include "Header.h"
#include "cOncologo.h"
#include "cPaciente.h"
#include "cDosimetrista.h"

int main() {
	string nombre;
	string sexo;
	string contacto;
	string tiposangre;
	float salud;
/*
	cout << "Ingrese nombre paciente " << endl;
	cin >> nombre;
	cout << "Ingrese sexo paciente " << endl;
	cin >> sexo;
	cout << "Ingrese contacto paciente " << endl;
	cin >> contacto;
	cout << "Ingrese tipo de sangre paciente " << endl;
	cin >> tiposangre;
	cout << "Ingrese salud paciente " << endl;
	cin >> salud;*/

	//cPaciente* paciente1 = new cPaciente(nombre, sexo, contacto, tiposangre,salud);
	cPaciente* paciente2 = new cPaciente("saul", "M", "1234", "0-", 0.7);
	cFicha* fichapaciente1 = new cFicha();

	paciente2->set_miFicha(fichapaciente1); //le setteo la ficha al paciente

	cOncologo* oncologo1 = new cOncologo("2345");

	oncologo1->AtenderPaciente(paciente2); //actualiza los tumores;y sus caraceristicas en la ficha; en base a estudios

	
	//para probar ese metodo imprimo en pantalla y de paso uso la sobrecarga<<
	if (fichapaciente1 != nullptr) {
		cout << "hola";
		cout << *fichapaciente1 << endl; //sobrecarga q llama al to-string - - - - - - - -
	}
	
	//!!!!!!!!!!!!!!Problema con la memoria, creo que variables de TERAPIA


	oncologo1->VerificarFecha(paciente2); //desp lo verifico pero primero tengo que hacer atendercliente
	cDosimetrista* Dosimetrista1 = new cDosimetrista("1234");

	Dosimetrista1->TipoTerapiaRecibir(paciente2);

	return 0;
}