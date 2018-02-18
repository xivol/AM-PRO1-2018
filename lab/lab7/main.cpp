//
// Лабораторная раббота №7. Массивы, обработка массивов.
// main.cpp
//

#include <iostream>
#include "lab7.h"
#include "test_lab7.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    test_full_lab7();
    
    int a[max_N];
    int n;

    cout << "Введите массив целых чисел, содержащий ноль" << endl;

    read(a,n);
    print(a,n);
    int p = product_positive_after_zero(a, n);

    if (p != 0) 
    {
        cout << "Произведение положительных элементов после первого ноля = " << p << endl;
    }
    else 
    {
        cout << "Ошибка: последовательность не содержит ноля или положительных элементов после ноля!" << endl;
    }

    system("pause");
    return 0;
}
