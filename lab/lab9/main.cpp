//
// Ћабораторна€ є9. ƒинамические массивы, замер времени выполнени€.
// main.cpp
//
#include <iostream>
#include "crtdynmem.h"
#include "lab9.h"

using namespace std;

int main()
{
	//test_full_lab9();
    setlocale(LC_ALL, "Rus");

    int *a = nullptr;  // иницилизаци€ указателей при объ€влении Ц залог успешной отладки 
    uint n = 0;

    // CоздаЄм точку отсчЄта 
    // дл€ учЄта динамически выдел€емой пам€ти
    _CrtMemState _ms;
    _CrtMemCheckpoint(&_ms);

	read(a, n);
	qsort(a, n);
	print(a, n);
    
    //delete [] a;   

	 // ќшибка Ц не освобождена динамическа€ пам€ть!     
     // выведем все утечки пам€ти с начала отсчЄта
	 _CrtMemDumpAllObjectsSince(&_ms);

     // ¬ыведем все утечки пам€ти с момента начала работы
     // _CrtDumpMemoryLeaks();
    system("pause");
    return 0;
}