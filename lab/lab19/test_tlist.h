//
// Лабораторная работа №13. Динамические структуры данных. Списки
// test_tlist.h
//

#pragma once

#include "tlist.h"

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
array_list get_array_list(const tlist::datatype *array, uint length);

// Тест для функции
// array_list get_array_list(const tlist::datatype *array, size_t length)
// Проверяет корректность структуры массива-списка и значений в списке.
bool test_get_array_list();

// Функция создания тестовых данных для проверки создания списка
// Входные данные:
//     filename - имя создаваемого файла данных;
//     length - количество данных.
// Возвращает указатель намассив данных и создаёт на диске файл 
// с заданным именем, содержащий те же данные.
// Если создать файл не удаётся, выбрасывает исключение char*.
tlist::datatype *create_test_data(const char* filename, uint length);

// Тест для функции
// tlist::datatype *create_test_data(const char* filename, size_t length)
// Сравнивает значение в файле с возращаемым массивом.
bool test_create_test_data();

// Тест на равенство массива и списка
// Входные параметры:
//     begin - указатель на начало списка;
//     array - указател на начапло массива;
//     length - длина массива.
// В случае не совпадения значений элементов срабатывает assert.
bool is_equal_test(const tlist *begin, tlist::datatype *array, uint length);


// Тест для функции
// tlist *find(const tlist *begin, const tlist::datatype x)
// Проверяет случаи наличия и отсутствия элементов в списке.
bool test_find();

// Тест всех функций tlist.h
bool test_tlist_full();