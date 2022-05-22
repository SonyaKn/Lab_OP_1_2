#include "class.h"
int main()
{
	Plural A(0);
	Plural B(0);
	cout << endl << "Plural A:";
	A.outputPlural();
	cout << endl << "Plural B:";
	B.outputPlural();

	Plural C = (A + B) - (A * B);

	cout << endl << "Plural C = ";
	C.outputPlural();
}
