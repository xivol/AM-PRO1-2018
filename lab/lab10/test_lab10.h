//
// Лабораторная работа №10. Двумерные массивы
// test_lab10.h
//
#pragma once
#include <cassert>
#include "lab10.h"

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

// Тестирование шаблона функции:
// template <typename T> 
// bool is_equal_matrix(const T a, const T b, const size_t m, const size_t n, const double precision)
bool test_is_equal_matrix();

// Тестирование функции:
// bool is_zeros(const double * a, const uint len, const double precision)
// Проверка нулевого и не нулевого массивов, массива с одним нолем
bool test_is_zeros();

// Тестирование функции:
// bool has_zero_row(const matrix m, const uint rows, const uint cols, const double precision)
// Проверка матрицы с нулями и без
bool test_has_zero_row();

// Тестирование функции:
// bool has_zero_col(const matrix m, const uint rows, const uint cols, const double precision)
// Проверка матрицы с нулями и без
bool test_has_zero_col();

// Тестирование функции:
// void remove_zero_cols(matrix m, const uint rows, uint &cols, const double precision)
// Проверка на удаление из нулевой матрицы, матрицы содержащейнули и матрицы без нулевых столбцов
bool test_remove_zero_cols(void *func = nullptr);

// Тестирование функции:
// void insert_row(matrix m, uint &rows, const uint cols, const double *row, const uint index)
// Проверка вставки в середину и в конец матрицы
bool test_insert_row(void *func = nullptr);

// Тестирование функции:
// void transpose(matrix m, uint &rows, uint &cols)
// Проверка транспонирования прямоугольной матрицы
bool test_transpose(void *func = nullptr);

bool test_multiply(void *func = nullptr);

// Запуск подряд всех тестов из этой библиотеки
bool test_full_lab10();