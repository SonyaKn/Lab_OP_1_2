#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Time
{
	int hour;
	int minutes;
	Time();
	void setTime();
	string getTime();
};

struct Timetable
{
	string destination_city;
	Time departure_time;
	Time duration_trip;
	Timetable();
	void setTimetable();
	void outputTimetable();
};

void inputBus(vector<Timetable>& );
void outputBusses(vector<Timetable>& );
void readF(vector<Timetable>&, Timetable&, string );
void writeF(vector<Timetable>&, Timetable&, string );
void updateF(vector<Timetable>&, vector<Timetable>&, string );
void lastDeparture(vector<Timetable>& );