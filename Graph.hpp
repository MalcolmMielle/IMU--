#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <GL/glut.h>

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <string>
#include "Matrices.h"
#include "Global.hpp"

class Environnement;
class IMU;


class Graph{
	public:
	virtual void draw(Environnement* env)=0;
	virtual void draw(IMU* cap)=0;
	virtual void drawGrid(float size, float step);
};
#endif
