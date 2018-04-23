//
// Лабораторная работа №22. Двусвязные списки. Обработка списков.
// main.cpp
//
#include <iostream>
#include "crtdynmem.h"
#include "lab22.h"
#include "test_lab22.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	test_full_lab22();

	_CrtMemState _ms;
	_CrtMemCheckpoint(&_ms);

	llist *end;
	llist *begin = read_list("list.txt", end);
	print_list(begin);

	cout << (is_symmetrical(begin, end) ? "Список симметричен" : "Список не симметричен") << endl;

	delete_list(begin);

	_CrtMemDumpAllObjectsSince(&_ms);

	system("pause");
	return 0;
}