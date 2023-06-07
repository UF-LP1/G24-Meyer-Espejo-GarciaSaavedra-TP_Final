
#include "cDosimetrista.h"
#include "cPaciente.h"
cDosimetrista::cDosimetrista() {

}
cDosimetrista::~cDosimetrista(){}
void cDosimetrista:: TipoTerapiaRecibir(cPaciente cMiPaciente, cTumor cMiTumor, cFicha cMiFicha) {
	eUbicacion tipo;
	tipo = cMiTumor.get_Ubicacion();
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