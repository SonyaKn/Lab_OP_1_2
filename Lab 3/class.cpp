#include "class.h"
Plural::Plural()
{
	element = 0;
	plural = {};
}
Plural::Plural(int count)
{
	cout << "Enter the number of elements of the set: ";
	cin >> count;
	cout << endl << "Enter " << count << " elements of the set" << endl;
	for (int i = 0; i < count; i++)
	{
		cin >> element;
		if (!find_num(element))
		{
			plural.insert(element);
		}
		else
		{
			cout << "The number is already in the plural. Try again  ";
			cin >> element;
			plural.insert(element);
		}
		
	}
}

set<int> Plural::GetPlural()
{
	return plural;
}

void Plural::outputPlural()
{
	copy(plural.begin(), plural.end(), ostream_iterator<int>(cout, " "));
}

Plural Plural:: operator +(const Plural& other)
{
	Plural C;
	set<int>::iterator it;
	for (it = other.plural.begin(); it != other.plural.end(); it++)
	{

		this->plural.insert(*it);

	}
	set<int>::iterator it1;
	for (it1 = this->plural.begin(); it1 != this->plural.end(); it1++)
	{

		C.plural.insert(*it1);

	}
	cout << endl << "Operator + :" << endl;
	C.outputPlural();
	return C;
}
Plural Plural:: operator *(const Plural& other)
{
	Plural C;
	set<int>::iterator it1;
	set<int>::iterator it2;

	for (it1 = other.plural.begin(); it1 != other.plural.end(); it1++)
	{
		for (it2 = this->plural.begin(); it2 != this->plural.end(); it2++)
		{
			if (*it2 == *it1)
			{
				C.plural.insert(*it1);
			}
		}
	}
	cout << endl << "Operator * :" << endl;
	C.outputPlural();
	return C;
}
Plural Plural:: operator -(const Plural& other)
{
	Plural C;
	set<int>::iterator it;
	set<int>::iterator it1;
	for (it1 = this->plural.begin(); it1 != this->plural.end(); it1++)
	{

		C.plural.insert(*it1);

	}
	for (it = other.plural.begin(); it != other.plural.end(); it++)
	{
		C.plural.erase(*it);
	}

	cout << endl << "Operator - :" << endl;
	C.outputPlural();
	return C;
}

bool Plural::find_num(int element)
{
	set<int>::iterator it;
	for (it = plural.begin(); it != plural.end(); it++)
	{
		if (*it == element)
		{
			return true;
		}
	}

	return false;
}