//
// Лабораторная работа №11. Динамические массивы. Обработка ошибок.
// lab11.cpp
//
#include <cassert>
#include <climits>
#include <iostream>
#include <iomanip>
#include "crtdynmem.h"
#include "lab11.h"

#ifndef DBL_MAX
#define DBL_MAX __DBL_MAX__
#endif

using namespace std;

void read_new(double** &m, uint &rows, uint &cols)
{
	assert(m == nullptr);
	cout << "Введите количество строк " << endl;
	cin >> rows;
	cout << "Введите количество столбцов " << endl;
	cin >> cols;

	// выделяем массив указателей
	m = new double*[rows];

	cout << "Введите " << rows*cols << " элементов" << endl;
	for (uint i = 0; i < rows; ++i) {
		// выделяем память под каждую строку отдельно
		m[i] = new double[cols];
		for (uint j = 0; j < cols; ++j)
			cin >> m[i][j];
	}
}

void delete_matrix(double **& m, const uint rows, const uint cols)
{
	assert(m != nullptr);

	// Освобождаем память занимаемую строками
	for (uint i = 0; i < rows; ++i)
		delete[] m[i];

	// Освобождаем память занимаемую массивом строк
	delete[] m;
	// Обнуляем указатель
	m = nullptr;
}

void print(double const*const* m, const uint rows, const uint cols)
{
	assert(m != nullptr);

	for (uint i = 0; i < rows; ++i) {
		for (uint j = 0; j < cols; ++j) {
			cout << setw(cout.precision() * 2 + 1);
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

double min_positive(const double *a, const uint size)
{
	assert(a != nullptr);

	double min = DBL_MAX;
	for (uint i = 0; i < size; ++i)
		if (a[i] > 0 && a[i] < min)
			min = a[i];
	if (min == DBL_MAX) // значение не изменилось
		throw "Нет положительных элементов в массиве";
	return min;
}

double min_positive(double const* const* m, const uint rows, const uint cols)
{
	assert(m != nullptr);
	double min = DBL_MAX;
	for (uint i = 0; i < rows; ++i)
	{
        try 
        {
            double row_min = min_positive(m[i], cols);
            if (row_min < min) min = row_min;
        }
        catch (char *c) { // если в строке нет положительных чисел            
            continue;
        }		
	}
	if (min == DBL_MAX) // значение не изменилось
		throw "Нет положительных элементов в матрице";
	return min;
}
