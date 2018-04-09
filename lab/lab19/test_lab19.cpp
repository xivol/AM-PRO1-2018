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
bool test_full_lab19()
{
    return  test_read_list() &&
		test_insert_middle();
}
