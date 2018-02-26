//
// Лабораторная №5. Сортировкии, рекурсия в массивах.
// sort_time.cpp
//

#include <ctime>  // библиотека для работы со временем
#include <iostream>
#include "sort_time.h"

// Рекурсивная функция быстрой сортировки:
// first - указатель на первый элемент массива,
// last  - указатель на последний элемент массива.
void qsort(int *first, int *last)
{ 
    if( first >= last ) return;

    int *left = first;
    int *right = last;
    int *mid = left + (right-left)-1 /2  ;
    do{
        while( *left < *mid ) left++;
        while( *right > *mid ) right--;

        if( left <= right ){
            swap_ptr( left, right );
            left++;
            right--;   
        }
    }
    while ( left <= right );

    qsort( first, right );
    qsort( left, last );

}

// Функция сортировки массива
// алгоритмом быстрой сортировки
void qsort(int *a, const size_t n)
{ 
    qsort(a, a + n-1);  // вызов рекурсивной функции
}

// Функция замера времени средствами ctime
double sort_time_in_seconds_for( sort_int sort, int* a, const size_t n)
{

    // начало отсчета времени
    clock_t start = clock();
    
    // код для которого замеряем время
    sort(a, n);
    
    // конец отсчета времени
    clock_t stop = clock();
    
    // количество секунд
    double seconds = double(stop - start) / CLOCKS_PER_SEC ;
    
    return seconds;
}