//
// Лабораторная работа №8. Массивы и указатели
// main.cpp
//

#include <iomanip>
#include <iostream>
#include "test_lab8.h"
#include "lab8.h"

using namespace std;

// Котангенс ctg(x)
double cotan(double x)
{
    return 1 / tan(x);
}

int main() 
{
    test_full_func_lab8();
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    
    float a;
    int k;
    cout << "Введите вещественное число:" << endl;
    cin >> a;
    k = a;

    // setw устанавливает ширину поля вывода 
    // для последующего значения
    cout << setw(10) << "address" << " | ";
    cout << setw(10) << "type" << " | ";
    cout << setw(10) << "dec" << " | ";
    cout << setw(10) << "hex" << endl;

    print_float(&a);
    print_int(&k);

    // Типизированные указатели нельзя преобразовывать неявно
    // print_float(&k); 
    // print_int(&a);
    
    cout << setw(10) << "type cast:" << endl;
    // Явное преобразование допустимо
    print_float((float*)&k);
    print_int((int*)&a);

    void *p = nullptr;
    // Неявно можно преобразовывать к нетипизированному указателю
    p = &k;
    // Но к конкретному типу придется приводить явно
    print_float((float*)p);
    print_int((int*)p);

    // Нетипизированный указатель позволяет 
    // писать обощенные функции работы с памятью
    
    // Реализуйте swap!
    //swap(&a, &k, sizeof(int));
    
    //cout << setw(10) << "swapped:" << endl;
    //print_float(&a);
    //print_int(&k);

    cout << endl;

    // setfill - устанавливает символ 
    // для заполнения пустого места в поле вывода,
    // работает для всего потока!
    cout << setfill('>');
    cout << setw(46) << ">" << endl;
    cout << setfill(' ');

    // Выведем таблицу значений функций в точке
    const simple_func f[] = { sin, cos, tan, cotan };

    // Размер статического массива можно узнать 
    // по длине выделенной памяти
    int len = sizeof(f) / sizeof(*f);
    
    double x = 1.68;
    int precision = 4;

    for (int i = 0; i < len; ++i)
        print_func(f[i], x, precision);

    cout << setfill('>');
    cout << setw(46) << ">" << endl;
    cout << setfill(' ');

    system("pause");
    return 0;
}
