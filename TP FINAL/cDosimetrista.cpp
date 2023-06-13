
#include "cDosimetrista.h"
#include "cPaciente.h"
cDosimetrista::cDosimetrista() {

}
cDosimetrista::~cDosimetrista(){}
void cDosimetrista:: TipoTerapiaRecibir( cPaciente MiPaciente) {

	vector <cTumor>TumoresPresentes; //tenes que hacer un auxiliar donde se guarden la lista de tumores del paciente  y recorrerla para sacar de cada uno la ubicacion y hacer el los if para ver que tipo de terapia
 //esta mal tendria que ser
 	 TumoresPresentes =  MiPaciente.get_miFicha().get_Tumores();

 for(int i=0;i<TumoresPresentes.size();i++){

	 if (TumoresPresentes[i].get_Ubicacion() == ojo) {

		 MiPaciente.get_miFicha().get_Terapia().push_back(cBT);
	 }

	 if (TumoresPresentes[i].get_Ubicacion() == cuello)
	 {
		 if (TumoresPresentes[i].get_Tamanio() == grande) {


			 MiPaciente.get_miFicha().get_Terapia().push_back(cBT);

		 }
		 else {
			 MiPaciente.get_miFicha().get_Terapia().push_back(cRH);
		 }
	 }
 


 if (TumoresPresentes[i].get_Ubicacion() == mama)
 {
	 if (TumoresPresentes[i].get_Tamanio() == grande) {


		 MiPaciente.get_miFicha().get_Terapia().push_back(cBT);

	 }
	 else {
		 MiPaciente.get_miFicha().get_Terapia().push_back(cRH);
	 }
           }

    if (TumoresPresentes[i].get_Ubicacion() == utero)
  {
	if (TumoresPresentes[i].get_Tamanio() == grande) {


		MiPaciente.get_miFicha().get_Terapia().push_back(cBT);

	}
	else {
		MiPaciente.get_miFicha().get_Terapia().push_back(cRH);
	}
       }
			



			if (TumoresPresentes[i].get_Ubicacion() == tiroides)
			{

				if (TumoresPresentes[i].get_Tamanio() == grande) {


					MiPaciente.get_miFicha().get_Terapia().push_back(cRS);

				}
				else {
					MiPaciente.get_miFicha().get_Terapia().push_back(cRTH);
				}
			}
			

			if (TumoresPresentes[i].get_Ubicacion() == prostata)
			{
				if (TumoresPresentes[i].get_Tamanio() == grande) {

					MiPaciente.get_miFicha().get_Terapia().push_back(cRS);
				}
			}


			else {
				MiPaciente.get_miFicha().get_Terapia().push_back(cRTH);
			}
	}

}
int CalcularDosisMax(cPaciente MiPaciente) {
	// Radiacion_paciente = Tumores_RTPHazExterno * 0.3 + Tumores_Braquiterapia * 0.6
	//+Tumores_Sistemico * 0.1











}
int CalcularRadiacionTotal();

string cDosimetrista::get_Nombre() {
	return this->Nombre;
}
string cDosimetrista::get_Apellido() {
	return this->Apellido;
}
string cDosimetrista::get_ID() {
	return this->ID;
}
