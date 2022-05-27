#include "class.h"
double Point::GetX()
{
	return x;
}
double Point::GetY()
{
	return y;
}
double Point::GetZ()
{
	return z;
}

string Point::GetStart()
{
	return string("(") + to_string(x0) + string(", ") + to_string(y0) + string(", ") + to_string(z0) + string(")");
}
string Point::GetFinal()
{

	return string("(") + to_string(x) + string(", ") + to_string(y) + string(", ") + to_string(z) + string(")");
}

double Point::GetDistance(double x2, double y2, double z2)
{
	return sqrt(pow(x2 - x, 2) + pow(y2 - y, 2) + pow(z2 - z, 2));
}

PointXYZ::PointXYZ()
{
	double min = -100.0;
	double max = 100.0;
	x0 = (double)(rand()) / RAND_MAX * (max - min) + min;
	y0 = (double)(rand()) / RAND_MAX * (max - min) + min;
	z0 = (double)(rand()) / RAND_MAX * (max - min) + min;
	x = y = z = 0;
}
void PointXYZ::coordinates(int time)
{
	double min = -5.0;
	double max = 5.0;
	double a1 = (double)(rand()) / RAND_MAX * (max - min) + min;
	double a2 = (double)(rand()) / RAND_MAX * (max - min) + min;
	double a3 = (double)(rand()) / RAND_MAX * (max - min) + min;
	x = x0 + a1 * sin(time);
	y = y0 + a2 * cos(time);
	z = z0 + a3 * pow(time, 2);

}
PointXY::PointXY()
{
	double min = -100.0;
	double max = 100.0;
	x0 = (double)(rand()) / RAND_MAX * (max - min) + min;
	y0 = (double)(rand()) / RAND_MAX * (max - min) + min;
	z0 = (double)(rand()) / RAND_MAX * (max - min) + min;

}

void PointXY::coordinates(int time)
{
	double min = -5.0;
	double max = 5.0;
	double a1 = (double)(rand()) / RAND_MAX * (max - min) + min;
	double a2 = (double)(rand()) / RAND_MAX * (max - min) + min;
	double a3 = (double)(rand()) / RAND_MAX * (max - min) + min;
	x = x0 + a1 * sin(time);
	y = y0 + a2 * cos(time);
	z = 0;
}

