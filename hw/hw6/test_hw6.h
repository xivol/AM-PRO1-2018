//
// Домашняя работа №6. Динамические двумерные массивы
// test_hw6.h
//
#pragma once
#include <cassert>
#include <initializer_list>
#include "hw6.h"

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

// Функция генерации разреженного динамического массива с заданными значениями
double **test_sparce_matrix(const std::initializer_list<std::initializer_list<double>> &m, uint &rows, uint &cols);

// Тестирование шаблона функции:
// template <typename T> 
// bool is_equal_matrix(const T a, const T b, const size_t m, const size_t n, const double precision)
bool test_is_equal_matrix();

// Тестирование функции:
// bool is_zeros(const double * a, const uint len, const double precision)
// Проверка нулевого и не нулевого массивов, массива с одним нолем
bool test_is_zeros();

// Тестирование функции:
// bool has_zero_row(const double *a, const uint rows, const uint cols, const double precision)
// Проверка матрицы с нулями и без
bool test_has_zero_row_compact();

// Тестирование функции:
// bool has_zero_row(double const* const* m, const uint rows, const uint cols, const double precision)
// Проверка матрицы с нулями и без
bool test_has_zero_row_sparce();

// Тестирование функции:
// bool has_zero_col(const double *a, const uint rows, const uint cols, const double precision)
// Проверка матрицы с нулями и без
bool test_has_zero_col_compact();

// Тестирование функции:
// bool has_zero_col(double const* const* m, const uint rows, const uint cols, const double precision)
// Проверка матрицы с нулями и без
bool test_has_zero_col_sparce();

// Запуск всех тестов библиотеки
bool test_full_hw6();