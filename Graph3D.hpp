#ifndef GRAPH3D_HPP
#define GRAPH3D_HPP


#include "Graph.hpp"
#include "IMU.hpp"
#include "ImgEcho.hpp"


#define PIOVER180 3.14159/180

class Graph3D : public Graph{

	protected : 
	ImgEcho imgecho;
	public : 
	Graph3D(const ImgEcho& img) : Graph(), imgecho(img){};
	virtual void draw(Environnement* env);
	virtual void draw(IMU* cap);	
	void drawInfoImu(IMU* cap);
	void drawString(const char *str, int x, int y, float color[4], void *font);
	void drawRepere();
};

#endif












