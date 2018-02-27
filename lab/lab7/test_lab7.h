//
// Лабораторная раббота №7. Массивы, обработка массивов.
// test_lab7.h
//
#pragma once

// Точность сравнения вещественных чисел
const double precision = 1E-10;

// Пример объявления функционального типа
typedef int(*int_array_func)(const int a[], int n);

// Тесты функциии:
// int find_zero(const int a[], int n)
// Проверка случаев: есть ноль, нет ноля.
bool test_first_zero(int_array_func f);

// Тесты функциии:
// int product_positive_after_zero(const int a[], int n)
// Проверка случаев: начальный ноль, конечный ноль, нет ноля.
bool test_product_positive_after_zero(int_array_func f);

// Тесты функциии:
// double divide_sums_around_min(const double a[], int n)
// Проверка случаев: минимум первый, минимум последний, минимум в середине массива.
bool test_divide_sums_around_min(void *func = nullptr);

// Тесты функциии:
// void remove_duplicates(int a[], int &n)
// Проверка случаев: нет дубликатов, каждый элемент продублирован один раз, несколько дубликатов подряд.
bool test_remove_duplicates(void *func = nullptr);

// Тесты функциии:
// void insert_duplicates(int a[], int &n)
// Проверка корректности вставки.
bool test_insert_duplicates(void *func = nullptr);

// Тесты функциии:
// bool is_symmetrical(const int a[], int n, int startIndex = 0)
// Проверка случаев: симметричный, не симматричный массивы; массивы чётной и нечётной длины.
bool test_is_symmetrical(void *func = nullptr);

// Запуск подряд всех тестов из
bool test_full_lab7();