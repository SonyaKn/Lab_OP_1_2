#pragma once
#include <iostream>
using namespace std;
class GeomProg
{
	int n;      //count
	double a;      //first el
	double q;   //znamennuk
public:
	GeomProg();
	int GetN();
	double GetA();
	double GetQ();
	void SetN(int);
	void SetA(double);
	void SetQ(double);
	double lastEl();
};
void inputProgressions(GeomProg *,int);
void AllLastEl(GeomProg*, int);
int MaxLastEl(GeomProg *,int);