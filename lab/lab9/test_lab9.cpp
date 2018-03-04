//
// Лабораторная №5. Сортировкии, рекурсия в массивах.
// test_sort.cpp
//
#include <cassert>
#include <iostream>
#include "test_lab9.h"

using namespace std;

bool test_name_sort_int(char *sort_name, sort_int sort)
{
	cerr << "test " << sort_name << ": ";

	if (sort == nullptr) {
		cerr << "NOT IMPLEMENTED" << endl;
		return true;
	}
	
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

    cerr <<"OK" << endl;
    return true;
}

bool test_name_find_int(char * find_name, find_int find)
{
	cerr << "test " << find_name << ": ";

	if (find == nullptr) {
		cerr << "NOT IMPLEMENTED" << endl;
		return true;
	}

	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	uint n = 10;

	int value = 9;
	int result = n - 1;
	assert(result == find(value, a, n));
	
	value = 0;
	result = 0;
	assert(result == find(value, a, n));

	value = 10;
	result = -1;
	assert(result == find(value, a, n));
	
	cerr << "OK" << endl;
	return true;
}

int *test_array(initializer_list<int> list, uint &size) {
	size = list.size();
	
	int *a = new int[size];
	
	int *p = a;
	for (auto i = list.begin(); i != list.end(); ++i) 
	{
		*p = *i;
		p++;
	}

	return a;
}

bool test_middle_insert(void *func)
{
	cerr << "test middle_insert: ";

	if (func == nullptr) {
		cerr << "NOT IMPLEMENTED" << endl;
		return true;
	}

	void(*middle_insert)(int, int*&, uint&) = (void(*)(int, int*&, uint&)) func;

	uint n;
	int value = 15;

	// Массив нечётной длины
	int *a = test_array({ 1, 0, 7, -1, 2, -3, 5 }, n);	
	int result[] = { 1, 0, 7, -1, 15, 2, -3, 5 };
	uint result_n = 8;

	middle_insert(value, a, n);
	assert(n == result_n);
	for (uint i = 0; i < n; ++i) {
		assert(a[i] == result[i]);
	}
	delete[] a;

	// Массив чётной длины
	a = test_array({ 1, 0, 7, 7, 0, 1 }, n);
	int result2[] = { 1, 0, 7, 15, 7, 0, 1 };
	result_n = 7;

	middle_insert(value, a, n);
	assert(n == result_n);
	for (uint i = 0; i < n; ++i) {
		assert(a[i] == result2[i]);
	}
	delete[] a;

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

	void(*remove_duplicates)(int *&, uint &) = (void(*)(int *&, uint &)) func;
	
	uint n;
	int *a = test_array({ 1, 1, 0, 0, 7, 7, -1, -1, 2, 2, -3, -3, 5, 5 }, n);	
	int result[] = { 1, 0, 7, -1, 2, -3, 5 };
	uint result_n = 7;

	remove_duplicates(a, n);
	assert(n == result_n);
	for (uint i = 0; i < n; ++i) {
		assert(a[i] == result[i]);
	}
	delete[] a;

	// Нет дубликатов
	a = test_array({ 1, 0, 7, -1, 2, -3, 5 }, n);
	remove_duplicates(a, n);
	assert(n == result_n);
	for (int i = 0; i < n; ++i) {
		assert(a[i] == result[i]);
	}
	delete[] a;

	cerr << "OK" << endl;
	return true;
}

bool test_full_lab9() 
{
#ifdef _DEBUG
	return test_name_sort_int("qsort", qsort) &&
		test_name_find_int("find", find) &&
		test_name_find_int("find_bin" /* ваша реализация здесь */) &&
		test_middle_insert(/* ваша реализация здесь */) &&
		test_remove_duplicates(/* ваша реализация здесь */);
#endif
}
