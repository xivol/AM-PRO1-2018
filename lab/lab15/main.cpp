//
// Лабораторная работа №15. Текстовые файлы. Обработка строк
// main.cpp
//
#include <iostream>
#include "lab15.h"
#include "test_lab15.h"

using namespace std;

int main()
{    
    try {
        test_full_lab15();
		cout << endl;
        print_len("jabberwocky.txt");
    }
    catch (char *error) {
        cout << error << endl;
    }
	system("pause");
    return 0;
}