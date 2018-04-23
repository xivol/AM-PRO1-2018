//
// Лабораторная работа №22. Двусвязные списки. Обработка списков.
// lab22.cpp
//
#include <cassert>
#include <iostream>
#include <fstream>
#include "crtdynmem.h"
#include "lab22.h"

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

bool is_symmetrical(const llist *begin, const llist *end)
{
	assert(begin != nullptr);
	assert(end != nullptr);

	while (begin != end) {
		if (begin->data != end->data)
			return false;
		if (begin->next == end)
			break;
		begin = begin->next;
		end = end->prev;
	}
	return true;
}