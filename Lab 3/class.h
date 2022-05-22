#pragma once
#include <iostream>
#include <set>
#include <iterator>
using namespace std;
class Plural
{
	int element;
	set<int> plural;
	bool find_num(int);

public:
	Plural();
	Plural(int);
	//Plural(const Plural& other);
	set<int> GetPlural();
	//void SetPlural(set<int>);
	void outputPlural();
	Plural operator + (const Plural& other);
	Plural operator * (const Plural& other);
	Plural operator - (const Plural& other);

};
