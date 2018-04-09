//
// Лабораторная работа №19. Списки. Обработка списков.
// test_lab19.h
//

#pragma once

#include "lab19.h"

// Определим массив-список:
// массив элемнтов tlist, каждый из которых
// указывает на следующий элемент в массиве.
// Это позволит легко проверить 
// корректность указателей в тесте.
typedef tlist *array_list;

// Функция получения массива-списка из массива значений.
// Входные параметры:
//     list - список инициализации.
// Возвращает массив элементов tlist.
array_list test_list(const std::initializer_list<tlist::datatype> &list);

// Тест на равенство двух списков
// Входные параметры:
//     begin1 - указатель на начало первого списка;
//     begin2 - указатель на начало второго списка.
// В случае не совпадения значений элементов срабатывает assert.
bool is_equal_test(const tlist *begin1, const tlist *begin2);

bool test_read_list();

bool test_insert_middle(void *func = nullptr);

// Тест всех функций tlist.h
bool test_full_lab19();