//
// Лабораторная №5. Сортировкии, рекурсия в массивах.
// test_sort.cpp
//
// Реализация тестов.

#include <cassert>
#include <iostream>
#include "test_sort.h"

using namespace std;

bool test_name_sort_int( sort_int sort, char* sort_name )
{
    // переместить последний элемент в начало
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    int n = 10;
    sort(a, n);
    for(int i = 1; i < n; ++i)
        assert(a[i-1] <= a[i]);

    // массив случайных чисел
    for(int i = 0; i < n; i++)
        a[i] = rand();
    sort(a, n);
    for(int i = 1; i < n; ++i)
        assert(a[i-1] <= a[i]);

    // массив дубликатов
    for (int i = 0; i < n / 2; i++)
        a[i] = a[n - 1 - i] = rand();
    sort(a, n);
    for (int i = 1; i < n; ++i)
        assert(a[i - 1] <= a[i]);

#ifdef _DEBUG
    cerr << "test " <<sort_name<< ": "<<"OK" << endl;
#endif /* _DEBUG */
    return true;
}
