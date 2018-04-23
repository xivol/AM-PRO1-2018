//
// Лабораторная работа №21. Двусвязный список
// test_lab21.cpp
//
#include <cassert>
#include <iostream>
#include "crtdynmem.h"
#include "test_lab21.h"
#include "lab18.h"
#include "lab21.h"

using namespace std;

array_llist test_list(const std::initializer_list<llist::datatype> &list, llist *&end)
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
    end = arr_list[list.size() -1];
    end.next = nullptr;

    return arr_list;
}

bool test_find()
{
    int n = 6;
    array_llist list = test_list({ 1,0,2,3,4,5 });
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

    cerr << "OK" << std::endl;
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
    llist *list = nullptr;
    llist::datatype x = 0;
    array_llist result_list = test_list({ x });

    llist *end = nullptr;
    llist *result = add_first(list, end, x);
    
    assert(result);
    assert(result == list);
    assert(r_end == list);
    assert(result->data == x);
    is_equal_test(list, result_list);

    delete result;
    delete[]result_list;

    // список с одним элементом
    list = new llist{ 1, nullptr };
    result_list = test_list({ x, 1 });    
    
    result = add_first(list, end, x);
    assert(result);
    assert(result == list);
    assert(end == list->next);
    assert(result->data == x);
    is_equal_test(list, result_list);

    delete[]result->next;
    delete result;
    delete[]result_list;

    // просто список
    list = test_list({ 1,2,3,4,5,6,7 }, end);
    llist *r_end = nullptr;
    result_list = test_list({ x, 1,2,3,4,5,6,7 }, r_end);

    result = add_first(list, end, x);
    assert(result);
    assert(result == list);
    assert(end == &list->next[6]);
    assert(result->data == x);
    is_equal_test(list, result_list);

    delete[]result->next;
    delete result;
    delete[]result_list;

    cerr << "OK" << std::endl;
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

	// пустой список
    llist *end = nullptr;
	llist *list = nullptr;
	llist::datatype x = 0;
    llist *r_end = nullptr;
	array_llist result_list = test_list({ x }, r_end);

	llist *result = insert_before(list, end, nullptr, x);

	assert(result);
	assert(result->next == nullptr);
	assert(result->data == x);
	is_equal_test(list, result_list);

	delete[]result_list;
	delete result;

	// просто список
	list = test_list({ 1,2,3,4,5,6,7 }, end);
	result_list = test_list({ 1,2,3,x,4,5,6,7 }, r_end);

	result = insert_before(list, end, &list[3], x);

	assert(result);
    assert(result->data == x);
	assert(result->next == &list[3]);
    assert(result->prev == &list[2]);
	assert((&list[2])->next == result);
    assert((&list[3])->prev == result);
	is_equal_test(list, result_list);

	delete[]list;	
	delete[]result_list;
	delete result;

	cerr << "OK" << std::endl;
	return true;
}

bool test_remove_first(void *func)
{
	cerr << "test remove_first: ";
	if (func == nullptr) {
		cerr << "NOT IMPLEMENTED" << endl;
		return true;
	}
	void(*remove_first)(llist *&, llist *&) = (void(*)(llist *&, llist *&)) func;
    
    
    // не пустой список
    llist *end = nullptr;
	array_llist list = test_list({ 1,2,3,4,5,6,7 }, end);
	list = new llist{ 0, list, nullptr };
    list->next->prev = list;
    
    llist *r_end = nullptr;
	array_llist result_list = test_list({ 1,2,3,4,5,6,7 }, r_end);
	
	remove_first(list, end);

	is_equal_test(list, result_list);
    
    delete[]list;
	delete[]result_list;

    // пустой список
    list = new llist{1, nullptr, nullptr};
	result_list = nullptr;

	remove_first(list, end);
    
	is_equal_test(list, result_list);

	cerr << "OK" << std::endl;
	return true;
}


bool test_full_lab21()
{
#ifdef _DEBUG
	return  test_find() &&        
		test_length_llist(/*ваша реализация здесь*/) &&
        test_find_last(/*ваша реализация здесь*/) &&
		test_add_first(/*ваша реализация здесь*/) &&
		test_insert_before(/*ваша реализация здесь*/) &&
		test_remove_first(/*ваша реализация здесь*/) &&
        test_remove_last(/*ваша реализация здесь*/) &&
        test_remove(/*ваша реализация здесь*/);
#endif
}
