//
// Лабораторная работа №21. Двусвязный список
// test_lab21.cpp
//
#include <cassert>
#include <iostream>
#include <fstream>
#include "crtdynmem.h"
#include "test_lab21.h"
#include "lab21.h"

using namespace std;

array_llist test_list(const initializer_list<llist::datatype> &list, llist *&end)
{
    llist *arr_list = new llist[list.size()];
    uint i = 0;
    for (auto it = list.begin(); it!=list.end(); ++it) {
        arr_list[i].data = *it;
        arr_list[i].next = &arr_list[i + 1];
        if (i>0)
            arr_list[i].prev = &arr_list[i - 1];
        i += 1;
    }
    
    arr_list[0].prev = nullptr;
    end = &arr_list[list.size() -1];
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
	array_llist expected_list = test_list({ 1,2,3,4,5,6,7,8,9 }, ex_end);
	create_test_file(tmpname, expected_list);

	// читаем данные из файла
	llist *end = nullptr;
	llist *list = read_list(tmpname, end);

	// проверяем равенство прочитанного с исходным
	is_equal_test(list, expected_list);

	// удаляем временные данные    
	delete[] expected_list;
	delete_list(list);
	remove_item(tmpname);

	cerr << "OK" << endl;
	return true;
}

bool test_find()
{
    int n = 6;
	llist *end = nullptr;
    array_llist list = test_list({ 1,0,2,3,4,5 }, end);
    llist::datatype array[] = { 1,0,2,3,4,5 };

    for (int i = 0; i < n; ++i) {
        llist *p = find(list, array[i]);
        assert(p == &list[i]);
    }

    llist *p = find(list, -1);
    assert(p == nullptr);

    delete[] list;

    cerr << "test find: OK" << endl;
    return true;
}

bool test_length_llist(void *func)
{
    cerr << "test length_llist: ";
    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    uint (*length)(const llist *) = (uint (*)(const llist *)) func;

    // пустой список
    array_llist list = nullptr;
    uint result = length(list);    
    assert(result == 0);

    // список с одним элементом
    list = new llist{ 1, nullptr };
    result = length(list);
    assert(result == 1);
    delete list;

    // просто список
    llist *end = nullptr;
    list = test_list({ 1,2,3,4,5,6,7 }, end);
    result = length(list);
    assert(result == 7);
    delete[]list;

    cerr << "OK" << endl;
    return true;
}

bool test_find_last(void *func)
{
	cerr << "test find_last: ";
	if (func == nullptr) {
		cerr << "NOT IMPLEMENTED" << endl;
		return true;
	}
	llist *(*find_last)(const llist *, const llist *, llist::datatype) = (llist *(*)(const llist *, const llist *, llist::datatype)) func;

	int n = 6;
	llist *end = nullptr;
	array_llist list = test_list({ 1,0,2,3,4,5 }, end);
	llist::datatype array[] = { 1,0,2,3,4,5 };

	for (int i = 0; i < n; ++i) {
		llist *p = find_last(list, end, array[i]);
		assert(p == &list[i]);
	}

	llist *p = find_last(list, end, -1);
	assert(p == nullptr);

	delete[] list;

	cerr << "OK" << endl;
	return true;
}

bool test_add_first(void *func)
{
    cerr << "test add_first: ";
    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    llist *(*add_first)(llist *&, llist *&, llist::datatype ) = (llist *(*)(llist *&, llist *&, llist::datatype )) func;

    // пустой список
	llist *end = nullptr;
    llist *list = nullptr;
    llist::datatype x = 0;
	llist *ex_end = nullptr;
    array_llist expected_list = test_list({ x }, ex_end);
	    
    llist *result = add_first(list, end, x);
    
    assert(result);
    assert(result == list);
    assert(end == list);
    assert(result->data == x);
    is_equal_test(list, expected_list);

    delete result;
    delete[]expected_list;

    // список с одним элементом
    list = new llist{ 1, nullptr, nullptr };
    end = list;
    expected_list = test_list({ x, 1 }, ex_end);    
    
    result = add_first(list, end, x);
    assert(result);
    assert(result == list);
    assert(end == list->next);
    assert(result->data == x);
    is_equal_test(list, expected_list);

    delete[]result->next;
    delete result;
    delete[]expected_list;

    // просто список
    list = test_list({ 1,2,3,4,5,6,7 }, end);    
    expected_list = test_list({ x, 1,2,3,4,5,6,7 }, ex_end);

    result = add_first(list, end, x);
    assert(result);
    assert(result == list);
    assert(end == &list->next[6]);
    assert(result->data == x);
    is_equal_test(list, expected_list);

    delete[]result->next;
    delete result;
    delete[]expected_list;

    cerr << "OK" << endl;
    return true;
}

