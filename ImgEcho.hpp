#ifndef IMGECHO_HPP
#define IMGECHO_HPP

#include <GL/glut.h>

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>

class ImgEcho{
	protected :
	Vector3 vec;
	Quaternion qua;
	public : 
	ImgEcho(float x, float y, float z, float roll, float pitch, float yaw) : vec(Vector3(x, y, z)), qua(Quaternion(roll, pitch, yaw)){};
	const Vector3& getVec(){return vec;};
	float getX(){return vec.x;};
	float getY(){return vec.y;};
	float getZ(){return vec.z;};
	Quaternion& getQua(){return qua;};
	
};
	
#endif
