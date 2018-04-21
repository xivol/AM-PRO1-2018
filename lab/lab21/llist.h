//
// Лабораторная работа №15. Двусвязный список
// llist.h
//
#pragma once

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

// Функция создания двусвязного списка на основе односвязного.
// Входные параметры:
//     filename - имя файла данных.
// Выходные праметры:
//     end - указатель на конец списка.
// Возвращает указатель на первый элемент нового списка.
llist *get_list(const char *filename, llist *&end);

// Функция проверки двусвязного списка на симметричность.
// Входные параметры:
//     begin - указатель на начало списка;
//     end - указатель на конецсписка.
// Возвпащает true, если список симметричен.
bool is_symmetrical(const llist *begin, const llist *end);

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