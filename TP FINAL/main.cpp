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

	cout << "Ingrese nombre paciente";
	cin >> nombre;
	cout << "Ingrese sexo paciente";
	cin >> sexo;
	cout << "Ingrese contacto paciente";
	cin >> contacto;
	cout << "Ingrese tipo de sangre paciente";
	cin >> tiposangre;
	cout << "Ingrese salud paciente";
	cin >> salud;

	cPaciente* paciente1 = new cPaciente(nombre, sexo, contacto, tiposangre,salud);
	cFicha* fichapaciente1 = new cFicha();

	paciente1->set_miFicha(fichapaciente1); //le setteo la ficha al paciente

	

	
	
	cOncologo* oncologo1 = new cOncologo("2345");

	oncologo1->AtenderPaciente(paciente1); //actualiza los tumores;y sus caraceristicas en la ficha; en base a estudios

	//para probar ese metodo imprimo en pantalla y de paso uso la sobrecarga<<
	cout << fichapaciente1 << endl; //sobrecarga q llama al to-string




	oncologo1->VerificarFecha(paciente1); //desp lo verifico pero primero tengo que hacer atendercliente

	
	cDosimetrista* Dosimetrista1=new cDosimetrista();

	Dosimetrista1->TipoTerapiaRecibir(paciente1);
	return 0;
}