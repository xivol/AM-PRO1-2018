//
// Лабораторная работа №4. Динамические массивы.
// dynarrdbg.cpp
//
// Дан массив целых чисел. Продублировать в массиве все элементы, находящиеся 
// между первым и последним нулевыми элементами. Если вставка невозможна, выдать 
// соответствующее сообщение.

#include "crtdynmem.h"
#include "dynarr.h"
#include <iostream>


using namespace std;


int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введите имя файла: ";
    char fname[20];
    cin >> fname;

   
    int *a = nullptr;  // иницилизация указателей при объявлении – залог успешной отладки 
    size_t n = 0;

    // Cоздаём точку отсчёта 
    // для учёта динамически выделяемой памяти
    _CrtMemState _ms;
    _CrtMemCheckpoint(&_ms);

    try {
        readFromText(fname, a, n);
        duplicateBetweenZeros(a, n);
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << endl;
    }
    catch (char* c) {
        cout << c << endl;
    }

    //delete [] a;   

    // ошибка – не освобождена динамическая память!     
     
     // выведем все утечки памяти на текущий момент
     // _CrtDumpMemoryLeaks();

     // выведем все утечки памяти с начала отсчёта
     _CrtMemDumpAllObjectsSince(&_ms);

    system("pause");
    return 0;
}