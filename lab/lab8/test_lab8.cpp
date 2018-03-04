//
// Лабораторная работа №8. Работа с указателями
// test_lab8.h
//
#include <iostream>
#include <cmath>
#include <cassert>
#include "test_lab8.h"
#include "lab8.h"

using namespace std;

bool test_swap_ptr(void * func)
{
    cerr << "test swap_ptr: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    void(*swap_ptr)(void *a, void *b, uint size) = (void(*)(void *a, void *b, uint size)) func;

    int a = 255, b = -255;
    swap_ptr(&a, &b, sizeof(int));
    assert(a == -255 && b == 255);

    double x = 0.95, y = 95;
    swap_ptr(&x, &y, sizeof(double));
    // Результат можно сравнивать на равенство, 
    // т.к. нет операций над значениями x, y
    assert(x == 95 && y == 0.95); 

    char i = 'i', j = 'j';
    swap_ptr(&i, &j, sizeof(char));
    assert(i == 'j' && j == 'i');

    cerr << "OK" << endl;
    return true;
}

double test_root_func(double x)
{
    return x*x - 1;
}

bool test_root(void * func)
{
    cerr << "test root: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    double(*root)(const simple_func f, const double a, const double b, const double eps) = (double(*)(const simple_func f, const double a, const double b, const double eps)) func;
    
    // sin [-1; 1]
    double a = -1, b = 1, eps = precision;
    double result = 0;
    assert(abs(root(sin, a, b, eps) - result) < eps);

    // cos [0; 2]
    a = 0, b = 2, eps = 0.001;
    result = 3.1415 / 2;
    assert(abs(root(cos, a, b, eps) - result) < eps);

    // x^2 - 1 [0; 1]
    a = 0, b = 1, eps = precision;    
    result = 1;
    assert(abs(root(test_root_func, a, b, eps) - result) < eps);

    // x ^ 2 - 1 [-1; 0]
    a = -1, b=0;
    assert(abs(root(test_root_func, a, b, eps) - result) < eps);

    // x^2 - 1 [2;0]
    a = 2;
    assert(abs(root(test_root_func, a, b, eps) - result) < eps);

    cerr << "OK" << endl;
    return true;
}

bool is_even(int x)
{
    return x % 2 == 0;
}

bool is_odd(int x)
{
    return !is_even(x);
}

bool less_5(int x)
{
    return x < 5;
}

bool test_all(void * func)
{
    cerr << "test all: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    bool(*all)(condition f, const int *x, const uint size) = (bool (*)(condition f, const int *x, const uint size)) func;

    int x[] = { 0, 1, 0 ,2, 0, 3 };
    uint sz = 6;
    assert(!all(is_odd, x, sz));

    assert(!all(is_even, x, sz));

    assert(all(less_5, x, sz));

    cerr << "OK" << endl;
    return true;
}

bool test_full_lab8()
{
#ifdef _DEBUG
    return test_swap_ptr( /* ваша реализация здесь */ ) &&
        test_root( /* ваша реализация здесь */ ) &&
        test_all(/* ваша реализация здесь */);
#endif
}
