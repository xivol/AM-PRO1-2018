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

void delete_list(tlist *&begin)
{
    while (begin != nullptr) {
        tlist *t = begin;
        begin = begin->next;
        delete t;
    }
}

void print(const tlist *begin)
{
    while (begin != nullptr) {
        cout << begin->data << ' ';
        begin = begin->next;
    }
    cout << endl;
}

// Передаём begin константой, чтобы показать что список не меняется
tlist *find(const tlist *begin, tlist::datatype x)
{
    const tlist *t =begin;
    
    while (t != nullptr) {
        if (t->data == x)
            break;
        t = t->next;
    }

    // снимаем константность указателя
    // т.к. мы знаем, что переданный список не константный tlist*
    return  const_cast<tlist *>(t);
}