//
// Лабораторная работа №21. Двусвязный список
// lab21.cpp
//
#include <cassert>
#include <iostream>
#include "crtdynmem.h"
#include "lab21.h"

using namespace std;

llist *read_list(uint length, llist *&end)
{
    llist *begin = nullptr;
    end = nullptr;

    while (length > 0) 
    {
        llist::datatype data;
        if (cin >> data)   // если чтение без ошибок
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
        length--;
    }

    return begin;
}
