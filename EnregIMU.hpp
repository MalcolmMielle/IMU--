#ifndef ENREGISTREURIMU_HPP
#define ENREGISTREURIMU_HPP

#include "Enregistreur.hpp"
#include "IMU.hpp"

class EnregIMU : public Enregistreur{
	public : 
	EnregIMU(){};
	virtual void record(Capteur& cap) ;
	virtual void record(IMU& cap) ;
};

#endif
