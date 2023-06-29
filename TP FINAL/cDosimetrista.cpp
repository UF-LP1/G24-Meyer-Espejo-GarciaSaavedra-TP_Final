#include "cDosimetrista.h"
cDosimetrista::cDosimetrista(string id):ID(id){}

cDosimetrista::~cDosimetrista()
{}

void cDosimetrista::TipoTerapiaRecibir(cPaciente* MiPaciente) { //termino mañana

	vector <cTumor*> TumoresPresentes;
	TumoresPresentes = MiPaciente->get_miFicha()->get_Tumores();

	for (int i = 0; i < TumoresPresentes.size(); i++) {
		cTerapia* terapia= new cRS(mediano);
		eUbicacion Ubi = TumoresPresentes[i]->get_Ubicacion();
		eTamanio Size = TumoresPresentes[i]->get_Tamanio();

		if (Ubi == ojo) {
			delete terapia;
			terapia = new cBT(TumoresPresentes[i]->get_Tamanio());
		}
		else if (Ubi == mama || Ubi == cuello || Ubi == utero) {
			if (Size == grande) {
				delete terapia;
				terapia = new cBT(grande);
			}
			else {
				delete terapia;
				terapia = new cRS(TumoresPresentes[i]->get_Tamanio()); //ya que puede ser mediano o chico
			}
		}
		else if (Ubi == tiroides || Ubi == prostata || Ubi == pulmon) {
			if (Size == grande) {
				delete terapia;
				terapia = new cRS(grande);
			}
			else {
				delete terapia;
				terapia = new cRTH(TumoresPresentes[i]->get_Tamanio());
			}
		}

		TumoresPresentes[i]->set_Terapia(terapia);
		
	}

	//SOLO EN ESE UTLIZO SISTEMATICA

	/*if (Ubi == tiroides || Ubi == prostata || Ubi == pulmon) {
		if (Size == grande) {

			TumoresPresentes[i]->set_Terapia(diagnosticoRS);
			terapiaaux.push_back(diagnosticoRS);*/




	/*vector <cTumor*> TumoresPresentes; 
	TumoresPresentes = MiPaciente->get_miFicha()->get_Tumores();
	vector<cTerapia*> terapiaaux;
	cTerapia* diagnosticoBT = new cBT;
	cTerapia* diagnosticoRS = new cRS;
	cTerapia* diagnosticoRTH = new cRTH;
	
	for (int i = 0; i < TumoresPresentes.size(); i++) {
		eUbicacion Ubi = TumoresPresentes[i]->get_Ubicacion();
		eTamanio Size = TumoresPresentes[i]->get_Tamanio();
		if (Ubi == ojo) {
			TumoresPresentes[i]->set_Terapia(diagnosticoBT);
			terapiaaux.push_back(diagnosticoBT);
		}
		if (Ubi == mama || Ubi == cuello || Ubi == utero) {
			if (Size == grande) {
				TumoresPresentes[i]->set_Terapia(diagnosticoBT);
				terapiaaux.push_back(diagnosticoBT);
			}
			else
			{
				TumoresPresentes[i]->set_Terapia(diagnosticoRTH);
				terapiaaux.push_back(diagnosticoRTH);
			}
		}
		if (Ubi == tiroides || Ubi == prostata ||Ubi == pulmon) {
			if (Size == grande) {
			
				TumoresPresentes[i]->set_Terapia(diagnosticoRS);
				terapiaaux.push_back(diagnosticoRS);
			}
			else {
				TumoresPresentes[i]->set_Terapia(diagnosticoRTH);
				terapiaaux.push_back(diagnosticoRTH);
			}
		}
	}

	MiPaciente->get_miFicha()->set_Terapia(terapiaaux);
	delete diagnosticoBT;
	delete diagnosticoRS;
	delete diagnosticoRTH;*/
}

int cDosimetrista::RadTotalPaciente(cPaciente* MiPaciente) {

	vector <cTerapia*> RadiacionTerapia;
	RadiacionTerapia = MiPaciente->get_miFicha()->get_Terapias();
	float radTP = 0.0; //por terapia paciente
	int cont = 0;
	
	for (int i = 0; i < RadiacionTerapia.size(); i++) {

		cBT* auxcBT=dynamic_cast<cBT*> (RadiacionTerapia[i]);
		cRTH* auxcRTH = dynamic_cast<cRTH*> (RadiacionTerapia[i]);
		if (auxcBT!=NULL || auxcRTH != NULL) {//seria radioterapia haz externo o sistematica
			cont++;
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
