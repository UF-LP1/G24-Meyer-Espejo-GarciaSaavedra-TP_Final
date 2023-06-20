#include "Header.h"
#include "cOncologo.h"
#include "cPaciente.h"

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

	//crear tumores que tenga el paciente
	cTumor* tumor1 = new cTumor();
	cTumor* tumor2 = new cTumor();
	cTumor* tumor3 = new cTumor();

	vector<cTumor*>TumoresPaciente;
	TumoresPaciente.push_back(tumor1);
	TumoresPaciente.push_back(tumor2);
	TumoresPaciente.push_back(tumor3);

	paciente1->get_miFicha()->set_Tumores(TumoresPaciente); //se los agrego a su ficha la lista de tumores del paciente
	
	cOncologo* oncologo1 = new cOncologo(2345);

	oncologo1->AtenderPaciente(paciente1); //actualiza los tumores;y sus caraceristicas en la ficha; en base a estudios

	//para probar ese metodo imprimo en pantalla y de paso uso la sobrecarga<<
	cout << fichapaciente1 << endl; //sobrecarga q llama al to-string




	oncologo1->VerificarFecha(paciente1); //desp lo verifico pero primero tengo que hacer atendercliente












	return 0;
}