//
// Лабораторная №11. Динамические массивы. Обработка ошибок.
// main.cpp
//
#include <iomanip>
#include <iostream>
#include "lab11.h"
#include "test_lab11.h"
#include "crtdynmem.h"

using namespace std;

int main()
{	
    test_lab11_full();
	setlocale(LC_ALL, "Rus");
    cout << fixed << setprecision(2);

    _CrtMemState _ms;
    _CrtMemCheckpoint(&_ms);

    uint rows, cols;
	double **m = nullptr;
	read_new(m, rows, cols);
    print(m, rows, cols);

    try 
    {
		cout << "Минимальный положительный элемент: " << min_positive(m, rows, cols) << endl;
    }
    catch (char *error) 
    {
        cout << error << endl;
    }
        
	delete_matrix(m, rows);

	_CrtMemDumpAllObjectsSince(&_ms);
    _CrtDumpMemoryLeaks();

    system("pause");
    return 0;
}
