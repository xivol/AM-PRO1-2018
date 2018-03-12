//
// Лабораторная работа №11. Динамические массивы. Обработка ошибок.
// lab11.cpp
//
#include <cassert>
#include <iostream>
#include "crtdynmem.h"
#include "lab11.h"

using namespace std;

void read_new(int *&a, uint &n)
{
	assert(a == nullptr);
	cout << "Введите количество элементов: ";
	cin >> n;
	
	a = new int[n];
	cout << "Введите " << n << " элементов" << endl;
	int *p = a;
	while ((p - a) < n) {
		cin >> *p++;
	}
}

void print(const int *a, uint n)
{
	assert(a != nullptr);

	const int *p = a;
	while ((p - a) < n) {
		cout << *p++ << " ";
	}

	cout << endl;
}

void find_zeros(const int* array, const uint size, uint &first, uint &last)
{
    assert(array != nullptr);
    assert(size > 0);

    first = -1;
    last = -1;
    for (uint i = 0; i < size; i++)
        if (array[i] == 0) {
            if (first == -1) first = i;
            last = i;
        }

    if (first == -1) throw "Нет нолей в массиве";

    assert(first != -1);
    assert(last != -1);
}

void duplicate_between_zeros(int *&array, uint &size)
{
    assert(array != nullptr);
    assert(size > 0);

    uint f = 0, l = 0;
    find_zeros(array, size, f, l);
    if (f == l) throw "Один ноль в массиве";
    if (f + 1 == l) return;  // нечего дублировать

    int* b = new int[size + l - f - 1];

    for (uint i = 0; i <= f; i++)
        b[i] = array[i];

    int j = f + 1;
    for (uint i = j; i < l; i++, j += 2) {
        b[j] = array[i];
        b[j + 1] = array[i];
    }

    for (uint i = l; i < size; i++, j++)
        b[j] = array[i];

    assert(j == size + l - f - 1);

    size += l - f - 1;
    delete[] array;
    array = b;
}