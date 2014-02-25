#include "Global.hpp"
#define PI 3.14159

LibSerial::SerialStream arduino;
Matrix4 matModel, matView, matModelView;
Point pos_cam(20,90,30); 
Point vise(0,0,0); 
Point up(1,0,PI/2);
void *font = GLUT_BITMAP_8_BY_13;
