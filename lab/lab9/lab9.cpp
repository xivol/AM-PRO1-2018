//
// Лабораторная №9. Динамические массивы, замер времени выполнения.
// lab9.cpp
//

#include <ctime>  // библиотека для работы со временем
#include <cassert>
#include <iostream>
#include "lab9.h"

using namespace std;

void read(int *&a, uint &n)
{
	assert(a == nullptr);
	cout << "Введите количество элементов: ";
	cin >> n;
	
	a = new int[n];
	cout << "Введите " << n << " элементов" << endl;
	int *p = a;
	while ((p - a) < n) {
		cin >> *p++;
	}
}

void print(const int *a, uint n)
{
	assert(a != nullptr);

	const int *p = a;
	while ((p - a) < n) {
		cout << *p++ << " ";
	}

	cout << endl;
}

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
            swap( *left, *right );
            left++;
            right--;   
        }
    }
    while ( left <= right );

    qsort( first, right );
    qsort( left, last );

}

void qsort(int *a, const uint n)
{ 
    qsort(a, a + n-1);  // вызов рекурсивной функции
}

double sort_time_in_seconds( sort_int sort, int* a, const uint n)
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

int find(int value, const int * a, const uint size)
{
	int index = -1;
	for (int i = 0; i < size; ++i)
		if (a[i] == value) index = i;
	return index;
}
