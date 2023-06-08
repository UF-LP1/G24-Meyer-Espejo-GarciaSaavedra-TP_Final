
#include "cDosimetrista.h"
#include "cPaciente.h"
cDosimetrista::cDosimetrista() {

}
cDosimetrista::~cDosimetrista(){}
void cDosimetrista:: TipoTerapiaRecibir(cPaciente MiPaciente, cTumor cMiTumor, cFicha cMiFicha) {
	eUbicacion tipo;
	vector <cTumor>TumoresPresentes; //tenes que hacer un auxiliar donde se guarden la lista de tumores del paciente  y recorrerla para sacar de cada uno la ubicacion y hacer el los if para ver que tipo de terapia
	tipo = cMiTumor.get_Ubicacion(); //esta mal tendria que ser
	TumoresPresentes = MiPaciente.get_miFicha().get_Tumores();
	if (tipo == 'ojo') {

		cMiFicha.TipoT.push_back(cBT) ;
		if (tipo == cuello)
		{
			cMiFicha.TipoT.push_back(cBT);
		}
		if (tipo == mama)
		{
			cMiFicha.TipoT.push_back(cBT)
		}
		if (tipo == utero)
		{
			cMiFicha.TipoT.push_back(cBT);
		}
		if (tipo == tiroides)
		{
			cMiFicha.TipoT.push_back(cRS)
		}
	}
	if (tipo == prostata)
	{
		if (cMiTumor.get_Tamanio() == grande) {

			cMiFicha.TipoT.push_back(cRS) ;
		}
	}


	else {
		cMiFicha.TipoT.push_back(cRTH)
	}
}

string cDosimetrista::get_Nombre() {
	return this->Nombre;
}
string cDosimetrista::get_Apellido() {
	return this->Apellido;
}
string cDosimetrista::get_ID() {
	return this->ID;
}