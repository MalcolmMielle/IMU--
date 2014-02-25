#ifndef CAPTEUR_HPP
#define CAPTEUR_HPP

#include <iostream>
#include <deque>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <SerialStream.h>
#include "Graph.hpp"
#include "Global.hpp"
#include "Enregistreur.hpp"

inline double convertToDouble(std::string const& s);
#define PORT "/dev/ttyUSB0"

class Capteur{
	protected :
	std::deque<float> mesure; 
	public : 
	Capteur(){
		//Definition du stream pour lire sur l'arduinoino
		std::cout<<"Quel Baud pour le capteur ? "<<std::endl;
		int Baud=0;
		scanf("%d",&Baud);
		arduino.Open(PORT);
		if(Baud==115200){
			arduino.SetBaudRate(LibSerial::SerialStreamBuf::BAUD_115200);
		}
		else if(Baud==57600){
			arduino.SetBaudRate(LibSerial::SerialStreamBuf::BAUD_57600);
		}
		else if(Baud==9600){
			arduino.SetBaudRate(LibSerial::SerialStreamBuf::BAUD_9600);
		}
		arduino.SetCharSize(LibSerial::SerialStreamBuf::CHAR_SIZE_8);
		arduino.SetParity( LibSerial::SerialStreamBuf::PARITY_NONE ) ;
		arduino.SetFlowControl(LibSerial::SerialStreamBuf::FLOW_CONTROL_HARD ) ;
		arduino.SetNumOfStopBits(1) ;
	}
	
	virtual ~Capteur(){
		arduino.Close();
		printf("Closed\n");
	}
	virtual std::deque<float>& getMesure(){return mesure;};
	virtual void readAll()=0;
	virtual void paint(Graph* g)=0;
	virtual void who(Enregistreur& enr) =0;
	virtual void setCalib()=0;
	virtual void noCalib()=0;
	virtual void setWhich(int i)=0;//Determine la mesure que l'on lis

};

class BadConversion : public std::runtime_error {
	public:
	BadConversion(std::string const& s) 
	: std::runtime_error(s){}
};
 
 
inline double convertToDouble(std::string const& s)
{
	std::istringstream iss(s);
	double x;
	iss>>x;
	//std::cout<<"Prout "<<iss<< " et on a " <<x <<std::endl;
	//if (!(iss >> x))
	//throw BadConversion("convertToDouble(\"" + s + "\")");
	return x;
}

#endif
