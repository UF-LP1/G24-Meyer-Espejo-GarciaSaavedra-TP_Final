
#include "cDosimetrista.h"
cDosimetrista::cDosimetrista( string id) {
	this->ID = id;
}
cDosimetrista::~cDosimetrista()
{}

void cDosimetrista:: TipoTerapiaRecibir( cPaciente *MiPaciente) {

	vector <cTumor*>TumoresPresentes; //tenes que hacer un auxiliar donde se guarden la lista de tumores del paciente  y recorrerla para sacar de cada uno la ubicacion y hacer el los if para ver que tipo de terapia
 //esta mal tendria que ser
 	 TumoresPresentes =  MiPaciente->get_miFicha()->get_Tumores();
	 
	 cBT* auxcbt = {};

 for(int i=0;i<TumoresPresentes.size();i++){

	 if (TumoresPresentes[i]->get_Ubicacion() == ojo) {

		 MiPaciente->get_miFicha()->Agregar_Terapia(cBT);
	 }

	 if (TumoresPresentes[i]->get_Ubicacion() == cuello)
	 {
		 if (TumoresPresentes[i]->get_Tamanio() == grande) {


			 MiPaciente->get_miFicha()->Agregar_Terapia(auxcbt);

		 }
		 else {
			 MiPaciente->get_miFicha()->Agregar_Terapia(auxcrth);
		 }
	 }
 if (TumoresPresentes[i]->get_Ubicacion() == mama)
 {
	 if (TumoresPresentes[i]->get_Tamanio() == grande) {


		 MiPaciente->get_miFicha()->Agregar_Terapia(auxcbt);

	 }
	 else {
		 MiPaciente->get_miFicha()->Agregar_Terapia(auxcrth);
	 }
           }

    if (TumoresPresentes[i]->get_Ubicacion() == utero)
  {
	if (TumoresPresentes[i]->get_Tamanio() == grande) {


		MiPaciente->get_miFicha()->Agregar_Terapia(auxcbt);

	}
	else {
		MiPaciente->get_miFicha()->Agregar_Terapia(auxcrth);
	}
       }
			if (TumoresPresentes[i]->get_Ubicacion() == tiroides)
			{

				if (TumoresPresentes[i]->get_Tamanio() == grande) {


					MiPaciente->get_miFicha()->Agregar_Terapia(auxcrs);

				}
				else {
					MiPaciente->get_miFicha()->Agregar_Terapia(auxcrth);
				}
			}
			
			if (TumoresPresentes[i]->get_Ubicacion() == prostata)
			{
				if (TumoresPresentes[i]->get_Tamanio() == grande) {

					MiPaciente->get_miFicha()->Agregar_Terapia(auxcrs);
				}
			}
			else {
				MiPaciente->get_miFicha()->Agregar_Terapia(auxcrth);
			}
	}

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
