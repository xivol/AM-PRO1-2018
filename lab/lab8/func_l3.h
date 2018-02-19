/* func_l3.h
 * Описание функций к Лабораторной работе №3.
 */
#pragma once
#include <cassert>

/* Глобальная константа : точность вычислений,
 * будет доступна во всех файлах, подключающий данный заголовок.
 */
const double precision = 1E-16;

/* Определение пользовательского типа uint,
 * как неотрицательного целого числа.
 * (разрядность int зависит от разрядности системы)
 */
typedef unsigned int uint;

// void swap_ptr (T *a, T *b)
// Шаблон функции обмена значениями двух переменных по указателю
// Параметры:
//      a, b - указатели на переменные.
// Результат:
//      параметры a и b  меняются значениям.
template <typename T>
void swap_ptr(T *a, T *b)
{
    assert(a != nullptr);
    assert(b != nullptr);
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

// double exp_of(const double x, const double eps = precision);
// Вычисление значения экспоненты с заданной точностью.
// Параметры:
//      x - значение аргумента функции,
//      eps - точность вычислений (по умолчанию = precision).
// Результат:
//      занчение e(x) с точностью eps.
double exp_of(const double x, const double eps = precision);

// uint sum_prime_factors(const uint k);
// Вычисление суммы простых делителей целого числа с помощью рекурсии.
// Параметры:
//      k - неотрицательное целое число.
// Результат:
//      сумма простых делителей числа k.
uint sum_prime_factors(const uint k);

// void tab(double(* const f)(double), const double a, const double b, const double h);
// Вывод всех значений функции на отрезке [a;b] с шагом h
// Параметры:
//      f - указатель на целевую функцию,
//      a, b - границы отрезка,
//      h - шаг табуляции (по умолчанию = precision).
// Результат:
//      вывод значений функции в виде: x | f(x)
//      для x = {a, a+h, a+2h, ... b} 
//      на стандартный вывод.
void tab( double(* const f)(double), const double a, const double b, const double h = precision);

// double root(double(*const f)(double), const double a, const double b, const double eps)
// Поиск корня функции на отрезке [a;b] с точностью eps методом деления пополам.
// Параметры:
//      f - указатель на целевую функцию,
//      a, b - границы отрезка (f(a)*f(b) < 0),
//      eps - точность поиска (по умолчанию = precision).
// Результат:
//      значение корня функции на отрезке.
double root(double(*const f)(double), const double a, const double b, const double eps = precision);