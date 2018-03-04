//
// Лабораторная работа №10. Двумерные массивы
// lab10.h
//
#pragma once

typedef unsigned int uint;
const double precision = 1E-15;

// Максимальное количество строк
const uint max_ROWS = 10;
// Максимальное количество столбцов
const uint max_COLS = 10;
// Пользовательский тип вещественной матрицы
typedef double matrix[max_ROWS][max_COLS];

// Максимальная длина статического массива
const uint MAX_N = max_COLS * max_ROWS;

// Вывод массива на консоль
// Параметры:
//     a – указатель на начало массива,
//     len – размер массива.
void print(const double *a, const uint len);

// Вывод массива на консоль в виде матрицы
// Параметры:
//     a – указатель на начало массива,
//     rows - количество строк для вывода,
//     cols - количество элементов в строке.
void print_as_matrix(const double * a, const uint rows, const uint cols);

// Ввод двумерного массива c клавиатуры
// Параметры:
//     m - указатель на начало массива,
//     rows - количество строк массива m,
//     cols - количество столбцов массива m.
void read( matrix m, uint &rows, uint &cols);

// Вывод двумерного массива на консоль
// Параметры:
//     m - указатель на начало массива,
//     rows - количество строк массива (по умолчанию max_ROWS),
//     cols - количество столбцов массива (по умолчанию max_COLS).
void print(const matrix m, const uint rows = max_ROWS, const uint cols = max_COLS);

// Проверка, что массив состоит из нолей
// Параметры:
//     a – указатель на начало массива,
//     len – размер массива,
//     precision – точность сравнения.
// Возвращаемое значение:
//     true, если все элементы равны нолю.
bool is_zeros(const double * a, const uint len, const double precision = 0.0);

// Проверка, что в матрице есть нолевой столбец
// Параметры:
//     m – указатель на начало массива,
//     rows - количество строк массива,
//     cols - количество столбцов массива,
//     precision – точность сравнения.
// Возвращаемое значение:
//     true, если существует столбец из нолей.
bool has_zero_col(const matrix m, const uint rows, const uint cols, const double precision = 0.0);

// Проверка, что в матрице есть нолевая строка
// Параметры:
//     m – указатель на начало массива,
//     rows - количество строк массива,
//     cols - количество столбцов массива,
//     precision – точность сравнения.
// Возвращаемое значение:
//     true, если существует строка из нолей.
bool has_zero_row(const matrix m, const uint rows, const uint cols, const double precision = 0.0);

// Удаление из матрицы всех нолевых столбцов
// Параметры:
//     m – указатель на начало массива,
//     rows – количество строк массива,
//     cols – количество столбцов массива,
//     precision – точность сравнения.
// Результат:
//     m – матрица без нолевых столбцов,
//     cols – новое число столбцов.
void remove_zero_cols(matrix m, const uint rows, uint &cols, const double precision = 0.0);

// Вставка в матрицу строки в заданную позицию, со смещением остальных строк вниз
// Параметры:
//     m – указатель на начало массива,
//     rows – количество строк массива,
//     cols – количество столбцов массива,
//     row – вставляемая строка,
//     index – индекс позиции для вставки.
// Результат:
//     m – матрица со вставленной строкой row в позиции index,
//     rows – новое число строк.
void insert_row(matrix m, uint &rows, const uint cols, const double *row, const uint index);

// Транспонирование прямоугольной матрицы
// Параметры:
//     m – указатель на начало массива,
//     rows – количество строк массива,
//     cols – количество столбцов массива.
// Результат:
//     m – транспонированная матрица,
//     rows – новое число строк,
//     cols – новое число столбцов.
void transpose(matrix m, uint &rows, uint &cols);

// Умножение прямоугольных матриц:
// С = А*В
// Параметры:
//     a, b, с – указатели на начало матриц,
//     a_rows, a_cols – количество строк и столбцов первой матрицы,
//     b_rows, b_cols – количество строк и столбцов второй матрицы.
void multiply(const matrix a, const uint a_rows, const uint a_cols, const matrix b, const uint b_rows, const uint b_cols, matrix c);
