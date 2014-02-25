#ifndef IMUCAPTEUR_HPP
#define IMUCAPTEUR_HPP

#include "Capteur.hpp"
#include "EnregIMU.hpp"

class IMU : public Capteur{
	protected : 
	//Mesure avec roll, pitch yaw.
	float antipitch;
	float antiyaw;
	float antiroll;
	int which; // de 0 = accelero, 1 = gyro, 2= Kalman à 3 = Compens à 4 = magnétmère
	
	public : 
	IMU() : Capteur(), antipitch(0), antiyaw(0), antiroll(0), which(0){
		for(int i=0;i<12;++i){
			this->mesure.push_back(0);
		}
	};

	~IMU(){
		printf("Closed\n");

	}
	virtual void setWhich(int i){which=i*3;};
	
	void setRoll(float r){this->mesure[0]=r;}
	void setPitch(float p){this->mesure[1]=p;}
	void setYaw(float y){this->mesure[2]=y;}
	
	float getRollA(){return this->mesure[0];};
	float getPitchA(){return this->mesure[1];};
	float getYawA(){return this->mesure[2];};
	
	float getRollG(){return this->mesure[3];};
	float getPitchG(){return this->mesure[4];};
	float getYawG(){return this->mesure[5];};

	float getRollK(){return this->mesure[6];};
	float getPitchK(){return this->mesure[7];};
	float getYawK(){return this->mesure[8];};
	
	float getRollC(){return this->mesure[9];};
	float getPitchC(){return this->mesure[10];};
	float getYawC(){return this->mesure[11];};
	
	float getMag(){return this->mesure[12];};
	float getTemp(){return this->mesure[13];};
	float getPress(){return this->mesure[14];};

	
	//Fonction de calibration
	void setCalib();
	void noCalib();
	float getAntipitch(){return antipitch;};
	float getAntiyaw(){return antiyaw;};
	float getAntiroll(){return antiroll;};
	float getRealpitch(){
		if(which<12){
			return this->mesure[which+1]-antipitch;
		}
		else{
			return 0;
		}
	};
	float getRealyaw(){
		if(which<12){
			return this->mesure[which+2]-antiyaw;
		}
		else{
			return this->mesure[which];
		}
	};
	float getRealroll(){if(which<12){
			return this->mesure[which]-antiroll;;
		}
		else{
			return 0;
		}
	};
	//Fonction pour demander TOUTES les mesures
	virtual void readAll();
	virtual void paint(Graph* g);
	virtual void who(Enregistreur& enr) {
		//printf("This is me\n");
		enr.record(*this);
	}
	
};

#endif
