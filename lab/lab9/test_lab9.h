//
// Лабораторная №9. Динамические массивы, замер времени выполнения.
// test_lab9.h
// 
#pragma once
#include <initializer_list>
#include "lab9.h"

// Тестирование функции сортировки массива целых чисел
// Параметры:
//     sort — указатель на функцию,
//     sort_name — имя тестируемой функции.
bool test_name_sort_int(char *sort_name, sort_int sort = nullptr);

// Тестирование функции поиска в отсортированном массиве целых чисел
// Параметры:
//     find — указатель на функцию,
//     find_name — имя тестируемой функции.
bool test_name_find_int(char *find_name, find_int find = nullptr);

// Функция генерации динамического массива с заданными значениями
int *test_array(std::initializer_list<int> list, uint &size);

// Тесты функциии:
// void middle_insert(int value, int *&a, uint &size)
// Проверка случаев массива чётной и нечётной длины.
bool test_middle_insert(void *func = nullptr);

// Тесты функциии:
// void remove_duplicates(int *&a, uint &size)
// Проверка случаев наличия и отсутствия дубликатов.
bool test_remove_duplicates(void *func = nullptr);

bool test_full_lab9();
