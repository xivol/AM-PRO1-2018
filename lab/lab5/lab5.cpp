//
// Лабораторная работа №5. Библиотека функций
// lab5.cpp
//

#include <cmath>
#include "lab5.h"

// double sqr(double x)
// - не видима в main.cpp т.к. не объявлена в lab.h
// Вычисление квадрата числа
inline double sqr(double x)
{
    return x*x;
}

/* Встраиваемые (inline) функции подставляются компилятором,
* но только в рамках одной единицы компиляции,
* и только достаточно простые функции
*/

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(sqr(x2 - x1) + sqr(y2 - y1));  // здесь вместо вызова функции sqr
                                               // компилятор постарается подставить её возвращаемое значение
}