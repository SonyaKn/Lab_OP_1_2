#pragma once
#include "class.h"
#include <iostream>
#include <sstream>
using namespace std;
int input();
int inputT();

PointXYZ* XYZ_Array(int, int);
PointXY* XY_Array(int, int);

void outputPoint(Point*, int, int);

double MinDistance(Point*, int);