#include "func.h"

int main()
{
	srand(time(NULL));

	double t=inputT();
	

	int m = input();
	PointXYZ* arrXYZ = XYZ_Array(m, t);
	cout << "--Array of PointXYZ--" << endl;
	outputPoint(arrXYZ, m, t);

	int n = input();
	PointXY* arrXY = XY_Array(n, t);
	cout << "--Array of PointXY--" << endl;
	outputPoint(arrXY, n, t);

	double min1 = MinDistance(arrXYZ, m);
	cout << "Min distance in array_xyz is " << min1 << endl;
	double min2 = MinDistance(arrXY, n);
	cout << "Min distance in array_xy is " << min2<<endl;
	delete[]arrXYZ;
	delete[]arrXY;

}

