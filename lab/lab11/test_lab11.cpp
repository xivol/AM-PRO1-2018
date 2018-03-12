//
// Лабораторная работа №11. Динамические массивы.
// test_lab11.cpp
//

#include <cassert>
#include <iostream>
#include "crtdynmem.h"
#include "lab11.h"
#include "test_lab11.h"

using namespace std;

bool test_find_zeros()
{
    cerr << "test find_zeros: ";
    // один ноль
    int a[] = { 1,0,1 };
    uint fresult = 1, lresult = 1;
    uint f, l;
    find_zeros(a, 3, f, l);
    assert(f == fresult && l == lresult);

    // все ноли
    int b[] = { 0,0,0,0,0,0 };
    fresult = 0;
    lresult = 5;
    find_zeros(b, 6, f, l);
    assert(f == fresult && l == lresult);

    // два разных
    int с[] = { 1,0,1,1,0,1 };
    fresult = 1;
    lresult = 4;
    find_zeros(с, 6, f, l);
    assert(f == fresult && l == lresult);

    // нет нолей
    int d[] = { 1,2,3,4,5 };
    try {
        find_zeros(d, 5, f, l);
        assert(0);
    }
    catch (char *c) {
        assert(c);
    }

    cerr << "OK" << endl;
    return true;
}

bool test_duplicate_between_zeros()
{
    cerr << "test duplicate_between_zeros: ";
    
    uint n = 5;
    int *a = new int[5] { 1,0,1,0,1 };
    int result1[] = { 1,0,1,1,0,1 };
    duplicate_between_zeros(a, n);
    assert(n == 6);
    for (uint i = 0; i < n; i++)
        assert(a[i] == result1[i]);
    delete[] a;

    n = 7;
    a = new int[7] { 1,0,1,1,1,0,1 };
    int result2[] = { 1,0,1,1,1,1,1,1,0,1 };
    duplicate_between_zeros(a, n);
    assert(n == 10);
    for (uint i = 0; i < n; i++)
        assert(a[i] == result2[i]);
    delete[] a;

    n = 7;
    a = new int[7] { 1,0,1,0,1,0,1 };
    int result3[] = { 1,0,1,1,0,0,1,1,0,1 };
    duplicate_between_zeros(a, n);
    assert(n == 10);
    for (uint i = 0; i < n; i++)
        assert(a[i] == result3[i]);
    delete[] a;
    
    cerr << "OK" << endl;
    return true;
}

bool test_lab11_full()
{
#ifdef _DEBUG
    return test_duplicate_between_zeros() &&
        test_find_zeros();
#elif
    return true;
#endif    
}