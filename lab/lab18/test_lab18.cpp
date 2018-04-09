//
// Лабораторная работа №18. Динамические структуры данных. Списки
// test_lab18.cpp
//
#include <cassert>
#include <iostream>
#include "crtdynmem.h"
#include "test_lab18.h"
#include "lab18.h"

using namespace std;


bool is_equal_test(const tlist *begin1, const tlist *begin2)
{    
    while (begin1 != nullptr && begin2 != nullptr) {
        // совпадение результата с исходными данными
        assert(begin1->data == begin2->data);
        begin1 = begin1->next;
        begin2 = begin2->next;
    }
    // совпадение количества результатов с исходным количеством
    assert(begin1 == begin2);
    return true;
}

array_list test_list(const std::initializer_list<tlist::datatype> &list)
{
    tlist *arr_list = new tlist[list.size()];
    uint i = 0;
    for (auto it = list.begin(); it!=list.end(); ++it) {
        arr_list[i].data = *it;
        arr_list[i].next = &arr_list[i+1];
        i += 1;
    }
    arr_list[list.size() -1].next = nullptr;

    return arr_list;
}

bool test_find()
{
    int n = 6;
    array_list list = test_list({ 1,0,2,3,4,5 });
    tlist::datatype array[] = { 1,0,2,3,4,5 };

    for (int i = 0; i < n; ++i) {
        tlist *p = find(list, array[i]);
        assert(p == &list[i]);
    }

    tlist *p = find(list, -1);
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
    uint (*length)(const tlist *) = (uint (*)(const tlist *)) func;

    // пустой список
    array_list list = nullptr;
    uint result = length(list);    
    assert(result == 0);

    // список с одним элементом
    list = new tlist{ 1, nullptr };
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
    tlist *(*add_first)(tlist *&, tlist::datatype ) = (tlist *(*)(tlist *&, tlist::datatype )) func;

    // пустой список
    tlist *list = nullptr;
    tlist::datatype x = 0;
    array_list result_list = test_list({ x });

    tlist *result = add_first(list, x);
    
    assert(result);
    assert(result == list);
    assert(result->data == x);
    is_equal_test(list, result_list);

    delete result;
    delete[]result_list;

    // список с одним элементом
    list = new tlist{ 1, nullptr };
    result_list = test_list({ x, 1 });    
    
    result = add_first(list, x);
    assert(result);
    assert(result == list);
    assert(result->data == x);
    is_equal_test(list, result_list);

    delete[]result->next;
    delete result;
    delete[]result_list;

    // просто список
    list = test_list({ 1,2,3,4,5,6,7 });
    result_list = test_list({ x, 1,2,3,4,5,6,7 });

    result = add_first(list, x);
    assert(result);
    assert(result == list);
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
    tlist *(*add_last)(tlist *&, tlist::datatype) = (tlist *(*)(tlist *&, tlist::datatype)) func;

    // пустой список
    tlist *list = nullptr;
    tlist::datatype x = 0;
    array_list result_list = test_list({ x });

    tlist *result = add_last(list, x);

    assert(result);
    assert(result->next == nullptr);
    assert(result->data == x);
    is_equal_test(list, result_list);

    delete result;
    delete[]result_list;

    // список с одним элементом
    list = new tlist{ 1, nullptr };
    result_list = test_list({ 1, x });

    result = add_last(list, x);
    assert(result);
    assert(result->next == nullptr);
    assert(result->data == x);
    is_equal_test(list, result_list);

    delete[]result->next;
    delete result;
    delete[]result_list;

    // просто список
    list = test_list({ 1,2,3,4,5,6,7 });
    result_list = test_list({ 1,2,3,4,5,6,7, x });

    result = add_last(list, x);
    assert(result);
    assert(result->next == nullptr);
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
	tlist *(*insert_before)(tlist *&, tlist *, tlist::datatype) = (tlist *(*)(tlist *&, tlist *, tlist::datatype)) func;

	// пустой список
	tlist *list = nullptr;
	tlist::datatype x = 0;
	array_list result_list = test_list({ x });

	tlist *result = insert_before(list, nullptr, x);

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
	tlist *(*remove_after)(tlist *) = (tlist *(*)(tlist *)) func;

	array_list list = test_list({ 1,2,3,4,5,6,7 });
	(&list[2])->next = new tlist{ 0, &list[3] };
	array_list result_list = test_list({ 1,2,3,4,5,6,7 });
	
	remove_after(&list[2]);

	assert((&list[2])->next == &list[3]);
	is_equal_test(list, result_list);

	delete[]list;
	delete[]result_list;

	list = test_list({ 1 });
	result_list = test_list({ 1});

	remove_after(&list[0]);

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
