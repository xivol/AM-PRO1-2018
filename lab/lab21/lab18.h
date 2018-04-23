//
// Лабораторная работа №18. Динамические структуры данных. Списки
// lab18.h
//
#pragma once

typedef unsigned int uint;

// Узел списка:
//     tlist::datatype - тип данных списка;
//     data - значение в узле списка;
//     next - указатель на следующий элемент.
struct tlist
{
    typedef int datatype;
    datatype data;
    tlist *next;
};

// Функция создания списка.
// Данные вводятся с конслои.
// Входные параметры:
//     length - количество элементов списка.
// Возвращает указатель на первый элемент списка.
tlist *read_list(const uint length);