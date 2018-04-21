//
// Лабораторная работа №15. Двусвязный список
// main.cpp
//
#include <iostream>
#include "llist.h"
#include "test_llist.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    test_llist_full();

    char filename[32] = "llist.txt";
    llist *end;
    llist *begin = get_list(filename, end);
    print_list(begin);

    cout << (is_symmetrical(begin, end) ? "Список симметричен" : "Список не симметричен") << endl;
    delete_list(begin);

    _CrtDumpMemoryLeaks();

    system("pause");
    return 0;
}