#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <cstdlib>
#include "math.h"

class Point{
	//Attributs
	protected : 
	float _r;
	float _teta;
	float _phi;
	//Méthodes
	public : 
	Point(){};
	Point(float r, float teta, float phi) : _r(r), _teta(teta), _phi(phi){};
	void setR(float r){
		_r=r;
	}
	void setT(float teta){
		_teta=teta;
	}
	void setP(float phi){
		_phi=phi;
	}
	void move(float teta, float phi){	
		_teta=teta+_teta;
		_phi=phi+_phi;
	}
	float getX(){return _r*cos(_teta)*cos(_phi);};
    	float getY(){return _r*sin(_teta)*cos(_phi) ;};
    	float getZ(){return _r*sin(_phi);};
    	float getR(){return _r;};
    	float getT(){return _teta;};
    	float getP(){return _phi;};
};
#endif
