//
// Лабораторная работа №14. Текстовые файлы. Обработка чисел
// lab14.cpp
//
#include <cassert>
#include <cctype>
#include <fstream>
#include <iostream>
#include "crtdynmem.h"
#include "lab14.h"

using namespace std;

bool is_eol(char c)
{
    return c == '\r' || c == '\n';
}

bool eol(std::istream &is)
{
    while (isspace(is.peek()) && !is_eol(is.peek()))
        is.get();
       
    if (is_eol(is.peek()))
    {
        return !is.eof();
    }
    return is.eof();
}

void read_from_text(const char* fname, int *&array, uint &size)
{
    assert(fname != nullptr);
    assert(array == nullptr);
    ifstream fin(fname);

    if (!fin.is_open()) // если файл не найден
        throw "Не найден указанный файл";

    if (!(fin >> size) || !eol(fin)) // если первый элемент файла - не число
        throw "Неверный формат входного файла";

    array = new int[size];
    uint i = 0;
    while (i < size && fin >> array[i++] && !eol(fin));

    // если число элементов в файле меньше указанного размера
    if (i != size || !fin.good() && !eol(fin)) {
        if (fin.good()) size = i;
        else size = i - 1;
        
        // сохраняем реальные данные
        int *b = new int[size];
        for (uint j = 0; j < size; ++j)
            b[j] = array[j];
        
        // удаляем слишком длинный массив
        delete[] array;
        array = b;
    }

    fin.close();
}

void print_to_stream(std::ostream &os, const int *a, uint n)
{
    assert(a != nullptr);
    assert(os);

    const int *p = a;
    while ((p - a) < n) {
        os << *p++ << " ";
    }

    os << endl;
}