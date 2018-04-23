//
// Лабораторная работа №22. Двусвязные списки. Обработка списков.
// lab22.h
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

// Функция проверки двусвязного списка на симметричность.
// Входные параметры:
//     begin - указатель на начало списка;
//     end - указатель на конецсписка.
// Возвпащает true, если список симметричен.
bool is_symmetrical(const llist *begin, const llist *end);

// Вставить новое значение в начало спискаю
// Входные параметры:
//     begin - указатель на начало списка;
//     x - новое значение.
// Возвращает указатель на новый элемент.
llist *insert_middle(llist *&begin, llist *&end, llist::datatype x);

// Удалить K элементов после элемента со значением X.
// Входные параметры:
//     begin - указатель на начало списка;
//     x - искомое значение;
//     k – количество значений для удаления.
void remove_k_after_x(llist *begin, llist *&end, llist::datatype x, uint k);

// Вставить значение X перед каждым элементом со значением Y.
// Входные параметры:
//     begin - указатель на начало списка;
//     x - новое значение;
//     y - искомое значение.
void insert_x_before_y(llist *&begin, llist *end, llist::datatype x, llist::datatype y);

// Заполнить список значениями из файла, отсортировав их по убыванию
// Входные параметры:
//     filename – имя файла данных.
// Выходные праметры:
//     end - указатель на конец списка.
// Возвращает указатель на начало списка.
llist *read_sorted(const char *filename, llist *&end );