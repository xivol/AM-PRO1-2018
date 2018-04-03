//
// Лабораторная №16. Двоичнвые файлы. Шаблонные функции
// main.cpp
//
#include <iostream>
#include "structs.h"
#include "test_lab16.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    test_full_lab16();

    // откроем файл на чтение
    fstream file("points.dat", ios::in);
    // перейдём в конец файла
    file.seekg(0, fstream::end);
    // выведем позицию файлового указателя
    cout << "Размер файла: " << file.tellg() << " байт" << endl;
    
    file.close();

    uint count_points = number_of<point>("points.dat");
    cout << "Количество точек в файле: " << count_points << endl;

    system("pause");
    return 0;
}