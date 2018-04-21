 //
// Лабораторная работа №13. Динамические структуры данных. Списки
// test_tlist.cpp
//

#include <cassert>
#include <iostream>
#include <fstream>
#include "crtdynmem.h"
#include "test_tlist.h"
#include "tlist.h"

using namespace std;

tlist::datatype *create_test_data(const char* filename, size_t length)
{
    // создаём массив данных
    tlist::datatype *array = new tlist::datatype[length];
    for (size_t i=0; i < length; i++) {
        array[i] = rand();
    }

    // создаём файл данных
    ofstream file(filename);    
    size_t i=0;
    while (file.good() && i < length)
        file << ' ' << array[i++];
    file.close();

    // возвращаем указатель на данные для проверки
    return array;
}

bool is_equal_test(const tlist *begin, tlist::datatype *array, size_t length)
{    
    size_t i = 0;
    while (begin != nullptr && i < length) {
        // совпадение результата с исходными данными
        assert(begin->data == array[i]);
        begin = begin->next;
        i++;
    }
    // совпадение количества результатов с исходным количеством
    assert(i == length);
    return true;
}

array_list get_array_list(const tlist::datatype *array, size_t length)
{
    assert(array != nullptr);
    tlist *arr_list = new tlist[length];

    for (size_t i = 0; i < length; i++) {
        arr_list[i].data = array[i];
        arr_list[i].next = &arr_list[i+1];
    }
    arr_list[length - 1].next = nullptr;

    return arr_list;
}

bool test_get_list()
{
    size_t n = 10;
    const char *tmpname = "list.tmp";    
    // получаем тестовые данные
    tlist::datatype *array = create_test_data(tmpname, n);

    // перенаправляем ввод из файла
    ifstream file(tmpname);
    streambuf *cin_buffer = cin.rdbuf();
    cin.rdbuf(file.rdbuf());
    // читаем данные из файла
    tlist *list = get_list(n);
    // возвращаем всё как было
    cin.rdbuf(cin_buffer);
    file.close();

    // проверяем равенство прочитанного с исходным
    is_equal_test(list, array, n);
    
    // удаляем временные данные
    delete [] array;
    remove(tmpname);
    delete_list(list);
#ifdef _DEBUG
    std::cerr << "test get_list(length): OK" << std::endl;
#endif
    return true;
}

bool test_get_list_from_file()
{
    size_t n = 10;
    const char *tmpname = "list.tmp";    
    // получаем тестовые данные
    tlist::datatype *array = create_test_data(tmpname, n);

    // читаем данные из файла
    tlist *list = get_list(tmpname);

    // проверяем равенство прочитанного с исходным
    is_equal_test(list, array, n);
    
    // удаляем временные данные    
    delete [] array;
    remove(tmpname);
    delete_list(list);
#ifdef _DEBUG
    std::cerr << "test get_list(filename): OK" << std::endl;
#endif
    return true;
}

bool test_get_array_list()
{
    int n = 5;
    tlist::datatype *array = new tlist::datatype[n];
    for (int i=0; i<n; i++) {
        array[i] = rand();
    }
    array_list list = get_array_list(array, n);

    tlist *p =list;
    int i = 0;
    while (p != nullptr && i < n) {
        // проверяем структуру списка
        assert(p == &list[i]);
        // проверяем значения в списке
        assert(p->data == array[i]);
        i++;
        p=p->next;
    }
    // проверяем количество значений в списке
    assert(i == n);

    delete[] list;  // т.к. это - массив элементов tlist
    delete[] array;
#ifdef _DEBUG
    std::cerr << "test get_array_list: OK" << std::endl;
#endif
    return true;
}

bool test_find()
{
    int n = 6;
    tlist::datatype array[] = { 1,0,2,3,4,5 };
    array_list list = get_array_list(array, n);

    for (int i = 0; i < n; ++i) {
        tlist *p = find(list, array[i]);
        assert(p == &list[i]);
    }

    tlist *p = find(list, -1);
    assert(p == nullptr);

    delete[] list;
#ifdef _DEBUG
    std::cerr << "test find: OK" << std::endl;
#endif
    return true;

}

bool test_tlist_full()
{
    return test_get_list() &&
        test_get_list_from_file() &&
        test_get_array_list() &&
        test_find();
}
