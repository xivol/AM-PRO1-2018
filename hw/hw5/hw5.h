#pragma once

typedef unsigned int uint;

typedef double(*simple_func)(double);

typedef void(*sort_int)(int*, const uint);

// Построение таблицы скорости сортировок
// Параметры:
//     sort – массив функций сортировки,
//     sort_number – количество функций сортировок,
//     min, max – границы количества элементов,
//     rows – количество строк таблицы.
// Результат:
//     N|    sort1|    sort2|    ...
//   min|      ...|      ...|    ...
//   ...|      ...|      ...|    ...
//   max|      ...|      ...|    ...
void sort_time_print(const sort_int *sort, const uint sort_number, const uint min, const uint max, const uint rows)

// Поиск элементов массива x с минимальным расстоянием между точками (x, y = f(x)).
// Параметры:
//      f - указатель на целевую функцию,
//      x - указатель на массив значений абсцисс точек,
//      size - количество тоек,
//      index1, index2 - выходные параметры.
// Возвращаемое значение:
//      минимальное расстояние между точками,
//      index1, index2 - индексы точек с минимальным расстоянием.
double min_distance(const simple_func f, const double *x, const uint size, int &min_index1, int &min_index2);

// Удалить из массива все элементы, меньшие среднего арифметического элементов массива.
// Выделяет динамическую память!
void remove_less_avg(double *&a, uint &size);

// Вставить между каждой парой элементов значение разности этих элементов.
// Выделяет динамическую память!
void insert_diff(double *&a, uint &size);