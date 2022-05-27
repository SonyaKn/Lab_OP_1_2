#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Point
{
protected:
	double x0;
	double x;
	double y0;
	double y;
	double z0;
	double z;
public:
	
	virtual string GetStart();
	virtual string GetFinal();

	virtual double GetDistance(double, double, double);
	virtual void coordinates(int)=0;
	virtual double GetX();
	virtual double GetY();
	virtual double GetZ();
};
class PointXYZ : public Point
{
public:
	PointXYZ();
	void coordinates(int);
};
class PointXY : public Point
{
public:
	PointXY();
	void coordinates(int);
};


