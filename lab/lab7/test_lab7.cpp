//
// Лабораторная раббота №7. Массивы, обработка массивов.
// test_lab7.cpp
//
#include <cassert>
#include <iostream>
#include "lab7.h"
#include "test_lab7.h"

using namespace std;

bool test_first_zero(int_array_func f)
{
    cerr << "test find_zero: ";

    if (f == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }

    int a[] = { 1, 0, 7, -1, 2, -3, 5 };
    int n = 7;
    assert(f(a, n) == 1);

    a[1] = 5;
    // нет ноля
    assert(f(a, n) == -1);

    cerr << "OK" << endl;
    return true;
}

bool test_product_positive_after_zero(int_array_func f)
{
    cerr << "test product_positive_after_zero: ";

    if (f == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }

    int a[] = { 1, 0, 7, -1, 2, -3, 5 };
    int n = 7;
    int result = 70;
    assert(f(a, n) == result);

    a[0] = 0; a[1] = 1;
    // { 0, 1, 7, -1, 2, -3, 5}
    // проверка c первым нолем
    assert(f(a, n) == result);

    a[0] = 5;
    a[6] = 0;
    // { 5, 1, 7, -1, 2, -3, 0}
    // последний ноль    
    assert(f(a, n) == 0);

    a[6] = -1;
    // { 5, 1, 7, -1, 2, -3, -1}
    // нет ноля
    assert(f(a, n) == 0);

    cerr << "OK" << endl;
    return true;
}

bool test_divide_sums_around_min(void *func)
{
    cerr << "test divide_sums_around_min: ";

    if (func == nullptr) 
    {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    double(*divide_sums_around_min)(const double a[], int n) = (double(*)(const double a[], int n)) func;
    
    double a[] = { 0, 0, 7, 1, 2, 3, 5 };
    int n = 7;
    double result = 0;
    assert(abs(divide_sums_around_min(a, n) - result) < precision);

    a[0] = 3;
    // { 3, 0, 7, 1, 2, 3, 5 };
    result = 3.0 / 18.0;
	double tmp = divide_sums_around_min(a, n);
    assert(abs(tmp - result) < precision);

    a[4] = -3;
    // { 3, 0, 7, 1, -3, 3, 5 };
    result = 11.0 / 8.0;
    assert(abs(divide_sums_around_min(a, n) - result) < precision);

    a[6] = -5;
    // { 3, 0, 7, 1, -3, 3, -5 };
	
	tmp = divide_sums_around_min(a, n);
	if (!isnan(tmp)) { cout << "divide_sums_around_min при делении на 0 должна возвращать NaN - смотрите формулировку задания!\n"; }
	assert(isnan(tmp));
    
    cerr << "OK" << endl;
    return true;
}

bool test_remove_duplicates(void *func)
{
    cerr << "test remove_duplicates: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    void(*remove_duplicates)(int [], int &) = (void(*)(int [], int &)) func;

    int a[] = { 1, 1, 0, 0, 7, 7, -1, -1, 2, 2, -3, -3, 5, 5 };
    int n = 14;
    int result[max_N] = { 1, 0, 7, -1, 2, -3, 5 };
    int result_n = 7;
    remove_duplicates(a, n);

    assert(n == result_n);
    for (int i = 0; i < n; ++i) {
        assert(a[i] == result[i]);
    }
    
    remove_duplicates(a, n);
    assert(n == result_n);
    for (int i = 0; i < n; ++i) {
        assert(a[i] == result[i]);
    }
    
    a[7] = a[8] = a[9] = 8;
    n = 10;
    result[7] = 8;
    result_n = 8;

    remove_duplicates(a, n);
    assert(n == result_n);
    for (int i = 0; i < n; ++i) {
        assert(a[i] == result[i]);
    }

    cerr << "OK" << endl;
    return true;
}

bool test_insert_duplicates(void *func)
{
    cerr << "test insert_duplicates: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    void(*insert_duplicates)(int [], int&) = (void(*)(int [], int&)) func;

    int a[max_N] = { 1, 0, 7, -1, 2, -3, 5 };
    int n = 7;
    int result[max_N] = { 1, 1, 0, 0, 7, 7, -1, -1, 2, 2, -3, -3, 5, 5 };
    int result_n = 14;
    insert_duplicates(a, n);

    assert(n == result_n);
    for (int i = 0; i < n; ++i) {
        assert(a[i] == result[i]);
    }

    cerr << "OK" << endl;
    return true;
}


bool test_is_symmetrical(void *func)
{
    cerr << "test is_symmetrical: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    bool(*is_symmetrical)(const int [], int, int) = (bool(*)(const int [], int, int)) func;


    int a[] = { 5, -3, 2, -1, 2, -3, 5 };
    int n = 7;
    assert(is_symmetrical(a, n, 0) == true);

    a[2] = 0;
    // { 5, -3, 0, -1, 2, -3, 5 }
    assert(is_symmetrical(a, n, 0) == false);

    int b[] = { 7, 5, -3, 2, 2, -3, 5, 7 };
    n = 8;
    assert(is_symmetrical(b, n, 0) == true);

    b[3] = 0;
    // { 7, 5, -3, 0, 2, -3, 5, 7 };
    assert(is_symmetrical(b, n, 0) == false);

    cerr << "OK" << endl;
    return true;
}

bool test_full_lab7()
{
    return test_first_zero(first_zero) &&
        test_product_positive_after_zero(product_positive_after_zero) &&
        test_divide_sums_around_min(/* ваша реализация здесь */) &&
        test_remove_duplicates(/* ваша реализация здесь */) &&
        test_insert_duplicates(/* ваша реализация здесь */) && 
        test_is_symmetrical(/* ваша реализация здесь */);
}
