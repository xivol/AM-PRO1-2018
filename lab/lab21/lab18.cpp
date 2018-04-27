//
// Лабораторная работа №18. Динамические структуры данных. Списки
// lab18.cpp
//
#include <cassert>
#include <iostream>
#include <fstream>
#include "crtdynmem.h"
#include "lab18.h"

using namespace std;

tlist *read_list(uint length)
{
    tlist *begin = nullptr;
    tlist *end = nullptr;

    while (length > 0) {
        tlist::datatype data;
        if (cin >> data) {  // если чтение без ошибок

            tlist *node = new tlist;
            node->data = data;
            node->next = nullptr;

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