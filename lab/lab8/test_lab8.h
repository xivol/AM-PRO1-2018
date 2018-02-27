//
// Лабораторная работа №8. Работа с указателями
// test_lab8.h
//
#pragma once

// Функциия:
// void swap_ptr(void *a, void *b, uint size)
// Проверка переменных типа int, double, char.
bool test_swap_ptr(void *f = nullptr);

// Для тестирования функций с побочным эффектом
// обычно используют некоторое логирование (запись в файл)
// с последующим сравнением результатов.
// bool test_tab();

// Функциия:
// double root(double(*const f)(double), const double a, const double b, const double eps)
// Проверить  sin [-1; 1]
//            cos [0; 2]
//            x^2 - 1 [0; 1] [-1;0] [2;0]
bool test_root(void *func = nullptr);

// Функциия:
// bool all(condition f, const int *x, const uint size)
bool test_all(void *func = nullptr);

// Поочередный запуск всех тестов данной библиотеки
bool test_full_lab8();