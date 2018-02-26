//
// Лабораторная работа №8. Массивы и указатели
// lab.h
// 
#pragma once

typedef double(*simple_func)(double);
typedef unsigned int uint;

const double precision = 1E-16;
const uint max_N = 100;

// Вывод вещественного числа по указателю
void print_float(float * t);

// Вывод целого числа по указателю
void print_int(int * t);



// Вывод значения функций в точке по указателю на функцию
// Параметры:
//      f - указатель на целевую функцию,
//      x - значение функции.
void print_func(simple_func f, double x, uint precision);

// Поменять местами значения заданного размера
// Параметры:
//      a, b - указатели на значения,
//      size - размер значений в байтах.
void swap(void * a, void * b, uint size);

// Вывод всех значений функции на отрезке [a;b] с шагом h
// Параметры:
//      f - указатель на целевую функцию,
//      a, b - границы отрезка,
//      h - шаг табуляции (по умолчанию = precision).
// Результат:
//      вывод значений функции в виде: x: | f(x):
//      для x = {a, a+h, a+2h, ... b} 
//      на стандартный вывод.
void tab(const simple_func f, const double a, const double b, const double h = precision);

// Поиск корня функции на отрезке [a;b] с точностью eps методом деления пополам.
// Параметры:
//      f - указатель на целевую функцию,
//      a, b - границы отрезка (f(a)*f(b) < 0),
//      eps - точность поиска (по умолчанию = precision).
// Возвращаемое значение:
//      значение корня функции на отрезке.
double root(const simple_func f, const double a, const double b, const double eps = precision);

// Ввод массива с клавиатуры
// Параметры:
//     a – массив, который будет заполнен,
//     n – размер введенного массива.
void read(double *a, int &n);

// Вывод массива на консоль
// Параметры:
//     a – массив,
//     n – размер массива.
void print(const double *a, int n);

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