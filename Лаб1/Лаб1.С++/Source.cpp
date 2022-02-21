/*Створити текстовий файл, що містить програму на мові С++.
Перевірити текст на рівну кількість закритих та відкритих дужок.
Вивести вміст файлу і результат аналізу*/

#include <iostream>
#include <fstream>
#include <string> 
using namespace std;
void WriteTo(string name)
{
    ofstream inFile;      //запись в файл myfile
    inFile.open(name/*, ios::app*/);
    if (inFile.is_open())
    {
        string text;
        char key = 24;
        cout << "============================================" << endl;
        cout << "Press ENTER to start a new line. " << endl << "Press CTRL + X to end the file." << endl;
        cout << "============================================" << endl;
        getline(cin, text);
        while (text[0] != key)
        {
            inFile << text << "\n";
            getline(cin, text);
        }
        cout << endl;
        inFile.close();
    }
    else
    {
        cout << "Can`t open the file!" << endl;
    }
}
string ReadingFrom(string name) 
{
    string text, line;
    ifstream outFile(name);
    if (outFile.is_open()) 
    {
        while (!outFile.eof())
        {
            getline(outFile, line);
            cout << line << endl;
            text += line + "\n";
        }
        outFile.close();
    }
    else
    {
        cout << "Can`t open the file!" << endl;
    }
    return text;
}
void Func(string text)
{
    int cl=0, op=0;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == '(' )op++;
        else if (text[i] == ')')cl++;
    }
    if (cl == op) cout << endl << "The number of '(' is equal to the number of ')'" << endl;
    else cout << endl << "The number of '(' isn`t equal to the number of ')'" << endl;
}

