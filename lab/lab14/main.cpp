//
// Лабораторная работа №14. Текстовые файлы. Обработка чисел
// main.cpp
//
#include <fstream>
#include <iostream>
#include "crtdynmem.h"
#include "lab14.h"
#include "test_lab14.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    test_full_lab14();
    
    cout << "Введите имя файла: ";
    char fname[20];
    cin.getline(fname, 20);
    
    int *a = nullptr;
    uint n = 0;

    _CrtMemState _ms;
    _CrtMemCheckpoint(&_ms);

    try {
        read_from_text(fname, a, n);

        ofstream fout("output.txt");
        if (!fout.is_open())
            throw "Не найден указанный файл";
        print_to_stream(fout, a, n);

        print_to_stream(cout, a, n);
    }
    catch (char *error) {
        cout << error << endl;
    }

    delete[] a;
    _CrtMemDumpAllObjectsSince(&_ms);

    system("pause");
    return 0;
}