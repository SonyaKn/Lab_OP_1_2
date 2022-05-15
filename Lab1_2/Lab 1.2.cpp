/*14. Створити файл з розкладом руху міжміських автобусів: 
пункт призначення, час відправлення та тривалість поїздки 
(у годинах та хвилинах). Видалитиз файлу інформацію про рейси, 
в яких хоча б частина шляху потрапляе на нічний час 
(з 23:00 до 6:00). Виняток становлять маршрути з тривалістю шляху 
понад 17 годин. Визначити час відправлення останнього автобуса 
в заданий пункт призначення.*/

#include "lib.h"

int main() 
{
	string nameF = "myfile.bin";
	vector<Timetable> busses;
	vector<Timetable>  newbusses;
	Timetable bus;
	
	writeF(busses, bus, nameF);
	busses.clear();
	cout << endl;

	cout << "File content: " << endl;
	readF(busses, bus, nameF);
	updateF(busses, newbusses, nameF);
	lastDeparture(newbusses);
}
