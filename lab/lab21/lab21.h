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

// Функция создания двусвязного списка чтением с консоли.
// Входные параметры:
//     filename - количество элементов списка.
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

// Шаблонная функция поиска элемента с заданным значением
// Входные параметры:
//     begin - указатель на начало списка;
// Возвращает указатель на заданный элемент.
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


// Шаблонная функция вычисления количества элементов в списке.
// Входные параметры:
//     begin - указатель на начало списка.
// Возвращает количество элементов списка
template <typename List>
uint length(const List *begin);

// Поиск заданного значения с конца списка
// Входные параметры:
//     begin - указатель на начало списка;
//     end - указатель на конец списка;
//     x - новое значение.
// Возвращает указатель на новый конец списка.
llist *find_last(const llist *begin, const llist *end, llist::datatype x);

// Вставка элемента в начало списка.
// Входные параметры:
//     begin - указатель на начало списка;
//     end - указатель на конец списка;
//     x - новое значение.
// Возвращает указатель на новое начало списка.
llist *add_first(llist *&begin, llist *&end, llist::datatype x);

// Вставка нового значения перед указанным элементом списка.
// Входные параметры:
//     begin - указатель на начало списка;
//     end - указатель на конец списка;
//     item - указатель на элемент для вставки;
//     x - новое значение.
// Возвращает указатель на новый элемент списка.
llist *insert_before(llist *&begin, llist *&end, llist *item, llist::datatype x);

// Удаление указанного элемента списка.
// Входные параметры:
//     begin - указатель на начало списка;
//     end - указатель на конец списка;
//     item - указатель на элемент для удаления.
void remove(llist *&begin, llist *&end, llist *item);
