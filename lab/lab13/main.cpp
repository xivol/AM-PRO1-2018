//
// Лабораторная работа №13. Динамические строки
// main.cpp
//
#include <iostream>
#include <crtdbg.h>
#include "crtdynmem.h"
#include "lab13.h"
#include "test_lab13.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    test_full_lab13();

    const int MaxChars = 100;
    char str[MaxChars];
    char sub[MaxChars];
    char rep[MaxChars];

    cout << "Введите исходную строку:" << endl;
    cin.getline(str, MaxChars);
    cout << "Введите строку для замены:" << endl;
    cin.getline(sub, MaxChars);
    cout << "Введите новую строку:" << endl;
    cin.getline(rep, MaxChars);

    _CrtMemState _ms; 
    _CrtMemCheckpoint(&_ms);

    char *res = nullptr;
    try {
        res = replace(str, sub, rep);

        cout << "Замена: " << sub << " <= " << rep << endl;
        if (res)
            cout << res << endl;
        else
            cout << "Исходная строка не найдена!" << endl;

    }
    catch (char *error) {
        cout << error << endl;
    }
    delete[] res;

    _CrtMemDumpAllObjectsSince(&_ms);
    _CrtMemCheckpoint(&_ms);

    string sstr = str;
    string ssub = sub;
    string srep = rep;

    try {
        cout <<  replace(sstr, ssub, srep) << endl;
    }
    catch (char *error) {
        cout << error << endl;
    }

    _CrtMemDumpAllObjectsSince(&_ms);
    system("pause");
    return 0;
}
