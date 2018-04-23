//
// Лабораторная работа №21. Двусвязный список
// test_lab21.h
//

#pragma once
#include <cassert>
#include <initializer_list>
#include "lab21.h"

// Определим массив-список:
// массив элемнтов tlist, каждый из которых
// указывает на следующий элемент в массиве.
// Это позволит легко проверить 
// корректность указателей в тесте.
typedef llist *array_llist;

// Функция получения массива-списка из массива значений.
// Входные параметры:
//     list - список инициализации.
// Возвращает массив элементов tlist.
array_llist test_list(const std::initializer_list<llist::datatype> &list);

// Тест на равенство двух списков
// Входные параметры:
//     begin1 - указатель на начало первого списка;
//     begin2 - указатель на начало второго списка.
// В случае не совпадения значений элементов срабатывает assert.
template <typename List>
bool is_equal_test(const List *begin1, const List *begin2)
{
    while (begin1 != nullptr && begin2 != nullptr) {
        // совпадение результата с исходными данными
        assert(begin1->data == begin2->data);
        begin1 = begin1->next;
        begin2 = begin2->next;
    }
    // совпадение количества результатов с исходным количеством
    assert(begin1 == begin2);
    return true;
}

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