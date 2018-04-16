//
// Лабораторная работа №20. Рекурсия в списках
// lab20.cpp
//

#include <cassert>
#include <iostream>
#include <fstream>
#include "lab20.h"

using namespace std;

tlist *read_list(size_t length)
{
    if (length == 0) 
        return nullptr;
    tlist *begin = nullptr;
    
    tlist::datatype data;
    if (cin >> data) {  // если чтение без ошибок

        begin = new tlist;
        begin->data = data;
        begin->next = read_list(length - 1);
    }
    
    return begin;
}

tlist *read_list(istream &fin)
{
    if (!fin.good()) 
        return nullptr;
    tlist *begin = nullptr;

    tlist::datatype data;
    if (fin >> data) {  // если чтение без ошибок

        begin = new tlist;
        begin->data = data;
        begin->next = read_list(fin);
    }

    return begin;
}

tlist *read_list(const char *filename)
{
    assert(filename != nullptr);
    tlist *begin = nullptr;

    ifstream fin(filename);
    if (!fin.is_open())
        throw "Невозможно открыть файл";

    begin = read_list(fin);
    
    fin.close();
    return begin;
}

void delete_list(tlist *&begin)
{
    if (begin == nullptr) 
        return;
    delete_list(begin->next);
    delete begin;
    begin = nullptr;
}

void print(const tlist *begin)
{
    if (begin == nullptr) 
        return;
    cout << begin->data << ' ';
    print(begin->next);    
}

tlist *find(const tlist *begin, tlist::datatype x)
{
    if (begin == nullptr) 
        return nullptr;
    if (begin->data == x) 
        return const_cast<tlist *>(begin);
    return find(begin->next, x);
}