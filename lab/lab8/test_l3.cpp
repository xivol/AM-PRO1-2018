/* test_l3.cpp
 * Реализация тестов для функций библиотеки func_l3.h
 */

#include <cassert>
#include <cmath>
#include <iostream>

#include "func_l3.h"
#include "test_l3.h"

using namespace std;

// bool test_swap()
// Функциия:
// template <typename T> void swap_point(T *a, T*b)
// Проверка переменных типа int, double, char*.
bool test_swap()
{
    // int
    assert(0);
    // double
    assert(0);
    // char*
    assert(0);

#ifdef _DEBUG    
    cerr << "swap test: OK" << endl;
#endif /* _DEBUG */
    return true;
}

// bool test_exp_of()
// Функциия:
// double exp_of(const double x, const double eps = precision)
// Проверка для элементрарных аргументов (0, 1), 
// проверка параметра точности, сравнение результата с exp(x).
bool test_exp_of()
{
    // exp(0) == 1
    double x = 0, eps = 1;
    double result = 1;
    assert(abs(exp_of(x, eps) - result) < precision);

    // exp(1) == 2,71..
    x = 1;
    result = 2.7182818284590455;
    assert(abs(exp_of(x) - result) < precision);

    // (exp(1) - 2,718)< 1E-3
    x = 1;
    eps = 1E-3;
    result = 2.718;
    assert(abs(exp_of(x, eps) - result) < eps);
    
    // exp(10) == 27,18..
    x = 10;
    eps = 1E-6;
    result = exp(10);
    assert(abs(exp_of(x, eps) - result) < eps);

#ifdef _DEBUG 
    cerr << "exp_of test: OK" << endl;
#endif /* _DEBUG */
    return true;
}

// bool test_sum_prime_factors()
// Функциия:
// uint sum_prime_factors(const uint k)
// Проверка для элементрарных аргументов (0, 1, 2), 
// проверка для простого и составного чисел.
bool test_sum_prime_factors()
{
    // k = 0
    assert(sum_prime_factors(0) == 0);
    // k = 1
    assert(sum_prime_factors(1) == 0);
    // k = 2
    assert(sum_prime_factors(2) == 2);
    // k = 17
    assert(0);
    // k = 121  11 + 11 
    assert(0);

#ifdef _DEBUG 
    cerr << "sum_prime_factors test: OK" << endl;
#endif /* _DEBUG */
    return true;
}

// double test_root_f1(const double x)
// Вспомогательная функция для test_root
inline double test_root_f1(const double x)
{
    return x*x - 1;
}

// bool test_root()
// Функциия:
// double root(double(*const f)(double), const double a, const double b, const double eps)
// Проверить  sin [-1; 1]
//            cos [0; 2]
//            x^2 - 1 [0; 1] [-1;0] [2;0]
bool test_root()
{
    // sin(x) [-1;1]
    double a = -1, b = 1;
    double result = 0;
   // assert(abs(root(sin, a, b) - result) < precision);
    // cos(x) [0;2]
    assert(0);
    // x^2 - 1 [-1; 0]
    assert(0);
    // x^2 - 1 [0; 1]
    assert(0);
    // x^2 - 1 [2; 0]
    // защита от дурака
    assert(0);

#ifdef _DEBUG 
    cerr << "root test: OK" << endl;
#endif /* _DEBUG */
    return true;
}

// bool test_full_func_l3()
// Поочередный запуск всех тестов данной библиотеки
bool test_full_func_l3()
{
    return test_swap() &&
        test_exp_of() &&
        test_sum_prime_factors &&
        test_root();
}