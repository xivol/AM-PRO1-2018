//
// Лабораторная №9. Динамические массивы, замер времени выполнения.
// main.cpp
//
#include <iostream>
#include "crtdynmem.h"
#include "test_lab9.h"
#include "lab9.h"

using namespace std;

int main()
{
	test_full_lab9();
    setlocale(LC_ALL, "Rus");

    int *a = nullptr;  // иницилизация указателей при объявлении – залог успешной отладки 
    uint n = 0;

    // Cоздаём точку отсчёта 
    // для учёта динамически выделяемой памяти
    _CrtMemState _ms;
    _CrtMemCheckpoint(&_ms);

	read(a, n);
	qsort(a, n);
	print(a, n);
    
    //delete [] a;   

	 // Ошибка – не освобождена динамическая память!     
     // выведем все утечки памяти с начала отсчёта
	 _CrtMemDumpAllObjectsSince(&_ms);

     // Выведем все утечки памяти с момента начала работы
     // _CrtDumpMemoryLeaks();
    system("pause");
    return 0;
}