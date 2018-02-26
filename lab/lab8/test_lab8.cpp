//
// Лабораторная работа №8. Массивы и указатели
// test_lab8.cpp
//
#include <iostream>
#include <cmath>
#include <cassert>
#include "test_lab8.h"
#include "lab8.h"

using namespace std;

bool test_swap_ptr(void * func)
{
    cerr << "test swap: ";

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

bool test_min_distance(void * func)
{
    cerr << "test min_distance: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    double(*min_distance)(const simple_func f, const double *x, const uint size, int &min_index1, int &min_index2) = (double(*)(const simple_func f, const double *x, const uint size, int &min_index1, int &min_index2)) func;

    cerr << "OK" << endl;
    return true;
}

bool test_full_func_lab8()
{
    return test_swap_ptr(/*...*/) &&
        test_root(/*...*/) &&
        test_min_distance(/*...*/);
}
