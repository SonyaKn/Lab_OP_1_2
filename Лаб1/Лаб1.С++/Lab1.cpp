#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include "Header.h"
using namespace std;
int main()
{
    string nameFile = "myFile.txt";
    WriteTo(nameFile);
    cout << endl << "Your text:" << endl<<endl;
    string text= ReadingFrom(nameFile);
    Func(text);
}
