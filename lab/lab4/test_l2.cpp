/* test_l4.cpp
 * Реализация тестов для функций библиотеки func_l3.h
 */

#include <iostream>
#include <cmath>
#include <cassert>

#include "func_l3.h"
#include "test_l2.h"


using namespace std;

// Точность сравнения вещественных чисел
const double precision = 1E-16;

bool test_distance()
{  

    double x1 = 0, y1 = 0;
    double x2 = 1, y2 = 0;
    double result = 1;

    // Тест 1 - единичный отрезок
    assert ( abs ( distance (x1,y1,x2,y2) - result) < precision);
    
    x1 = 2; y1 = 5;
    x2 = 3; y2 = 4;
    result = sqrt(2);

    // Тест 2 - отрезок иррациональной длины
    assert ( abs ( distance (x1,y1,x2,y2) - result) < precision);
    
    x1 = -2; y1 = -5;
    x2 = -2; y2 = -5;
    result = 0;

     // Тест 3 - отрезок нулевой длины
    assert ( abs ( distance (x1,y1,x2,y2) - result) < precision);

// Проверка запуска в режиме отладки (макрос _DEBUG)
#ifndef NDEBUG

    // Этот код будет скомпилирован только в режиме отладки
    // std::cerr - стандартный поток вывода для ошибок
    // по умолчанию выводит на консоль    
    cerr<<"distance test: OK"<<endl;      
#endif /* NDEBUG */

    return true;
}
