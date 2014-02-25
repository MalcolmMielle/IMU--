#ifndef ENVIR_HPP
#define ENVIR_HPP

#include <math.h>
#include <SerialStream.h>

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iomanip>
#include "Point.hpp"
#include "Capteur.hpp"
#include "Graph.hpp"
#include "Global.hpp"
#include "Enregistreur.hpp"

#define PI 3.14159
void key(unsigned char key, int x, int y);

class Environnement{
	private :
	protected : 
	Capteur* cap;
	Enregistreur* enr;
	Graph* g;
	unsigned char keyp;
	int x;
	int y;
	int button, state;
	bool mouseLeftDown;
	bool mouseRightDown;
	float mouseX, mouseY;
	public :
	Environnement(){};
	Environnement(Graph& g2, Capteur& cap, Enregistreur& enr) : cap(&cap), enr(&enr), g(&g2){};
	void askSensor();
	void initEnv();
	void paint();
	void mainEnv();
	void key(unsigned char key, int x, int y);
	void mouse(int button, int state, int x, int y);
	void mouseMotion(int button, int state);
};

static Environnement* g_CurrentInstance;

extern "C"
inline void drawCallback()
{
	//printf("GOOOOOO\n");
  g_CurrentInstance->paint();
}


extern "C"
inline void keyBack(unsigned char key, int x, int y)
{
	//printf("GOOOOOO key !!! =)\n");
  g_CurrentInstance->key(key, x, y);
}

extern "C"
inline void askingSensor()
{
	//printf("GOOOOOO sensor !!! =)\n");
  g_CurrentInstance->askSensor();
  g_CurrentInstance->paint();
}

extern "C"
inline void askMouse(int button, int state, int x, int y)
{
	//printf("GOOOOOO sensor !!! =)\n");
  g_CurrentInstance->mouse(button, state, x, y);
}

extern "C"
inline void askMouseMotion(int button, int state)
{
	//printf("GOOOOOO sensor !!! =)\n");
  g_CurrentInstance->mouseMotion(button, state);
}


inline void Environnement::mainEnv(){
	::g_CurrentInstance=this;
	::glutIdleFunc(::askingSensor);
	::glutKeyboardFunc(::keyBack);//Fonction principale clavier
	::glutDisplayFunc(::drawCallback); //Fonction principale de dessin
	::glutMouseFunc(::askMouse);
      ::glutMotionFunc(::askMouseMotion);
	
	::glutMainLoop(); //Boucle de traitement	

}

#endif
	
