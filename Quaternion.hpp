#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include "Matrices.h"
#define TOLERANCE 0.00001f
#define PIOVER180 3.14159/180
// Convert from Euler Angles
class Quaternion
{
	protected : 
	float x;
	float y;
	float z;
	float w;
	public : 
	Quaternion(float roll, float pitch, float yaw){
		// Basically we create 3 Quaternions, one for pitch, one for yaw, one for roll
		// and multiply those together.
		// the calculation below does the same, just shorter
		float p = pitch * PIOVER180 / 2.0;
		float y = yaw * PIOVER180 / 2.0;
		float r = roll * PIOVER180 / 2.0;
	 
		float sinp = sin(p);
		float siny = sin(y);
		float sinr = sin(r);
		float cosp = cos(p);
		float cosy = cos(y);
		float cosr = cos(r);
		this->x = sinr * cosp * cosy - cosr * sinp * siny;
		this->y = cosr * sinp * cosy + sinr * cosp * siny;
		this->z = cosr * cosp * siny - sinr * sinp * cosy;
		this->w = cosr * cosp * cosy + sinr * sinp * siny;
		normalise();
	}
	
	Quaternion(float x, float y, float z, float w){
		x=x;
		y=y;
		z=z;
		w=w;
	}
	
	float getX(){return x;}
	float getY(){return y;}
	float getZ(){return z;}
	float getW(){return w;}
	
	
	// normalising a quaternion works similar to a vector. This method will not do anything
	// if the quaternion is close enough to being unit-length. define TOLERANCE as something
	// small like 0.00001f to get accurate results
	void normalise()
	{
		// Don't normalize if we don't have to
		float mag2 = w * w + x * x + y * y + z * z;
		if (fabs(mag2) > TOLERANCE && fabs(mag2 - 1.0f) > TOLERANCE) {
			float mag = sqrt(mag2);
			w /= mag;
			x /= mag;
			y /= mag;
			z /= mag;
		}
	}
	
	// Convert to Matrix
	Matrix4 getMatrix() const
	{
		float x2 = x * x;
		float y2 = y * y;
		float z2 = z * z;
		float xy = x * y;
		float xz = x * z;
		float yz = y * z;
		float wx = w * x;
		float wy = w * y;
		float wz = w * z;
	 
		// This calculation would be a lot more complicated for non-unit length quaternions
		// Note: The constructor of Matrix4 expects the Matrix in column-major format like expected by
		//   OpenGL
		//std::cout << 1.0f - 2.0f * (y2 + z2) <<" Quat "<<std::endl;
		return Matrix4( 1.0f - 2.0f * (y2 + z2), 2.0f * (xy - wz), 2.0f * (xz + wy), 0.0f,
				2.0f * (xy + wz), 1.0f - 2.0f * (x2 + z2), 2.0f * (yz - wx), 0.0f,
				2.0f * (xz - wy), 2.0f * (yz + wx), 1.0f - 2.0f * (x2 + y2), 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
	}
	
	Quaternion getConjugate()
	{
		return Quaternion(-x, -y, -z, w);
	}
	
	void getAxisAngle(Vector3& axis, float* angle)
	{
		float scale = sqrt(x * x + y * y + z * z);
		axis.x = x / scale;
		axis.y = y / scale;
		axis.z = z / scale;
		*angle = acos(w) * 2.0f;
	}

	
};

#endif
