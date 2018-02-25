//
// Лабораторная №5. Сортировкии, рекурсия в массивах.
// sort_time.h
//

#ifndef sort_h 
// Ключи гарантирующий 
// единственное вхождение файла
// в результирующий код
#define sort_h
#pragma once

#include <cassert>

// Объявление "функционального типа".
typedef void(* const sort_int)(int *, const size_t);
/*  
   Теперь указатель на функции вида
    void f(int *, const size_t)
   можно передавать как sort_int
*/

// Шаблонный swap для указателей
// из func_l3
template <typename T>
void swap_ptr( T *a, T *b)
{
    // проверка нулевого указателя
    assert(a != nullptr);
    assert(b != nullptr);

    T tmp = *b;
    *b = *a;
    *a = tmp;
}

// Функция сортировки массива 
// алгоритмом быстрой сортировкаи
// Параметры:
//     a — массив для сортировки;
//     n — длна массива a.
void qsort(int *a, const size_t n);

// Функция вычисления времени работы функции сортировки
// Параметры:
//     sort — указатель на функцию сортировки;
//     a — массив для сортировки;
//     n — длна массива a.
// Возращаемое значение:
// время работы функции в секундах.
double sort_time_in_seconds_for( sort_int sort, int* a, const size_t n);

#endif /* sort_h */
