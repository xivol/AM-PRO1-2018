//
// Лабораторная работа №11. Динамические массивы.
// test_lab11.cpp
//
#pragma once
#include <initializer_list>
#include "lab11.h"

// Шаблон функции сравнения двух матриц на равенство.
// Входные параметры:
//     a, b - указатели на начало массива,
//     rows - количество строк матриц а, b,
//     cols - количество количество столбцов матриц а, b,
//     precision - точность сравнения, по умолчанию = 0.
// Возвращаемое значение:
//     true - если все элементы матриц равны.
template <typename T>
bool is_equal_matrix(const T a, const T b, const uint rows, const uint cols, const double precision = 0.0)
{
    assert(a != nullptr);
    assert(b != nullptr);
    if (a == b) return true;

    for (uint i = 0; i < rows; ++i)
        for (uint j = 0; j < cols; ++j)
            if (fabs(a[i][j] - b[i][j]) > precision)
                return false;
    return true;
}

// Функция генерации динамического массива с заданными значениями
double *test_array(const std::initializer_list<double> &list, uint &size);

// Функция генерации разреженного динамического массива с заданными значениями
double **test_sparce_matrix(const std::initializer_list<std::initializer_list<double>> &m, uint &rows, uint &cols);

bool test_min_positive();

bool test_min_positive_matrix();

bool test_major_div_minor(void *func = nullptr);

bool test_append_col(void *func = nullptr);

bool test_remove_rows(void *func = nullptr);

bool test_lab11_full();
