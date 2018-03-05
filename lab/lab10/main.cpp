//
// Лабораторная работа №10. Двумерные массивы
// main.cpp
//
#include <iomanip>
#include <iostream>
#include "lab10.h"
#include "test_lab10.h"

using namespace std;

int main()
{
    test_full_lab10();
    setlocale(LC_ALL, "Rus");
    double a[MAX_N] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
    uint n = 16;

    cout << fixed << setprecision(2);

    cout << endl << "Исходный массив:" << endl;
    print(a, n);
    cout << endl << endl;

    // Выведем массив, как матицу заданного размера
    uint rows = 3, cols = 5;
    cout << "Вывод массива как матрицы " << rows << "x" << cols << ":" << endl;
    print_as_matrix(a, rows, cols);

    // Попробуем преобразовать массив в матрицу   
    void *p = a;  // избавляемся от информации об исходном типе

    // Прямое преобразование указателей на статический массив не допускается
    // Используем преобразование ссылок
    matrix &ma = *(matrix*)p;

    cout << endl << "Вывод массива с преобразованием к matrix:" << endl;
    // тип matrix имеет размер 10х10
    // ожидается что каждая строка имеет длину 10
    print(ma);
    cout << endl;

    // Работа с матрицами

    matrix m = {}; // инициализируем нолями!
    read(m, rows, cols);

    cout << "Матрица:" << endl;
    print(m, rows, cols);
    cout << endl;

    cout << "В виде массива:" << endl;
    print(&m[0][0], rows*max_COLS);
    cout << endl << endl;
    
    cout << "В матрице есть нулевые строки: " << boolalpha << has_zero_row(m, rows, cols) << endl;
    cout << "В матрице есть нулевые столбцы: " << boolalpha << has_zero_col(m, rows, cols) << endl;

    system("pause");
    return 0;
}