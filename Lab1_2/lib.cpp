#include "lib.h"
Time::Time() 
{
	hour = 0;
	minutes = 0;
}

void Time::setTime() 
{
	cout << "Enter hour: ";
	cin >> hour;
	while (hour < 0 || hour > 23) 
	{
		cout << "Incorrect input. Hour values must be in range 0 TO 23" << endl << "Enter hour: ";
		cin >> hour;
	}

	cout << "Enter minute: ";
	cin >> minutes;
	while (minutes < 0 || minutes > 59) {
		cout << "Incorrect input. Minutes should range from 0 t0 59" << endl<< "Enter minute: ";
		cin >> minutes;
	}
}

string Time::getTime()
{
	return to_string(hour) + ":" + to_string(minutes); //23:15
}

Timetable::Timetable() 
{
	destination_city = "";
}

void Timetable::setTimetable() 
{
	cout << endl << "Enter destination city: ";
	cin >> destination_city;
	while (destination_city.size() < 1)
	{
		cout << "Incorrect input. The number of characters in destination name is at least 2" << endl;
		cin >> destination_city;
	}
	cout << "Set departure time" << endl; 
	departure_time.setTime();
	cout << "Set duration of trip" << endl;
	duration_trip.setTime();
}

void Timetable::outputTimetable()
{
	cout << endl << "City: " + destination_city + "\tDeparture time: " + departure_time.getTime() + "\tDuration of trip: " + duration_trip.getTime();
}

void inputBus(vector<Timetable>& res)
{
	int count;
	cout << endl << "Enter how many buses you want to add: ";
	cin >> count;
	while (count < 1)
	{
		cout << endl << "Incorrect input. Enter how many buses you want to add: ";
		cin >> count;
	}
	for (int i = 0; i < count; i++)
	{
		Timetable t;
		t.setTimetable();
		res.push_back(t);
	}
}

void writeF(vector<Timetable>& busses, Timetable& bus, string fileName)
{
	char flag;
	ofstream outf;
	cout << "Do you want to rewrite the file (y/n)?";
	while (true)
	{
		cin >> flag;
		if (flag == 'y')
		{
			outf.open(fileName, ios::binary);
			break;
		}
		else if (flag == 'n')
		{
			readF(busses, bus, fileName);
			cout << endl << "Old file:" << endl;
			outputBusses(busses);
			cout << endl;
			outf.open(fileName, ios::app || ios::binary);
			break;
		}
		else
		{
			cout << "Incorrect input: Enter y or n" << endl;
		}
	}

	if (!outf.is_open())
	{
		cout << "ERROR: Cannot open file";
		exit(0);
	}
	else
	{
		inputBus(busses);
		for (int i = 0; i < busses.size(); i++)
		{
			outf.write((char*)&busses[i], sizeof(Timetable));
		}

	}
	outf.close();
}

void readF(vector<Timetable>& busses, Timetable& bus, string fileName)
{
	ifstream inf;

	inf.open(fileName, ios::binary);

	if (!inf.is_open())
	{
		cout << "ERROR: Cannot read file" << endl;
		exit(0);
	}
	else
	{
		while (inf.read((char*)&bus, sizeof(Timetable)))
		{
			busses.push_back(bus);
		}
	}

	inf.close();
}

void outputBusses(vector<Timetable>& busses)
{
	for (int i = 0; i < busses.size(); i++)
	{
		busses[i].outputTimetable();
	}
}
void updateF(vector<Timetable>& busses, vector<Timetable>& newbusses, string fileName)
{
	int h, m;
	for (int i = 0; i < busses.size(); i++)
	{
		busses[i].outputTimetable();
		newbusses.push_back(busses[i]);
		h = busses[i].departure_time.hour + busses[i].duration_trip.hour;
		m = busses[i].departure_time.minutes + busses[i].duration_trip.minutes;
		if (m >= 60)
		{
			m = m - 60;
			h++;
		}
		if (h >= 23 || h < 6 || (h == 6 && m == 0)|| busses[i].departure_time.hour<6|| (busses[i].departure_time.hour==6&& busses[i].departure_time.minutes==0))
		{
			if (busses[i].duration_trip.hour >= 17)
			{
				cout << " - night time, but more than 17 hours";
			}
			else
			{
				cout << " - night time, less than 17 hours";
				newbusses.pop_back();
			}
		}
	}

	ofstream outf;
	outf.open(fileName, ios::binary);

	for (int i = 0; i < newbusses.size(); i++)
	{
		outf.write((char*)&newbusses[i], sizeof(Timetable));
	}

	outf.close();
	cout << endl <<endl<< "File after deletion:";

	for (int i = 0; i < newbusses.size(); i++)
	{
		newbusses[i].outputTimetable();
	}
}
void lastDeparture(vector<Timetable>& newbusses)
{
	string needCity;
	cout <<endl<< "Enter the city of the last bus you`re looking for:";
	cin >> needCity;
	cout << endl;
	while (needCity.size() < 1)
	{
		cout << "Incorrect input. The number of characters in destination name is at least 2" << endl;
		cin >> needCity;
	}
	int needH = 0, needM = 0, id = 0;
	for (int i = 0; i < newbusses.size(); i++)
	{
		if (needCity == newbusses[i].destination_city)
		{
			if (needH < newbusses[i].departure_time.hour) needH = newbusses[i].departure_time.hour;
			if (needM < newbusses[i].departure_time.minutes) needM = newbusses[i].departure_time.minutes;
			id = i;
		}
	}
	cout << "Last bus to " << needCity << endl;
	newbusses[id].outputTimetable();
}