 //
 // Лабораторная работа №22. Двусвязные списки. Обработка списков.
// test_lab22.cpp
//

#include <cassert>
#include <iostream>
#include <initializer_list>
#include <fstream>
#include "crtdynmem.h"
#include "test_lab22.h"
#include "lab22.h"

using namespace std;

array_llist test_list(const initializer_list<llist::datatype> &list, llist *&end)
{
	llist *arr_list = new llist[list.size()];
	uint i = 0;
	for (auto it = list.begin(); it != list.end(); ++it) {
		arr_list[i].data = *it;
		arr_list[i].next = &arr_list[i + 1];
		if (i>0)
			arr_list[i].prev = &arr_list[i - 1];
		i += 1;
	}

	arr_list[0].prev = nullptr;
	end = &arr_list[list.size() - 1];
	end->next = nullptr;

	return arr_list;
}

void create_test_file(const char* filename, const llist *begin)
{
	ofstream file(filename);
	if (!file.is_open())
		throw "Невозможно открыть файл";
	while (file.good() && begin != nullptr)
	{
		file << ' ' << begin->data;
		begin = begin->next;
	}
	file.close();
}

bool test_read_list()
{
	cerr << "test read_list: ";
	const char *tmpname = "list.tmp";
	// получаем тестовые данные
	llist *ex_end = nullptr;
	array_llist expected_list= test_list({ 1,2,3,4,5,6,7,8,9 }, ex_end);
	create_test_file(tmpname, expected_list);

	// читаем данные из файла
	llist *end = nullptr;
	llist *list = read_list(tmpname, end);

	// проверяем равенство прочитанного с исходным
	is_equal_test(list, expected_list);

	// удаляем временные данные    
	delete[] expected_list;
	delete_list(list);
	remove(tmpname);

	cerr << "OK" << endl;
	return true;
}

bool test_is_symmetrical()
{
	// проверка для списка чётной длины
	size_t  n = 10;
	llist *end;
	llist *list = test_list({ 0, 1, 2, 3, 4, 4, 3, 2, 1, 0 }, end);

	for (size_t i = 0; i < n / 2; i++) {
		assert(is_symmetrical(&list[i], &list[n - i - 1]));
		if (i != n - i - 2)
			assert(!is_symmetrical(&list[i], &list[n - i - 2]));
	}

	delete[] list;

	// проверка для списка нечётной длины
	n = 9;
	list = test_list({ 1, 0, 1, 0, 1, 0, 1, 0, 1 }, end);

	for (size_t i = 0; i < n / 2; i++) {
		assert(is_symmetrical(&list[i], &list[n - i - 1]));
		assert(is_symmetrical(&list[i], &list[i + 2]));
		assert(is_symmetrical(&list[i], &list[i + 4]));
		assert(!is_symmetrical(&list[i], &list[i + 1]));
		assert(!is_symmetrical(&list[i], &list[i + 3]));
	}
	delete[] list;


	cerr << "test is_symmetrical: OK" << endl;
	return true;
}

bool test_insert_middle(void *func)
{
	cerr << "test insert_mddle: ";
	if (func == nullptr) {
		cerr << "NOT IMPLEMENTED" << endl;
		return true;
	}
	llist *(*insert_middle)(llist *&, llist *&, llist::datatype ) = (llist *(*)(llist *&, llist *&, llist::datatype)) func;

	// пустой список
	llist *end = nullptr;
	array_llist list = nullptr;
	llist::datatype x = 0;
	llist *ex_end = nullptr;
	array_llist expected_list = test_list({ x }, ex_end);

	llist * result = insert_middle(list, end, x);

	assert(result);
	assert(result == list);
	assert(result->next == nullptr);
	assert(result->data == x);
	is_equal_test(list, expected_list);

	delete result;
	delete[] expected_list;

	// в конец списка
	list = test_list({ 1 }, end);
	expected_list = test_list({ 1, x }, ex_end);

	result = insert_middle(list, end, x);

	assert(result);
	assert(list->next == result);
	assert(result->next == nullptr);
	assert(result->data == x);
	is_equal_test(list, expected_list);

	delete result;
	delete[] list;
	delete[] expected_list;

	// четное количество элементов
	list = test_list({ 1, 2 }, end);
	expected_list = test_list({ 1, x, 2 }, ex_end);

	result = insert_middle(list, end, x);

	assert(result);
	assert(list->next == result);
	assert(result->next == &list[1]);
	assert(result->data == x);
	is_equal_test(list, expected_list);

	delete result;
	delete[] list;
	delete[] expected_list;

	// нечетное количество элементов
	list = test_list({ 1, 2, 3 }, end);
	expected_list = test_list({ 1, 2, x, 3 }, ex_end);

	result = insert_middle(list, ex_end, x);

	assert(result);
	assert((&list[1])->next == result);
	assert(result->next == &list[2]);
	assert(result->data == x);
	is_equal_test(list, expected_list);

	delete result;
	delete[] list;
	delete[] expected_list;
	
	cerr << "OK" << endl;
	return true;
}

