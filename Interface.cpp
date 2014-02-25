#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Environnement.hpp"
#include "Graph3D.hpp"
#include "Global.hpp"
#include "EnregIMU.hpp"
#include "IMU.hpp"

/****************************PROGRAMME******************************************/

int main(int argc, char *argv[])
{
	ImgEcho imgecho(0, 0, 2, 0, 0,45 );
	Graph3D g(imgecho);
    	IMU cap;
    	EnregIMU enr;
	Environnement env(g, cap, enr);
	FILE* f;
	f=fopen("Carte.txt","w");
	fclose(f);	
	glutInit(&argc, argv); //Init de la fenêtre
	//printf("GO\n");
	env.initEnv();
	//printf("Fin\n");
	env.mainEnv();

}
	
