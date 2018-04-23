//
// Лабораторная работа №19. Списки. Обработка списков
// lab19.cpp
//
#include <cassert>
#include <iostream>
#include <fstream>
#include "crtdynmem.h"
#include "lab19.h"

using namespace std;

tlist *read_list(const char *filename)
{
	assert(filename != nullptr);
	tlist *begin = nullptr;
	tlist *end = nullptr;

	ifstream fin(filename);
	if (!fin.is_open())
		throw "Невозможно открыть файл";

	tlist::datatype data;
	while (fin >> data) 
	{
		tlist *node = new tlist;
		node->data = data;
		node->next = nullptr;

		if (begin == nullptr)
			begin = node;

		if (end != nullptr)
			end->next = node;
		end = node;
	}

	fin.close();
	return begin;
}
