//
// Лабораторная №11. Динамические массивы. Обработка ошибок.
// lab11.h
//
#pragma once

typedef unsigned int uint;
const double precision = 1E-15;

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

// Вывод массива на консоль
// Параметры:
//     a – массив,
//     n – размер массива.
void print(const int *a, uint n);

// Вывод матрицы на консоль
// Параметры:
//     m – указатель на начало массива,
//     rows - количество строк для вывода,
//     cols - количество элементов в строке.
void print(double const* const* m, const uint rows, const uint cols);

// Найти минимальное положительное значение в массиве
double min_positive(const double *a, const uint size);

// Найти минимальное положительное значение в матрице
double min_positive(double const* const* m, const uint rows, const uint cols);

// Найти отношение сумм элементов на главной и побочной диагоналях матрицы
double major_div_minor(double const* const* a, const uint rows, const uint cols);

typedef double aggregate(const double*, const uint);
// Добавить в матрицу столбец результат вычисления заданной аггрегатной фнкции для каждой строки
void append_col(double** &a, const uint rows, uint &cols, aggregate aggr);

typedef bool condition(const double*, const uint);
// Удалить из матрицы строки удволетворяющие заданному функцией условию.
void remove_rows(double** &a, uint &rows, const uint cols, condition cond);
