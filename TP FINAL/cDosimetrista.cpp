
#include "cDosimetrista.h"
cDosimetrista::cDosimetrista() {

}
cDosimetrista::~cDosimetrista(){}



void cDosimetrista:: TipoTerapiaRecibir( cPaciente *MiPaciente) {

	vector <cTumor>TumoresPresentes; //tenes que hacer un auxiliar donde se guarden la lista de tumores del paciente  y recorrerla para sacar de cada uno la ubicacion y hacer el los if para ver que tipo de terapia
 //esta mal tendria que ser
 	 TumoresPresentes =  MiPaciente->get_miFicha().get_Tumores();
	 

 for(int i=0;i<TumoresPresentes.size();i++){

	 if (TumoresPresentes[i].get_Ubicacion() == ojo) {

		 MiPaciente->get_miFicha().get_Terapia().push_back(cBT);
	 }

	 if (TumoresPresentes[i].get_Ubicacion() == cuello)
	 {
		 if (TumoresPresentes[i].get_Tamanio() == grande) {


			 MiPaciente->get_miFicha().get_Terapia().push_back(cBT);

		 }
		 else {
			 MiPaciente->get_miFicha().get_Terapia().push_back(cRTH);
		 }
	 }
 if (TumoresPresentes[i].get_Ubicacion() == mama)
 {
	 if (TumoresPresentes[i].get_Tamanio() == grande) {


		 MiPaciente->get_miFicha().get_Terapia().push_back(cBT);

	 }
	 else {
		 MiPaciente->get_miFicha().get_Terapia().push_back(cRTH);
	 }
           }

    if (TumoresPresentes[i].get_Ubicacion() == utero)
  {
	if (TumoresPresentes[i].get_Tamanio() == grande) {


		MiPaciente->get_miFicha().get_Terapia().push_back(cBT);

	}
	else {
		MiPaciente->get_miFicha().get_Terapia().push_back(cRTH);
	}
       }
			if (TumoresPresentes[i].get_Ubicacion() == tiroides)
			{

				if (TumoresPresentes[i].get_Tamanio() == grande) {


					MiPaciente->get_miFicha().get_Terapia().push_back(cRS);

				}
				else {
					MiPaciente->get_miFicha().get_Terapia().push_back(cRTH);
				}
			}
			

			if (TumoresPresentes[i].get_Ubicacion() == prostata)
			{
				if (TumoresPresentes[i].get_Tamanio() == grande) {

					MiPaciente->get_miFicha().get_Terapia().push_back(cRS);
				}
			}


			else {
				MiPaciente->get_miFicha().get_Terapia().push_back(cRTH);
			}
	}

}



int CalcularDosisMax(cPaciente *MiPaciente) {
	vector <cTumor>TumoresPresentes;











}//falta hacer







int CalcularRadiacionTotal(cPaciente* MiPaciente) {

	vector <cTerapia*> RadiacionTerapia;
	RadiacionTerapia = MiPaciente->get_miFicha().get_Terapia();
	vector <cTumor>RadiacionTumor;
	RadiacionTumor = MiPaciente->get_miFicha().get_Tumores();
	int radTP = 0;
	int radTT = 0;
	for (int i = 0; i < RadiacionTerapia.size(); i++) {
		cBT* auxcBT = dynamic_cast <cBT*> (RadiacionTerapia[i]);
		//todo es de paciente,nada por tumor

		if (auxcBT != NULL) {
			radTP = radTP + 180;//aca se calculo en paciente
			radTT = radTT + (RadiacionTumor[i].get_AcumRadiacion() * (0.6));//aca se calcula en tumor
		}
		cRTH* auxcRTH = dynamic_cast <cRTH*> (RadiacionTerapia[i]);
		if (auxcRTH != NULL) {
			radTP = radTP + 100;//aca se calcula en paciente
			radTT = radTT + (RadiacionTumor[i].get_AcumRadiacion()) * (0.3);//aca se calcula en tumor
		}

		cRS* auxcRS = dynamic_cast <cRS*> (RadiacionTerapia[i]);
		if (auxcRS != NULL)
		{
			radTP = radTP + 100;//aca se calcula en paciente
			radTT = radTT + (RadiacionTumor[i].get_AcumRadiacion() * (0.1));//aca se calcula en tumor
		}
	}
		radTP = radTP + radTT;//se calcula la total


		if (radTP > 100) {//el minimo maximo es 100Gy
			return false;
		}
		else {
			return true;

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
