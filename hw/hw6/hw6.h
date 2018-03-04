//
// Домашняя работа №6. Динамические двумерные массивы
// hw6.h
//
#pragma once

typedef unsigned int uint;
const double precision = 1E-15;

// Ввод двумерного массива c клавиатуры
// Параметры:
//     a - указатель на начало массива,
//     rows - количество строк массива m,
//     cols - количество столбцов массива m.
void read_new(double* &a, uint &rows, uint &cols);

// Ввод двумерного массива c клавиатуры
// Параметры:
//     m - указатель на начало массива,
//     rows - количество строк массива m,
//     cols - количество столбцов массива m.
void read_new(double** &m, uint &rows, uint &cols);

// Освобождение памяти занимаемой двумерным массивом
// Параметры:
//     m - указатель на начало массива,
//     rows - количество строк массива m,
//     cols - количество столбцов массива m.
void delete_matrix(double** &m, const uint rows, const uint cols = 0);

// Вывод массива на консоль в виде матрицы
// Параметры:
//     a – указатель на начало массива,
//     rows - количество строк для вывода,
//     cols - количество элементов в строке.
void print(const double * a, const uint rows, const uint cols);

// Вывод матрицы на консоль
// Параметры:
//     m – указатель на начало массива,
//     rows - количество строк для вывода,
//     cols - количество элементов в строке.
void print(double const* const* m, const uint rows, const uint cols);

// Проверка, что массив состоит из нолей
// Параметры:
//     a – указатель на начало массива,
//     len – размер массива,
//     precision – точность сравнения.
// Возвращаемое значение:
//     true, если все элементы равны нолю.
bool is_zeros(const double * a, const uint len, const double precision = ::precision);

// Проверка, что в матрице есть нолевой столбец
// Параметры:
//     a – указатель на начало массива,
//     rows - количество строк массива,
//     cols - количество столбцов массива,
//     precision – точность сравнения.
// Возвращаемое значение:
//     true, если существует столбец из нолей.
bool has_zero_col(const double *a, const uint rows, const uint cols, const double precision = ::precision);

// Проверка, что в матрице есть нолевой столбец
// Параметры:
//     m – указатель на начало массива,
//     rows - количество строк массива,
//     cols - количество столбцов массива,
//     precision – точность сравнения.
// Возвращаемое значение:
//     true, если существует столбец из нолей.
bool has_zero_col(double const* const* m, const uint rows, const uint cols, const double precision = ::precision);

// Проверка, что в матрице есть нолевая строка
// Параметры:
//     a – указатель на начало массива,
//     rows - количество строк массива,
//     cols - количество столбцов массива,
//     precision – точность сравнения.
// Возвращаемое значение:
//     true, если существует строка из нолей.
bool has_zero_row(const double *a, const uint rows, const uint cols, const double precision = ::precision);

// Проверка, что в матрице есть нолевая строка
// Параметры:
//     m – указатель на начало массива,
//     rows - количество строк массива,
//     cols - количество столбцов массива,
//     precision – точность сравнения.
// Возвращаемое значение:
//     true, если существует строка из нолей.
bool has_zero_row(double const* const* m, const uint rows, const uint cols, const double precision = ::precision);