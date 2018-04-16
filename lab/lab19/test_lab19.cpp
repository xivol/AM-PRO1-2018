 //
 // Лабораторная работа №19. Списки. Обработка списков.
// test_lab19.cpp
//

#include <cassert>
#include <iostream>
#include <initializer_list>
#include <fstream>
#include "crtdynmem.h"
#include "test_lab19.h"
#include "lab19.h"

using namespace std;

void create_test_file(const char* filename, const tlist *begin)
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
	for (auto it = list.begin(); it != list.end(); ++it) {
		arr_list[i].data = *it;
		arr_list[i].next = &arr_list[i + 1];
		i += 1;
	}
	arr_list[list.size() - 1].next = nullptr;

	return arr_list;
}

bool test_read_list()
{
	cerr << "test read_list: ";
    const char *tmpname = "list.tmp";    
    // получаем тестовые данные
	array_list array = test_list({ 1,2,3,4,5,6,7,8,9 });
	create_test_file(tmpname, array);

    // читаем данные из файла
    tlist *list = read_list(tmpname);

    // проверяем равенство прочитанного с исходным
    is_equal_test(list, array);
    
    // удаляем временные данные    
    delete [] array;    
    delete_list(list);
	remove(tmpname);

	cerr << "OK" << endl;
    return true;
}

bool test_insert_middle(void *func)
{
	cerr << "test insert_mddle: ";
	if (func == nullptr) {
		cerr << "NOT IMPLEMENTED" << endl;
		return true;
	}
	tlist *(*insert_middle)(tlist *&, tlist::datatype ) = (tlist *(*)(tlist *&, tlist::datatype)) func;

	// пустой список
	array_list list = nullptr;
	tlist::datatype x = 0;
	array_list result_list = test_list({ x });

	tlist * result = insert_middle(list, x);

	assert(result);
	assert(result == list);
	assert(result->next == nullptr);
	assert(result->data == x);
	is_equal_test(list, result_list);

	delete result;
	delete[] result_list;

	// в конец списка
	list = test_list({ 1 });
	result_list = test_list({ 1, x });

	result = insert_middle(list, x);

	assert(result);
	assert(list->next == result);
	assert(result->next == nullptr);
	assert(result->data == x);
	is_equal_test(list, result_list);

	delete result;
	delete[] list;
	delete[] result_list;

	// четное количество элементов
	list = test_list({ 1, 2 });
	result_list = test_list({ 1, x, 2 });

	result = insert_middle(list, x);

	assert(result);
	assert(list->next == result);
	assert(result->next == &list[1]);
	assert(result->data == x);
	is_equal_test(list, result_list);

	delete result;
	delete[] list;
	delete[] result_list;

	// нечетное количество элементов
	list = test_list({ 1, 2, 3 });
	result_list = test_list({ 1, 2, x, 3 });

	result = insert_middle(list, x);

	assert(result);
	assert((&list[1])->next == result);
	assert(result->next == &list[2]);
	assert(result->data == x);
	is_equal_test(list, result_list);

	delete result;
	delete[] list;
	delete[] result_list;
	
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
    void (*remove_k_after_x)(tlist *, tlist::datatype, uint) = (void (*)(tlist *, tlist::datatype, uint )) func;
    
    array_list list = test_list({ 1,2,3,4,5,6,7,8,9 });
    tlist::datatype x = 0;
    uint k = 1;
    array_list result_list = test_list({ 1,2,3,4,5,6,7,8,9 });
    remove_k_after_x(list, x, k);
    is_equal_test(list, result_list);

    list[0].next = new tlist{ 0, list[0].next };
    x = list[0].data;
    remove_k_after_x(list, x, k);
    is_equal_test(list, result_list);

    delete[] list;
    delete[] result_list;
    
    list = test_list({ 1,1,2,1,1 });
    x = 1;
    for (int i = 0; i < 5; ++i)
        if(list[i].data == x)
            list[i].next = new tlist{ 0, list[i].next };
    result_list = test_list({ 1,1,2,1,1 });
    
    remove_k_after_x(list, x, k);
    is_equal_test(list, result_list);

    delete[] list;
    delete[] result_list;

    list = test_list({ 1,1,2,1,1 });
    k = 2;
    x = 1;
    for (int i = 0; i < 5; ++i)
        if (list[i].data == x) {
            list[i].next = new tlist{ 0, list[i].next };
            list[i].next = new tlist{ 0, list[i].next };
        }
    result_list = test_list({ 1,1,2,1,1 });

    remove_k_after_x(list, x, k);
    is_equal_test(list, result_list);

    delete[] list;
    delete[] result_list;

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
    void (*insert_x_before_y)(tlist *&, tlist::datatype, tlist::datatype) = (void (*)(tlist *&, tlist::datatype, tlist::datatype)) func;

    array_list list = test_list({ 1,2,3,4 });
    tlist::datatype x = 0;
    tlist::datatype y = 1;
    array_list result_list = test_list({ 0,1,2,3,4 });
    
    insert_x_before_y(list, x, y);
    is_equal_test(list, result_list);
    
    delete[] list->next;
    delete list;
    delete[] result_list;

    list = test_list({ 2,1,2,1,2 });
    result_list = test_list({ 2,0,1,2,0,1,2 });

    insert_x_before_y(list, x, y);
    is_equal_test(list, result_list);
    
    delete list->next;
    delete (&list[2])->next;
    delete[] list;
    delete[] result_list;
    
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
    tlist *(*read_sorted)(const char *) = (tlist *(*)(const char *)) func;

    const char *tmpfile = "tmpfile.txt";
    array_list result_list = test_list({ 0,1,2,3,4,5 });
    create_test_file(tmpfile, result_list);

    tlist *list = read_sorted(tmpfile);
    is_equal_test(list, result_list);

    delete[] list;

    list = test_list({ 5,3,4,1,2,0 });
    create_test_file(tmpfile, list);
    delete[] list;

    list = read_sorted(tmpfile);
    is_equal_test(list, result_list);

    delete[] list;
    delete[] result_list;

    remove(tmpfile);
    cerr << "OK" << endl;
    return true;
}

bool test_full_lab19()
{
    return  test_read_list() &&
        test_insert_middle(/*ваша реализация здесь*/) &&
        test_remove_k_after_x(/*ваша реализация здесь*/) &&
        test_insert_x_before_y(/*ваша реализация здесь*/) &&
        test_read_sorted(/*ваша реализация здесь*/);
}
