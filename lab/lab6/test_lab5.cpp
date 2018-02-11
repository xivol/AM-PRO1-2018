//
// Лабораторная работа №6. Тестирование
// test_lab5.cpp
//

#include <iostream>
#include <cmath>
#include <cassert>

#include "lab5.h"
#include "test_lab5.h"

using namespace std;

bool test_sqr()
{
    // std::cerr - стандартный поток вывода для ошибок
    // по умолчанию выводит на консоль    
    cerr << "test sqr: ";

    // Тест 1 - нулевое значение
    double a = 0;
    double result = 0;
    assert(abs(sqr(a) - result) < precision);

    // Тест 2 - положительное значение
    a = 0.5;
    result = 0.25;
    assert(abs(sqr(a) - result) < precision);

    // Тест 3 - отрицательное значение
    a = -0.5;
    assert(abs(sqr(a) - result) < precision);

    // Все тесты пройдены успешно
    cerr << "OK" << endl;
    return true;
}


bool test_distance()
{  
    cerr << "test distance: ";

    // Тест 1 - единичный отрезок
    double x1 = 0, y1 = 0;
    double x2 = 1, y2 = 0;
    double result = 1;
    
    assert( abs( distance(x1, y1, x2, y2) - result) < precision);
    
    // Тест 2 - отрезок иррациональной длины
    x1 = 2; y1 = 5;
    x2 = 3; y2 = 4;
    result = sqrt(2);

    assert ( abs( distance (x1,y1,x2,y2) - result) < precision);

    // Тест 3 - отрезок нулевой длины
    // Опишите тест для отрезка нулевой длины
    assert ( false );
  
    cerr << "OK" << endl;
    return true;
}

bool test_full_lab5()
{
    // Проверка запуска в режиме отладки (макрос _DEBUG)
#ifdef _DEBUG
    // Этот код будет скомпилирован только в режиме отладки
    return test_sqr() && test_distance();

#endif /* _DEBUG */

    return false;
}
