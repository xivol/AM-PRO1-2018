//
// Лабораторная №16. Двоичнвые файлы. Шаблонные функции
// test_lab16.cpp
//
#include <iostream>
#include <fstream>
#include "test_lab16.h"
#include "structs.h"

using namespace std;

bool test_number_of(const char *filename)
{
    assert(filename);
    cerr << "test number_of: ";

    fstream file(filename, ios::in);
    assert(file.is_open());

    file.seekg(0, std::fstream::end);
    uint size = (uint)file.tellg();
    file.close();

    // количество байт в файле
    assert(number_of<uint8_t>(filename) == size);

    int number_of_ints = size / sizeof(int);
    // количество int в файле
    assert(number_of<int>(filename) == number_of_ints);
    
    cerr << "OK" << endl;
    return true;
}

bool test_full_lab16()
{
#ifdef _DEBUG
    const char *input = "points.dat";
    return test_number_of(input) &&
        test_swap<double>(input /*ваша реализация здесь*/);
#else
    return true;
#endif    
}