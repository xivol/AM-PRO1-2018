//
// Лабораторная работа №18. Динамические структуры данных. Списки
// test_lab18.h
//

#pragma once
#include <initializer_list>
#include "lab18.h"

// Определим массив-список:
// массив элемнтов tlist, каждый из которых
// указывает на следующий элемент в массиве.
// Это позволит легко проверить 
// корректность указателей в тесте.
typedef tlist *array_list;

// Функция получения массива-списка из массива значений.
// Входные параметры:
//     array - массив значений элементов списка;
//     length - количество значений.
// Возвращает массив элементов tlist.
array_list test_list(const std::initializer_list<tlist::datatype> &list);

// Тест на равенство двух списков
// Входные параметры:
//     begin1 - указатель на начало первого списка;
//     begin2 - указатель на начало второго списка.
// В случае не совпадения значений элементов срабатывает assert.
bool is_equal_test(const tlist *begin1, const tlist *begin2);

// Тест для функции
// tlist *find(const tlist *begin, const tlist::datatype x)
// Проверяет случаи наличия и отсутствия элементов в списке.
bool test_find();

// Тест для функции
// uint length(const tlist *begin);
// Проверяет случаи пустого и не пустого списков.
bool test_length(void *func = nullptr);

// Тест для функции
// tlist *add_first(tlist *&begin, tlist::datatype x);
// Проверяет случаи пустого и не пустого списков.
bool test_add_first(void *func = nullptr);

// Тест для функции
// tlist *add_last(tlist *&begin, tlist::datatype x);
// Проверяет случаи пустого и не пустого списков.
bool test_add_last(void *func = nullptr);

// Тест для функции
// Проверяет случаи пустого и не пустого списков.
bool test_insert_before(void *func = nullptr);

// Тест для функции
// Проверяет случаи пустого и не пустого списков.
bool test_remove_after(void *func = nullptr);

// Тест всех функций tlist.h
bool test_full_lab18();