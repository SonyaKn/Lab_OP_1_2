#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include "Header.h"
using namespace std;
int main()
{
    string nameFile = "myFile.txt";
    vector<string>v_text;
    WriteTo(nameFile);
    cout << endl << "Your text:" << endl<<endl;
    string text= ReadingFrom(nameFile,v_text);
    //Func(text);
    Func2(v_text);
}
