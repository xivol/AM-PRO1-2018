/* test_l3.h
 * Описание тестов функций из библиотеки func_l3.h
 */
#pragma once

// bool test_swap()
// Функциия:
// template <typename T> void swap_ptr(T *a, T*b)
// Проверка переменных типа int, double, char*.
bool test_swap();

// bool test_exp_of()
// Функциия:
// double exp_of(const double x, const double eps = precision)
// Проверка для элементрарных аргументов (0, 1), проверка параметра точности,
// сравнение результата с exp(x).
bool test_exp_of();

// bool test_sum_denominators()
// Функциия:
// uint sum_denomnators(const uint k)
// Проверка для элементрарных аргументов (0, 1, 2), проверка значения суммы.
bool test_sum_prime_factors();

// Для тестирования функций с побочным эффектом
// обычно используют некоторое логирование 
// с последующим сравнением результатов.
// Не реализовывать!
// bool test_tab();

// bool test_root()
// Функциия:
// double root(double(*const f)(double), const double a, const double b, const double eps)
// Проверить  sin [-1; 1]
//            cos [0; 2]
//            x^2 - 1 [0; 1] [-1;0] [2;0]
bool test_root();

// bool test_full_func_l3()
// Поочередный запуск всех тестов данной библиотеки
bool test_full_func_l3();