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

bool test_sqr(int number_of_tests)
{
    // std::cerr - стандартный поток вывода для ошибок
    // по умолчанию выводит на консоль    
    cerr << "test sqr: ";

    int n = 0;
    while (n < number_of_tests) {
        double a = rand() * (0.5 - (double)rand() / RAND_MAX);
        double result = a*a;
        
        assert(abs(sqr(a) - result) < precision);
        n += 1;
    }

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
    x2 = 2; y2 = 5;
    result = 0;
    assert ( abs( distance(x1, y1, x2, y2) - result) < precision);
  
    cerr << "OK" << endl;
    return true;
}

bool test_full_func_l2()
{
    // Проверка запуска в режиме отладки (макрос _DEBUG)
#ifdef _DEBUG
    // Этот код будет скомпилирован только в режиме отладки
    int number_of_tests = 100;
    return test_sqr(number_of_tests) && test_distance();

#endif /* _DEBUG */

    return false;
}
