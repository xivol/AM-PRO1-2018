//
// Лабораторная работа №14. Текстовые файлы. Обработка чисел
// test_lab14.cpp
//
#include <cstring>
#include <cassert>
#include <iostream>
#include <fstream>
#include "lab14.h"
#include "test_lab14.h"

using namespace std;

bool is_equal_text(const char *filename1, const char *filename2)
{
    assert(filename1);
    assert(filename2);

    ifstream f1(filename1);
    if (!f1.is_open()) {
        char error[128] = "Couldn't open file ";
        strcat_s(error, 128, filename1);
        throw error;
    }

    ifstream f2(filename2);
    if (!f2.is_open()) {
        char error[128] = "Couldn't open file ";
        strcat_s(error, 128, filename2);
        throw error;
    }

    while (!f1.eof() && !f2.eof())
        if (f1.get() != f2.get())
            return false;

    if (!f1.eof() || !f2.eof())
        return false;

    f1.close();
    f2.close();
    return true;
}
bool test_is_equal_text(const char *filename1, const char *filename2)
{
    cerr << "test is_equal_text : ";
    assert(filename1);
    assert(filename2);      

    assert(is_equal_text(filename1, filename1));

    assert(is_equal_text(filename2, filename2));

    assert(!is_equal_text(filename2, filename1));

    assert(!is_equal_text(filename1, filename2));

    cerr << "OK" << endl;
    return true;
}

bool test_find_abs_min(void *func)
{
    cerr << "test find_abs_min: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    double(*find_abs_min)(const char *) = (double(*)(const char *)) func;

    const char *test_fn = "test_file.txt";

    // пустой файл
    ofstream fout(test_fn);
    assert(fout.is_open()); 
    fout.close();

    try {
        find_abs_min(test_fn);
        assert(false);
    } 
    catch (const char * error) {
        assert(true);
    }

    // файл чисел
    double d[10] = { 1, -2, 3, -4, 5, -6, 7, -8, 9, -10 };
    fout.open(test_fn);
    assert(fout.is_open());
    for (int i = 0; i < sizeof(d) / sizeof(*d); ++i)
        fout << d[i] << " ";
    fout.close();
    
    double result = 1;
    assert(find_abs_min(test_fn) == result);

    remove(test_fn);

    cerr << "OK" << endl;
    return true;
}

bool test_min_max_for_line(void *func)
{
    cerr << "test min_max_for_line: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    void(*min_max_for_line)(const char *, const char*) = (void(*)(const char *, const char*)) func;

    const char *input_fn = "test_in_file.txt";
    const char *output_fn = "test_out_file.txt";
    
    // пустой файл
    ofstream fout(input_fn);
    assert(fout.is_open());
    fout.close();

    try {
        min_max_for_line(input_fn, output_fn);
        assert(false);
    }
    catch (const char * error) {
        assert(true);
    }

    remove(input_fn);
    remove(output_fn);

    // тестовый файл
    input_fn = "test_min_max_for_line.txt"; 
    const char *result_fn = "result_min_max_for_line.txt";
    
    min_max_for_line(input_fn, output_fn);
    assert(is_equal_text(output_fn, result_fn));
    
    remove(output_fn);

    cerr << "OK" << endl;
    return true;
}


bool test_full_lab14()
{
#ifdef _DEBUG
    return test_is_equal_text("test_min_max_for_line.txt", "result_min_max_for_line.txt") &&
        test_find_abs_min(/*ваша реализация здесь*/) &&
        test_min_max_for_line(/*ваша реализация здесь*/);

#else
    return true;
#endif    
}