bool test_insert_before(void *func)
{
	cerr << "test insert_before: ";
	if (func == nullptr) {
		cerr << "NOT IMPLEMENTED" << endl;
		return true;
	}
	llist *(*insert_before)(llist *&, llist *&, llist *, llist::datatype) = (llist *(*)(llist *&, llist *&, llist *, llist::datatype)) func;

	// в пустой список
    llist *end = nullptr;
	llist *list = nullptr;
	llist::datatype x = 0;
    llist *ex_end = nullptr;
	array_llist expected_list = test_list({ x }, ex_end);

	llist *result = insert_before(list, end, nullptr, x);

	assert(result);
	assert(list == result);
	assert(end == result);
	assert(result->data == x);
	assert(result->prev == nullptr);
	assert(result->next == nullptr);

	delete[]expected_list;
	delete result;

	// в начало
	list = test_list({ 1,2,3,4,5,6,7 }, end);
	llist * tmp_list = list;
	expected_list = test_list({ x, 1,2,3,4,5,6,7 }, ex_end);

	result = insert_before(list, end, list, x);

	assert(result);	
	assert(list == result);
	assert(result->data == x);
	assert(result->next == tmp_list);
	assert(result->prev == nullptr);
	assert(tmp_list->prev == result);\

	is_equal_test(list, expected_list);

	delete[]list->next;
	delete list;
	delete[]expected_list;
	
	// просто список
	list = test_list({ 1,2,3,4,5,6,7 }, end);
	expected_list = test_list({ 1,2,3, x, 4,5,6,7 }, ex_end);

	result = insert_before(list, end, &list[3], x);

	assert(result);
    assert(result->data == x);
	assert(result->next == &list[3]);
    assert(result->prev == &list[2]);
	assert((&list[2])->next == result);
    assert((&list[3])->prev == result);
	is_equal_test(list, expected_list);

	delete[]list;	
	delete[]expected_list;
	delete result;

	cerr << "OK" << endl;
	return true;
}

bool test_remove_item(void *func)
{
	cerr << "test remove_item: ";
	if (func == nullptr) {
		cerr << "NOT IMPLEMENTED" << endl;
		return true;
	}
	void(*remove_item)(llist *&, llist *&, llist *) = (void(*)(llist *&, llist *&, llist *)) func;

	llist *end = nullptr;
	array_llist list = test_list({ 1,2,3,4,5,6,7 }, end);
	llist *ex_end = nullptr;
	array_llist expected_list = test_list({ 1,2,3,4,5,6,7 }, ex_end);

	// в конце
	end->next = new llist{ 8, end, nullptr };
	end = end->next;

	remove_item(list, end, end);
	is_equal_test(list, expected_list);

	// в начале
	list->prev = new llist{ 0, nullptr, list };
	list = list->prev;

	remove_item(list, end, list);
	is_equal_test(list, expected_list);

	// в середине
	list[2].next = new llist{ -1, &list[2], &list[3] };
	list[3].prev = list[2].next;

	remove_item(list, end, list[2].next);
	is_equal_test(list, expected_list);

	delete[]list;
	delete[]expected_list;

	list = test_list({ 1 }, end);

	remove_item(list, end, list);

	assert(list == nullptr);
	assert(end == nullptr);

	cerr << "OK" << endl;
	return true;
}

bool test_full_lab21()
{
#ifdef _DEBUG
	return  test_read_list() && test_find() &&
		test_length_llist(/*ваша реализация здесь*/) &&
		test_find_last(/*ваша реализация здесь*/) &&
		test_add_first(/*ваша реализация здесь*/) &&
		test_insert_before(/*ваша реализация здесь*/) &&
        test_remove_item(/*ваша реализация здесь*/);
#endif
}
