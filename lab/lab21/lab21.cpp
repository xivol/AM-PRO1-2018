//
// Лабораторная работа №21. Двусвязный список
// lab21.cpp
//
#include <cassert>
#include <iostream>
#include "crtdynmem.h"
#include "lab21.h"

using namespace std;

llist *read_list(const char *filename, llist *&end)
{
    assert(filename != nullptr);
    llist *begin = nullptr;
    end = nullptr;

    ifstream fin(filename);
    if (!fin.is_open())
        throw "Невозможно открыть файл";
    
    llist::datatype data;
    while (fin >> data)
    {
        llist *node = new llist;
        node->data = data;
        node->next = nullptr;
        node->prev = end;

        if (begin == nullptr)
            begin = node;

        if (end != nullptr)
            end->next = node;
        end = node;
    }

    return begin;
}
