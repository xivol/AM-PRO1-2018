//
// Лабораторная работа №5. Библиотека функций
// lab5.cpp
//

#include <cmath>
#include "lab5.h"

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(sqr(x2 - x1) + sqr(y2 - y1));  // вместо вызова функции sqr
                                               // компилятор постарается подставить её возвращаемое значение
}