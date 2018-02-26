//
// Лабораторная №5. Сортировкии, рекурсия в массивах.
// test_sort.h
// 
// Описание тестов для sort_time.h

#ifndef test_sort_h
#define test_sort_h
#pragma once

#include "sort_time.h"

// bool test_name_sort_int( sort_int sort, char* sort_name )
// Функция тестирования функций сортировки
// Параметры:
//     sort — указатель на функцию;
//     sort_name — имя тестируемой функции.
// Результат:
//     true, если все тесты завершились удачно.
bool test_name_sort_int( sort_int sort, char* sort_name );


// Немного магии препроцессора и можно вызвать 
// функцию тестирования без указания имени тестируемой функции
#define test_sort_int(sort) test_name_sort_int(sort, #sort)
/*          ^               ^
     макрос с параметром    вызов функции со вторым параметром: строкой, 
                            содержащей имя параметра макроса
*/

#endif /* test_sort_h */
