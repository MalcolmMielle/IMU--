#include <iostream>
#define BOOST_TEST_DYN_LINK
#include "Quaternion.hpp"
#include <iostream>
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/


BOOST_AUTO_TEST_CASE(trying)
{
	float yaw, pitch, roll;
	yaw=0;
	pitch=0;
	roll=0;
	
	Quaternion q(pitch, yaw, roll);
	Matrix4 pop = q.getMatrix();
	BOOST_CHECK_EQUAL(pop[0],1);
	BOOST_CHECK_EQUAL(pop[1],0);
	BOOST_CHECK_EQUAL(pop[2],0);
	BOOST_CHECK_EQUAL(pop[3],0);
	BOOST_CHECK_EQUAL(pop[4],0);
	BOOST_CHECK_EQUAL(pop[5],1);
	BOOST_CHECK_EQUAL(pop[6],0);
	BOOST_CHECK_EQUAL(pop[7],0);
	BOOST_CHECK_EQUAL(pop[8],0);
	BOOST_CHECK_EQUAL(pop[9],0);
	BOOST_CHECK_EQUAL(pop[10],1);
	std::cout << "OUT"<<std::endl;

	yaw=90;
	pitch=0;
	roll=0;
	
	Quaternion q2(pitch, yaw, roll);
	pop = q2.getMatrix();
	BOOST_CHECK_EQUAL(pop[0],1);
	BOOST_CHECK_EQUAL(pop[1],0);
	BOOST_CHECK_EQUAL(pop[2],0);
	BOOST_CHECK_EQUAL(pop[3],0);
	BOOST_CHECK_EQUAL(pop[4],0);
	BOOST_CHECK_EQUAL(pop[5],1);
	BOOST_CHECK_EQUAL(pop[6],0);
	BOOST_CHECK_EQUAL(pop[7],0);
	BOOST_CHECK_EQUAL(pop[8],0);
	BOOST_CHECK_EQUAL(pop[9],0);
	BOOST_CHECK_EQUAL(pop[10],1);
	std::cout << "OUT"<<std::endl;

}
