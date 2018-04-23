//
// Лабораторная работа №21. Двусвязный список
// lab21.h
//
#pragma once

typedef unsigned int uint;

// Узел двусвязного списка:
//     llist::datatype - тип данных списка;
//     data - значение в узле списка;
//     prev - указатель на предидущий элемент;
//     next - указатель на следующий элемент.
struct llist
{
    typedef int datatype;
    datatype data;
    llist *prev;
    llist *next;
};

// Функция создания двусвязного списка .
// Входные параметры:
//     length - количество элементов списка.
// Выходные праметры:
//     end - указатель на конец списка.
// Возвращает указатель на первый элемент нового списка.
llist *read_list(const char *filename, llist *&end);

// Шаблонная функция удаления линейного списка.
// Входные параметры:
//     begin - указатель на начало списка.
// Выходное значение параметра begin равно nullptr.
template <typename List>
void delete_list(List *&begin)
{
    while (begin != nullptr) {
        List *t = begin;
        begin = begin->next;
        delete t;
    }
}

// Шаблонная функция вывода линейного списка на консоль.
// Входные параметры:
//     begin - указатель на начало списка.
template <typename List>
void print_list(const List *begin) 
{
    while (begin != nullptr) {
        cout << begin->data << ' ';
        begin = begin->next;
    }
    cout << endl;
}

template <typename List, typename Datatype>
List *find(const List *begin, Datatype x)
{
    const List *t = begin;

    while (t != nullptr) {
        if (t->data == x)
            break;
        t = t->next;
    }

    // снимаем константность указателя
    // т.к. мы знаем, что переданный список не константный tlist*
    return  const_cast<List *>(t);
}


// Количество элементов списка.
// Входные параметры:
//     begin - указатель на начало списка/
// Возвращает количество элементов списка
template <typename List>
uint length(const List *begin);

// Вставка элемента в начало списка.
// Входные параметры:
//     begin - указатель на начало списка;
//     x - новое значение.
// Возвращает указатель на новое начало списка.
llist *add_first(llist *&begin, llist *&end, llist::datatype x);

// Вставка элемента в конец списка.
// Входные параметры:
//     begin - указатель на начало списка;
//     x - новое значение.
// Возвращает указатель на новый конец списка.
llist *add_last(llist *&begin, llist *&end, llist::datatype x);

// Вставка нового значения перед указанным элементом списка.
// Входные параметры:
//     begin - указатель на начало списка;
//     item - указатель на элемент для вставки;
//     x - новое значение.
// Возвращает указатель на новый элемент списка.
llist *insert_before(llist *&begin, llist *&end, llist *item, llist::datatype x);

// Вставка нового значения после указанного элемента списка.
// Входные параметры:
//     begin - указатель на начало списка;
//     item - указатель на элемент для вставки;
//     x - новое значение.
// Возвращает указатель на новый элемент списка.
llist *insert_after(llist *&begin, llist *&end, llist *item, llist::datatype x);

// Удаление элемента после указанного элемента списка.
// Входные параметры:
//     item - указатель на элемент для удаления.
void remove(llist *&begin, llist *&end, llist *item);
