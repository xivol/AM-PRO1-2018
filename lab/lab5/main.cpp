//
// Лабораторная работа №5. Библиотека функций
// main.cpp
//

#include <iostream>
#include "lab5.h"
#include "point.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    double x1, y1, x2, y2;
    cout << "Введите координаты первой точки:" << endl;
    cin >> x1 >> y1;
    cout << "Введите координаты второй точки:" << endl;
    cin >> x2 >> y2;
    cout << "Расстояние между точками:" << endl;
    cout << distance(x1, y1, x2, y2) << endl;

    point p1{ x1, y1 }, p2{ x2, y2 };
    cout << distance(p1, p2) << endl;

    system("pause");
    return 0;
}