bool test_remove_k_after_x(void *func)
{
    cerr << "test remove_k_after_x: ";
    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    void (*remove_k_after_x)(llist *, llist *&, llist::datatype, uint) = (void (*)(llist *, llist *&, llist::datatype, uint )) func;
    
	llist *end = nullptr;
    array_llist list = test_list({ 1,2,3,4,5,6,7,8,9 }, end);
    llist::datatype x = 0;
	uint k = 1;
	llist *ex_end = nullptr;
    array_llist expected_list = test_list({ 1,2,3,4,5,6,7,8,9 }, ex_end);
    
	remove_k_after_x(list, end, x, k);
    is_equal_test(list, expected_list);

    list[0].next = new llist{ 0, &list[0] , list[0].next};
    x = list[0].data;
    remove_k_after_x(list, end, x, k);
    is_equal_test(list, expected_list);

    delete[] list;
    delete[] expected_list;
    
    list = test_list({ 1,1,2,1,1 }, end);
    x = 1;
    for (int i = 0; i < 5; ++i)
        if(list[i].data == x)
            list[i].next = new llist{ 0, &list[i], list[i].next };
    expected_list = test_list({ 1,1,2,1,1 }, ex_end);
    
    remove_k_after_x(list, end, x, k);
    is_equal_test(list, expected_list);

    delete[] list;
    delete[] expected_list;

    list = test_list({ 1,1,2,1,1 }, end);
    k = 2;
    x = 1;
    for (int i = 0; i < 5; ++i)
        if (list[i].data == x) {
            list[i].next = new llist{ 0, &list[i], list[i].next };
            list[i].next = new llist{ 0, &list[i], list[i].next };
        }
    expected_list = test_list({ 1,1,2,1,1 }, ex_end);

    remove_k_after_x(list, end, x, k);
    is_equal_test(list, expected_list);

    delete[] list;
    delete[] expected_list;

    cerr << "OK" << endl;
    return true;
}

bool test_insert_x_before_y(void *func)
{
    cerr << "test insert_x_before_y: ";
    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    void (*insert_x_before_y)(llist *&, llist *, llist::datatype, llist::datatype) = (void (*)(llist *&, llist *, llist::datatype, llist::datatype)) func;

	llist *end = nullptr;
    array_llist list = test_list({ 1,2,3,4 }, end);
    llist::datatype x = 0;
    llist::datatype y = 1;
	llist *ex_end = nullptr;
    array_llist expected_list = test_list({ 0,1,2,3,4 }, ex_end);
    
    insert_x_before_y(list, end, x, y);
    is_equal_test(list, expected_list);
    
    delete[] list->next;
    delete list;
    delete[] expected_list;

    list = test_list({ 2,1,2,1,2 }, end);
    expected_list = test_list({ 2,0,1,2,0,1,2 }, ex_end);

    insert_x_before_y(list, end, x, y);
    is_equal_test(list, expected_list);
    
    delete list->next;
    delete (&list[2])->next;
    delete[] list;
    delete[] expected_list;
    
    cerr << "OK" << endl;
    return true;
}

bool test_read_sorted(void *func)
{
    cerr << "test read_sorted: ";
    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    llist *(*read_sorted)(const char *, llist *&) = (llist *(*)(const char *, llist *&)) func;

    const char *tmpfile = "tmpfile.txt";
	llist *ex_end = nullptr;
    array_llist expected_list = test_list({ 0,1,2,3,4,5 }, ex_end);
    create_test_file(tmpfile, expected_list);

	llist *end = nullptr;
    llist *list = read_sorted(tmpfile, end);
    is_equal_test(list, expected_list);

    delete[] list;

    list = test_list({ 5,3,4,1,2,0 }, end);
    create_test_file(tmpfile, list);
    delete[] list;

    list = read_sorted(tmpfile, end);
    is_equal_test(list, expected_list);

    delete[] list;
    delete[] expected_list;

    remove(tmpfile);
    cerr << "OK" << endl;
    return true;
}

bool test_full_lab22()
{
	return  test_read_list() &&
		test_is_symmetrical() &&
		test_insert_middle(/*ваша реализация здесь*/) &&
		test_remove_k_after_x(/*ваша реализация здесь*/) &&
        test_insert_x_before_y(/*ваша реализация здесь*/) &&
        test_read_sorted(/*ваша реализация здесь*/);
}
