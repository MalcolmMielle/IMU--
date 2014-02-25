#ifndef ENREGISTREUR_HPP
#define ENREGISTREUR_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <SerialStream.h>
#include "Graph.hpp"
#include "Global.hpp"
class Capteur;

class Enregistreur{
	public : 
	Enregistreur(){};
	virtual void record(Capteur& cap) =0;
	virtual void record(IMU& cap) =0;
};

#endif
