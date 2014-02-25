#include "EnregIMU.hpp"


void EnregIMU::record(Capteur& cap) {
	cap.who(*this);
}

void EnregIMU::record(IMU& cap){
	FILE* f;
	f=fopen("Carte.txt","a");
	fprintf(f,"%f %f %f %f %f %f %f %f %f %f %f %f\n",cap.getPitchA(),cap.getRollA(),cap.getYawA(),cap.getPitchG(),cap.getRollG(),cap.getYawG(),cap.getPitchK(),cap.getRollK(),cap.getYawK(),cap.getPitchC(),cap.getRollC(),cap.getYawC());
	fclose(f);	
}
