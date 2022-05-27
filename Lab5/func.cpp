#include "func.h"
PointXYZ* XYZ_Array(int size, int time)
{
	PointXYZ* Array = new PointXYZ[size];
	for (int i = 0; i < size; i++)
	{
		PointXYZ point;
		point.coordinates(time);
		Array[i] = point;
	}
	return Array;
}
PointXY* XY_Array(int size, int time)
{
	PointXY* Array = new PointXY[size];
	for (int i = 0; i < size; i++)
	{
		PointXY point;
		point.coordinates(time);
		Array[i] = point;
	}
	return Array;
}
int input()
{
	int num = 0;
	do
	{
		cout << "Enter the number of points: "; cin >> num;
	} while (num <= 0);
	return num;
}
int inputT()
{
	cout << "Enter t in seconds: ";
	int time;
	cin >> time;
	while (true)
	{
		if (time > 0)return time;
		else cin >> time;
	}
}
void outputPoint(Point* Array, int size, int time)
{
	for (int i = 0; i < size; i++)
	{
		cout << "M" << i + 1 << ":" << endl;
		cout << "Initial coordinates ofthe point: " << Array[i].GetStart() << endl;
		cout << "Coordinates of the point in " << time << " seconds: " << Array[i].GetFinal() << endl;
		cout << endl;
	}
}
double MinDistance(Point* Array, int size)
{
	double minD = Array[0].GetDistance(Array[1].GetX(), Array[1].GetY(), Array[1].GetZ());
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			double temp = Array[i].GetDistance(Array[j].GetX(), Array[j].GetY(), Array[j].GetZ());
			if (temp < minD)minD = temp;
		}
	}
	return minD;
}
