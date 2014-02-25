
#include "Environnement.hpp"

void Environnement::initEnv(){
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //Double Buffer et Couleur et buffer de profondeur
	glutInitWindowPosition(50,50);
	glutInitWindowSize(600,600);
	glutCreateWindow("KII : Koelis Interface for IMU"); //Nom de la fenêtre
	//Activation de la profondeur.
	glMatrixMode(GL_PROJECTION); //Définit le type de la pile de matrice
	glLoadIdentity(); //Fixe la matrice dans la pile de matrice
	gluPerspective(45,1,0.5,1000);//Angle de vue en y, ratio longueur largeur en x, jusqu'ou un objet proche est visible, idem loin
	glEnable(GL_DEPTH_TEST); //Activation de la profondeur
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//Init des tampons d'affichage et de profondeur
}	
	
	

	
void Environnement::paint(){
	//printf("Fonction de dessin avec %f\n", pos_cam.getX());
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);//Init des tampons d'affichage et de profondeur
	glMatrixMode(GL_MODELVIEW); //
	glPushMatrix();
	//glLoadIdentity(); //Nouvelle matrice sur la pile.
	matView.identity();
	matModel.identity();

	matView.rotate(-pos_cam.getT(), 0,0,1);  // 1: rotate on z-axis
	matView.rotate(-pos_cam.getP(), 1,0,0);  // 2: rotate on x-axis
	
	matView.translate(0, 0, -pos_cam.getR());
	
	glLoadMatrixf(matView.getTranspose());
	g->draw(this);
	g->drawGrid(10.0f, 1.0f);
	cap->paint(g);
	//Fin du dessin
	glPopMatrix();
	glutSwapBuffers();
}

void Environnement::askSensor(){
	cap->readAll();
	enr->record(*cap);
}
	
void Environnement::key(unsigned char key, int x, int y)
{    
	//printf("ASK\n");
	if(key== 'q'){
			arduino.Close();
			exit(0);
	}

	else if(key=='2'){

		pos_cam.setP(pos_cam.getP()-0.1);
		//		printf("touche 2et %f\n",phi);
		glutPostRedisplay();
	}

	else if(key=='8'){
	//		printf("touche 8\n");
		pos_cam.setP(pos_cam.getP()+0.1);
		glutPostRedisplay();
	}

	else if(key=='4'){
	//		printf("touche 4\n");
		pos_cam.setT(pos_cam.getT()-0.1);
		glutPostRedisplay();
	}

	else if(key=='6'){
	//		printf("touche 6\n");
		pos_cam.setT(pos_cam.getT()+0.1);
		glutPostRedisplay();
	}

	else if(key=='+'){
	//		printf("touche +\n");
		pos_cam.setR(pos_cam.getR()-0.1);
		//std::cout << pos_cam.getR() << " R" << std::endl;
		glutPostRedisplay();
	}

	else if(key=='-'){
	//		printf("touche -\n");
		pos_cam.setR(pos_cam.getR()+0.1);
		glutPostRedisplay();
	}

	else if(key=='z'){
		cap->setCalib();
		glutPostRedisplay();
	}
	
	else if(key=='a'){
		cap->setWhich(0);
		glutPostRedisplay();
	}
	
	else if(key=='m'){
		cap->setWhich(4);
		glutPostRedisplay();
	}
	
	else if(key=='g'){
		cap->setWhich(1);
		glutPostRedisplay();
	}
	
	else if(key=='c'){
		cap->setWhich(3);
		glutPostRedisplay();
	}
	
	else if(key=='k'){
		cap->setWhich(2);
		glutPostRedisplay();
	}
	
	else if(key=='n'){
		cap->noCalib();
		glutPostRedisplay();
	}

	else{
	glutPostRedisplay();
	}

}


void Environnement::mouse(int button, int state, int x, int y)
{
    mouseX = x;
    mouseY = y;
	
    if(button == GLUT_LEFT_BUTTON)
    {
        if(state == GLUT_DOWN)
        {
            mouseLeftDown = true;
        }
        else if(state == GLUT_UP)
            mouseLeftDown = false;
    }

    else if(button == GLUT_RIGHT_BUTTON)
    {
        if(state == GLUT_DOWN)
        {
            mouseRightDown = true;
        }
        else if(state == GLUT_UP)
            mouseRightDown = false;
    }
}


void Environnement::mouseMotion(int x, int y)
{
	//std::cout <<"Mouse "<<x << " "<< mouseX << std::endl;
    if(mouseLeftDown)
    {
        pos_cam.setT( pos_cam.getT()-((x - mouseX)));
        pos_cam.setP( pos_cam.getP()-((y - mouseY)));
        mouseX = x;
        mouseY = y;
    }
    if(mouseRightDown)
    {
        pos_cam.setR(pos_cam.getR() + ((y - mouseY) * 0.2f));
        mouseY = y;
    }
}
	
	
	
