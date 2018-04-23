//
// Лабораторная работа №20. Рекурсия в списках
// main.cpp
//


#include <iostream>
#include "crtdynmem.h"
#include "lab20.h"
#include "test_lab20.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    test_full_lab20();

    _CrtMemState _ms;
    _CrtMemCheckpoint(&_ms);
    
    uint n;
    cout << "Введите количество элементов списка" << endl;
    cin >> n;
    cout << "Введите элементы списка" << endl;
    tlist * list = read_list(n);

    tlist *p = find(list, 0);
    int cnt = 0;
    while (p) {  // p != nullptr
        cnt++;
        p = find(p->next, 0);
    }

    cout << "Количество нулевых элементов: " << cnt << endl;
    delete_list(list);

    _CrtMemDumpAllObjectsSince(&_ms);

    system("pause");
    return 0;
}