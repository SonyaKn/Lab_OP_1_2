#include "lib.h"
using namespace std;
int main()
{
    cout << "Enter the number of geometric progressions: " << endl;
    int count;
    cin >> count;
    GeomProg *elements=new GeomProg[count];

    inputProgressions(elements,count);
    AllLastEl(elements, count);
    int index = MaxLastEl(elements, count);
    cout << "The largest last element in the " << index+1 << " geometric progression" << endl;
    delete[] elements;
}
