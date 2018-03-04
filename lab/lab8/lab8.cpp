//
// Лабораторная работа №8. Работа с указателями
// lab8.cpp
//
#include <cassert>
#include <iomanip>
#include <iostream>
#include "lab8.h"

using namespace std;

void print_float(float * t)
{
    assert(t != nullptr); // не пустой указатель
    
    // fixed - устанавливает формат вывода 
    // с фиксированной точкой для всего потока
    cout << fixed;
    // setprecision - устанавливает количество знаков 
    // после запятой для всего потока
    //
    cout << setprecision(4);
    cout << "0x" << t << " | ";
    cout << setw(10) << "float" << " | ";
    cout << setw(10) << *t << " | ";
    
    // hex - устанавливает формат вывода 
    // целых чисел в шестнадцатеричной форме
    cout << setw(10) << hex << *(int*)t << endl;
}

void print_int(int * t)
{
    assert(t != nullptr); // не пустой указатель

    cout << "0x" << t << " | ";
    cout << setw(10) << "int" << " | "; 

    // dec - устанавливает формат вывода 
    // целых чисел в десятицной форме
    cout << setw(10) << dec << *t << " | ";
    
    // hex - устанавливает формат вывода 
    // целых чисел в шестнадцатеричной форме
    cout << setw(10) << hex << *t << endl;
}

void print_func(simple_func f, double x, uint precision)
{
    assert(f != nullptr);
    cout << fixed << setprecision(precision) << defaultfloat;
    cout << "f: 0x" << f << " | ";
    cout << "x: " << setw(2 * precision + 1) << x << " | ";
    cout << "f(x): " << setw(2 * precision + 1) << f(x) << endl;
}

void read(int *a, int &n)
{
    assert(a != nullptr);
    cout << "Введите N<" << max_N << endl;
    do {
        cin >> n;
    } while (n < 1 || n >= max_N);

    cout << "Введите " << n << " элемнтов" << endl;
    
    int *p = a;
    while ((p - a) < n) {
        cin >> *p++;
    }
}

void print(const int *a, int n)
{
    assert(a != nullptr);
    assert(n>0 && n<max_N);

    const int *p = a;    
    while ((p - a) < n) {
        cout << *p++ << " ";
    }

    cout << endl;
}
