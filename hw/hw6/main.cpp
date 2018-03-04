//
// ƒомашн€€ работа є6. ƒинамические двумерные массивы
// main.cpp
//
#include <iomanip>
#include <iostream>
#include "crtdynmem.h"
#include "hw6.h"
#include "test_hw6.h"

using namespace std;

int main()
{
    test_full_hw6();
    setlocale(LC_ALL, "Rus");
    cout << fixed << setprecision(2);

    // ‘иксируем состо€ние динамической пам€ти
    _CrtMemState _ms;
    _CrtMemCheckpoint(&_ms);

    // ƒва возможных варианта работы 
    // с двумерными массивами в динамической пам€ти:
    
    // ”плотненные
    double *a = nullptr;
    // массив хранитс€ в непрерывном блоке пам€ти,
    // как статический двумерный массив double[][]

    // ѕлюсы: пам€ть выдел€етс€ только под элементы массива;
    //        линейна€ организаци€ позволет легко кешировать весь массив;
    //        освобождаетс€ одним delete[].

    // ћинусы: нельз€ использовать адресацию с двум€ индексами a[i][j];
    //         добавление, удаление строк ведЄт к пересозданию всего массива.

    uint rows, cols;
    read_new(a, rows, cols);
    print(a, rows, cols);

    cout << "¬ матрице есть нулевые строки: " << boolalpha << has_zero_row(a, rows, cols) << endl;
    cout << "¬ матрице есть нулевые столбцы: " << boolalpha << has_zero_col(a, rows, cols) << endl;
    
    delete[] a; 
    a = nullptr;

    // –азреженные
    double **m = nullptr;
    // массив указателей на отдельные строки

    // ѕлюсы: можно адресовать с двум€ индексами m[i][j];
    //        строками можно манипулировать как элементами m[i],
    //        добавление, удаление одной строки не вли€ет на остальные.

    // ћинусы: отдельный массив под каждую строку преп€тствует кешированию всей матрицы процессором
    //         замедл€€ работу с большими данными;
    //         каждую строку нужно освобождать отдельно, иначе будут утечки пам€ти.

    read_new(m, rows, cols);
    print(m, rows, cols);

    cout << "¬ матрице есть нулевые строки: " << boolalpha << has_zero_row(m, rows, cols) << endl;
    cout << "¬ матрице есть нулевые столбцы: " << boolalpha << has_zero_col(m, rows, cols) << endl;

    delete_matrix(m, rows);
    
    _CrtMemDumpAllObjectsSince(&_ms);  // провер€ем отсутствие утечек пам€ти
    
    system("pause");
    return 0;
}