#include "cDosimetrista.h"
cDosimetrista::cDosimetrista() {}

cDosimetrista::~cDosimetrista()
{}

void cDosimetrista::TipoTerapiaRecibir(cPaciente* MiPaciente) {

	vector <cTumor*>TumoresPresentes; //tenes que hacer un auxiliar donde se guarden la lista de tumores del paciente  y recorrerla para sacar de cada uno la ubicacion y hacer el los if para ver que tipo de terapia
	//esta mal tendria que ser
	TumoresPresentes = MiPaciente->get_miFicha()->get_Tumores();

	cTerapia* diagnosticoBT = new cBT;
	cTerapia* diagnosticoRS = new cRS;
	cTerapia* diagnosticoRTH = new cRTH;

	for (int i = 0; i < TumoresPresentes.size(); i++) {
		eUbicacion Ubi = TumoresPresentes[i]->get_Ubicacion();
		eTamanio Size = TumoresPresentes[i]->get_Tamanio();
		if (Ubi == ojo) {
			TumoresPresentes[i]->set_Terapia(diagnosticoBT);
		}
		if (Ubi == mama || Ubi == cuello || Ubi == utero) {
			if (Size == grande) {
				TumoresPresentes[i]->set_Terapia(diagnosticoBT);
			}
			else
			{
				TumoresPresentes[i]->set_Terapia(diagnosticoRTH);
			}
		}
		if (Ubi == tiroides || Ubi == prostata) {
			if (Size == grande) {
			
				TumoresPresentes[i]->set_Terapia(diagnosticoRS);
			}
			else {
				TumoresPresentes[i]->set_Terapia(diagnosticoRTH);
			}
		}
	}
	delete diagnosticoBT;
	delete diagnosticoRS;
	delete diagnosticoRTH;
}

//bool cDosimetrista::CalcularDosisTotalTumor(cPaciente* MiPaciente) {
//	vector <cTumor*>TumoresPresentes;
//
//	return false;
//}


int cDosimetrista::RadTotalPaciente(cPaciente* MiPaciente) {

	vector <cTerapia*> RadiacionTerapia;
	RadiacionTerapia = MiPaciente->get_miFicha()->get_Terapia();
	float radTP = 0.0; //por terapia paciente
	int cont = 0;
	for (int i = 0; i < RadiacionTerapia.size(); i++) {
		cBT* auxcBT = dynamic_cast <cBT*> (RadiacionTerapia[i]);
		//todo es de paciente,nada por tumor

		if (auxcBT == NULL) {//seria radioterapia haz externo o sistematica
			cont++;
	    	//diversion!!
		}	
	}
	if (cont == 0) {
		radTP = 180;//solo hay terapia de braquiterapia
	}
	else {
		radTP = 100;//hay por lo menos una,de haz externo o sistematica
	}	
	MiPaciente->get_miFicha()->set_RadiacionMaxP(radTP);
	return(radTP);
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
