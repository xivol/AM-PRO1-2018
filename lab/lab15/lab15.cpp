//
// Лабораторная работа №15. Текстовые файлы. Обработка строк
// lab15.cpp
//
#include <cassert>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>

#include "lab15.h"

using namespace std;

//
void print_len(const char *filename)
{
    assert(filename);

    // создаём файловый поток
    ifstream fin(filename);
    // проверяем, что учпешно связали поток с файлом
    if(!fin.is_open())
        throw "Couldn't open file!";

    string line;
    // пока не конец файла
    while(!fin.eof())
    {
        // читаем одну строку в память
        getline(fin, line);
        cout << line << " : " << line.length() << endl;
    }
    // завершаем работу с файлом
    fin.close();
}