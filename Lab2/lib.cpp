#include "lib.h"
GeomProg::GeomProg()
{
	n = 1;
	a = 1;
	q = 1;
}
int GeomProg::GetN()
{
	return n;
}
double GeomProg::GetA()
{
	return a;
}
double GeomProg::GetQ()
{
	return q;
}
void GeomProg::SetN(int n)
{
	this->n = n;
}
void GeomProg::SetA(double a)
{
	this->a = a;
}
void GeomProg::SetQ(double q)
{
	this->q = q;
}
double GeomProg::lastEl()
{
	return a * pow(q, n - 1);
}
void inputProgressions(GeomProg *element,int count)
{
	for (int i = 0; i < count; i++)
	{
		int n;
		double a, q;
		cout << endl << "Enter the number of progression items: ";
		cin >> n;
		element[i].SetN(n);
		cout << "Enter the first element of progression: ";
		cin >> a;
		element[i].SetA(a);
		cout <<"Enter the denominator of the progression: ";
		cin >> q;
		element[i].SetQ(q);
	}
}
void AllLastEl(GeomProg* element, int count)
{
	cout << "Last elements of progressions:" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << element[i].lastEl() << " ";
	}
	cout << endl;
}
int MaxLastEl(GeomProg *element,int count)
{
	double maxEl=element[0].lastEl();
	int id=0;
	for (int i = 0; i < count; i++)
	{
		if (maxEl < element[i].lastEl())
		{
			maxEl = element[i].lastEl();
			id = i;
		}
	}
	return id;
}
