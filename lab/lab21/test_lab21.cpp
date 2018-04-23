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

array_llist test_list(const std::initializer_list<llist::datatype> &list)
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
    arr_list[list.size() -1].next = nullptr;
    arr_list[0].prev = nullptr;

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

bool test_length(void *func)
{
    cerr << "test length: ";
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
    list = test_list({ 1,2,3,4,5,6,7 });
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

    llist *r_end = nullptr;
    llist *result = add_first(list, r_end, x);
    
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
    
    result = add_first(list, r_end, x);
    assert(result);
    assert(result == list);
    assert(r_end == list->next);
    assert(result->data == x);
    is_equal_test(list, result_list);

    delete[]result->next;
    delete result;
    delete[]result_list;

    // просто список
    list = test_list({ 1,2,3,4,5,6,7 });
    result_list = test_list({ x, 1,2,3,4,5,6,7 });

    result = add_first(list, r_end, x);
    assert(result);
    assert(result == list);
    assert(r_end == &list->next[6]);
    assert(result->data == x);
    is_equal_test(list, result_list);

    delete[]result->next;
    delete result;
    delete[]result_list;

    cerr << "OK" << std::endl;
    return true;
}

bool test_add_last(void *func)
{
    cerr << "test add_last: ";
    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    llist *(*add_last)(llist *&, llist *&, llist::datatype) = (llist *(*)(llist *&, llist *&, llist::datatype)) func;

    // пустой список
    llist *list = nullptr;
    llist::datatype x = 0;
    array_llist result_list = test_list({ x });

    llist *r_end = nullptr;
    llist *result = add_last(list, r_end, x);

    assert(result);
    assert(result == list);
    assert(result == r_end);
    assert(result->data == x);
    is_equal_test(list, result_list);

    delete result;
    delete[]result_list;

    // список с одним элементом
    list = new llist{ 1, nullptr };
    result_list = test_list({ 1, x });

    result = add_last(list, r_end, x);
    assert(result);
    assert(result == r_end);
    assert(result->data == x);
    is_equal_test(list, result_list);

    delete[]list;
    delete result;
    delete[]result_list;

    // просто список
    list = test_list({ 1,2,3,4,5,6,7 });
    result_list = test_list({ 1,2,3,4,5,6,7, x });

    result = add_last(list, r_end, x);
    assert(result);
    assert(result == r_end);
    assert(result->data == x);
    is_equal_test(list, result_list);

    delete[]list;
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
	llist *list = nullptr;
	llist::datatype x = 0;
	array_llist result_list = test_list({ x });

	llist *result = insert_before(list, nullptr, x);

	assert(result);
	assert(result->next == nullptr);
	assert(result->data == x);
	is_equal_test(list, result_list);

	delete[]result_list;
	delete result;

	// просто список
	list = test_list({ 1,2,3,4,5,6,7 });
	result_list = test_list({ 1,2,3,x,4,5,6,7 });

	result = insert_before(list, &list[3], x);

	assert(result);
	assert(result->next == &list[3]);
	assert((&list[2])->next == result);
	assert(result->data == x);
	is_equal_test(list, result_list);

	delete[]list;	
	delete[]result_list;
	delete result;

	cerr << "OK" << std::endl;
	return true;
}

bool test_remove_after(void *func)
{
	cerr << "test remove_after: ";
	if (func == nullptr) {
		cerr << "NOT IMPLEMENTED" << endl;
		return true;
	}
	void(*remove)(llist *&, llist *&, llist *) = (void(*)(llist *&, llist *&, llist *)) func;

	array_llist list = test_list({ 1,2,3,4,5,6,7 });
	(&list[2])->next = new llist{ 0, &list[3] };
	array_llist result_list = test_list({ 1,2,3,4,5,6,7 });
	
	remove(&list[2]);

	assert((&list[2])->next == &list[3]);
	is_equal_test(list, result_list);

	delete[]list;
	delete[]result_list;

	list = test_list({ 1 });
	result_list = test_list({ 1 });

	remove(&list[0]);

	is_equal_test(list, result_list);

	delete[]list;
	delete[]result_list;

	cerr << "OK" << std::endl;
	return true;
}


bool test_full_lab18()
{
#ifdef _DEBUG
	return  test_find() &&        
		test_length(/*ваша реализация здесь*/) &&
		test_add_first(/*ваша реализация здесь*/) &&
		test_add_last(/*ваша реализация здесь*/) &&
		test_insert_before(/*ваша реализация здесь*/) &&
		test_remove_after(/*ваша реализация здесь*/);
#endif
}
