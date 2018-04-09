//
// Лабораторная работа №18. Динамические структуры данных. Списки
// main.cpp
//


#include <iostream>
#include "crtdynmem.h"
#include "tlist.h"
#include "test_tlist.h"

using namespace std;

int main()
{
   setlocale(LC_ALL, "Russian");
    test_full_lab18();

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

    _CrtDumpMemoryLeaks();
    
    system("pause");
    return 0;
}