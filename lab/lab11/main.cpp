#include <iostream>
#include "lab11.h"
#include "test_lab11.h"
using namespace std;

int main()
{
    test_lab11_full();
	setlocale(LC_ALL, "Rus");

	_CrtMemState _ms;
	_CrtMemCheckpoint(&_ms);

    uint rows, cols;
	double **m = nullptr;
	read_new(m, rows, cols);

    try {
		cout << "Минимальный положительный элемент: " << min_positive(m, rows, cols) << endl;
    }
    catch (char* c) {
        cout << c << endl;
    }

    print(m, rows, cols);
	delete_matrix(m, rows);

	_CrtMemDumpAllObjectsSince(&_ms);

    system("pause");
    return 0;
}