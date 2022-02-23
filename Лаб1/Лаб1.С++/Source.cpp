/*Створити текстовий файл, що містить програму на мові С++.
Перевірити текст на рівну кількість закритих та відкритих дужок,вважаючи, 
що кожен оператор в програмі займає не більше одного рядка вихідного файлу.
Вивести вміст файлу і результат аналізу*/

#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
using namespace std;
void WriteTo(string name)
{
    int num;
    cout << "Type 1 if you want to write a new file." << endl<<"Type 2 if you want to expand the file." << endl;
    cin >>num;
    ofstream inFile;      //запись в файл myfile
    if (num == 1)
        inFile.open(name);
    else if (num == 2)
        inFile.open(name, ios::app);
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
string ReadingFrom(string name,vector<string>&v_text) 
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
            v_text.push_back(line);
        }
        outFile.close();
    }
    else
    {
        cout << "Can`t open the file!" << endl;
    }
    return text;
}
/*void Func(string text)
{
     int cl = 0, op = 0, cl1 = 0, op1 = 0 , cl2 = 0, op2 = 0;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == '(')op++;
        else if (text[i] == ')')cl++;
        if (text[i] == '{')op1++;
        else if (text[i] == '}')cl1++;
    }
    if (cl == op) cout << endl << "The number of '(' is equal to the number of ')'" << endl;
    else cout << endl << "The number of '(' isn`t equal to the number of ')'" << endl;
    if (cl1 == op1) cout << endl << "The number of '{' is equal to the number of '}'" << endl;
    else cout << endl << "The number of '{' isn`t equal to the number of '}'" << endl;
    if (cl2 == op2) cout << endl << "The number of '[' is equal to the number of ']'" << endl;
    else cout << endl << "The number of '[' isn`t equal to the number of ']'" << endl;
}*/
void Func2(vector<string>& v_text)
{
    int counter=0;
    for (int i = 0; i < v_text.size(); i++)
    {
        string line = v_text[i];
        int cl = 0, op = 0;
        for (int j = 0; j < line.size(); j++)
        {
            if (line[j] == '(')op++;
            else if (line[j] == ')')cl++;
        }
        if (op != cl)
        {
            cout << endl << "In line [" << i + 1 << "] the number of '('  isn`t equal to the number of ')'" << endl;
            counter++;
        }
    }
    if (counter == 0)
    {
        cout << endl << "The number of '('  is equal to the number of ')'" << endl;
    }
}
