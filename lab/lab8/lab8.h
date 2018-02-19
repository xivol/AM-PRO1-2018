//
// Лабораторная работа №8. Массивы и указатели
// lab.h
// 
#pragma once

const double precision = 1E-16;

typedef double(*simple_func)(double);

void table(const simple_func funcs[], int func_size, const double points[], int points_size);

// Вывод всех значений функции на отрезке [a;b] с шагом h
// Параметры:
//      f - указатель на целевую функцию,
//      a, b - границы отрезка,
//      h - шаг табуляции (по умолчанию = precision).
// Результат:
//      вывод значений функции в виде: x | f(x)
//      для x = {a, a+h, a+2h, ... b} 
//      на стандартный вывод.
void tab(const simple_func f, const double a, const double b, const double h = precision);

// double root(double(*const f)(double), const double a, const double b, const double eps)
// Поиск корня функции на отрезке [a;b] с точностью eps методом деления пополам.
// Параметры:
//      f - указатель на целевую функцию,
//      a, b - границы отрезка (f(a)*f(b) < 0),
//      eps - точность поиска (по умолчанию = precision).
// Результат:
//      значение корня функции на отрезке.
double root(const simple_func f, const double a, const double b, const double eps = precision);