//
// Лабораторная работа №21. Двусвязный список
// main.cpp
//
#include <iostream>
#include <iomanip>
#include "crtdynmem.h"
#include "lab19.h"
#include "lab21.h"
#include "test_lab21.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    test_full_lab21();

    _CrtMemState _ms;
    _CrtMemCheckpoint(&_ms);
    
    tlist *list1 = read_list("list.txt");
    
    llist *list2_end = nullptr;
    llist *list2 = read_list("list.txt", list2_end);
    
    print_list(list1);
    tlist::datatype x;
    cout<<"Ввведите искомое значение: ";
    cin >> x;
    cout << "В списке есть элемент со значением "<<x<<": " <<boolalpha << (find(list1, x) != nullptr) << endl;
    
    print_list(list2);
    cout<<"Ввведите искомое значение: ";
    llist::datatype y;
    cin >> y;
    cout << "В списке есть элемент со значением "<<y<<": " <<boolalpha << (find(list2, y) != nullptr) << endl;

    delete_list(list1);
    delete_list(list2);

    _CrtMemDumpAllObjectsSince(&_ms);

    system("pause");
    return 0;
}
