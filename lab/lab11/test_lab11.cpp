//
// Лабораторная работа №11. Динамические массивы.
// test_lab11.cpp
//
#include <cassert>
#include <iostream>
#include "crtdynmem.h"
#include "lab11.h"
#include "test_lab11.h"

using namespace std;

double *test_array(const std::initializer_list<double> &list, uint &size)
{
    size = list.size();
   
    double *t = new double[size];
    uint k = 0;

    for (auto i = list.begin(); i != list.end(); ++i)
            t[k++] = *i;
    return t;
}

double **test_sparce_matrix(const std::initializer_list<std::initializer_list<double>> &m, uint &rows, uint &cols)
{
    rows = m.size();
    cols = m.begin()->size();

    double **a = new double*[rows];
    int ik = 0;

    for (auto i = m.begin(); i != m.end(); ++i) {
        a[ik] = new double[cols];
        int jk = 0;
        for (auto j = i->begin(); j != i->end(); ++j)
            a[ik][jk++] = *j;
        ik += 1;
    }
    return a;
}

bool test_min_positive()
{
    cerr << "test min_positive: ";

    uint size;
    double *a = test_array({ 1,2,3,4,5,6 }, size);
    double result = 1;
    assert(fabs(min_positive(a, size) - result) < precision);
    delete[] a;

    a = test_array({ -1,0,0.1,0.2,0.3,1 }, size);
    result = 0.1;
    assert(fabs(min_positive(a, size) - result) < precision);
    delete[] a;

    a = test_array({ -1, -0.1, 0 }, size);
    try 
    {
        result = min_positive(a, size);  // должно вызвать ошибку
        assert(false);  // не должно дойти до этой проверки
    }
    catch (char *c) 
    {
        assert(true);  // получили ошибку
    }
    delete[] a;

    cerr << "OK" << endl;
    return true;
}

bool test_min_positive_matrix()
{
    cerr << "test min_positive_matrix: ";

    uint rows, cols;
    double **m = test_sparce_matrix({ { 1,2 },{ 3,4 },{ 5,6 } }, rows, cols);
    double result = 1;
    assert(fabs(min_positive(m, rows, cols) - result) < precision);
    delete_matrix(m, rows, cols);

    m = test_sparce_matrix({ { -1,2 },{ -3,-4 },{ 0.5,-6 } }, rows, cols);
    result = 0.5;
    assert(fabs(min_positive(m, rows, cols) - result) < precision);
    delete_matrix(m, rows, cols);

    m = test_sparce_matrix({ { -1,-2 },{ -3,-4 },{ -5,-6 } }, rows, cols);
    try 
    {
        result = min_positive(m, rows, cols);
        assert(false);
    }
    catch (char *c) 
    {
        assert(true);
    }
    delete_matrix(m, rows, cols);

    cerr << "OK" << endl;
    return true;
}

bool test_major_div_minor(void *func)
{
    cerr << "test major_div_minor: ";
    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    double(*major_div_minor)(double const* const*, const uint, const uint) = (double(*)(double const* const* a, const uint rows, const uint cols))func;

    uint rows, cols;
    double **m = test_sparce_matrix({ { 1,2,3 },{ 4,5,6 },{ 7,8,9 } }, rows, cols);
    double result = 15.0 / 15.0;
    assert(fabs(major_div_minor(m, rows, cols) - result) < precision);
    delete_matrix(m, rows, cols);

    m = test_sparce_matrix({ { 0,2,3 },{ 4,0,6 },{ 7,8,0 } }, rows, cols);
    result = 0.0 / 10.0;
    assert(fabs(major_div_minor(m, rows, cols) - result) < precision);
    delete_matrix(m, rows, cols);

    m = test_sparce_matrix({ { 1,2,1 },{ 4,2,6 },{ -3,8,9 } }, rows, cols);
    try {
        result = major_div_minor(m, rows, cols);
        assert(false);
    }
    catch (char *c) { // деление на ноль
        assert(true);
    }
    delete_matrix(m, rows, cols);
    cerr << "OK" << endl;
    return true;
}

bool test_append_col(void *func)
{
    cerr << "test append_col: ";
    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    void (*append_col)(double** &, const uint, uint &, aggregate) = (void (*)(double** &, const uint, uint &, aggregate))func;

    uint rows, cols;
    double **m = test_sparce_matrix({ { 1,2,3 },{ 4,5,6 },{ 7,8,9 } }, rows, cols);
    uint result_rows, result_cols;
    double **result = test_sparce_matrix({ { 1,2,3,1 },{ 4,5,6,4 },{ 7,8,9,7 } }, result_rows, result_cols);

    append_col(m, rows, cols, min_positive);
    assert(cols == result_cols && rows == result_rows);
    assert(is_equal_matrix(m,result,rows,cols));

    delete_matrix(m, rows, cols);
    delete_matrix(result, result_rows, result_cols);

    cerr << "OK" << endl;
    return true;
}

bool test_has_zero(const double *a, const uint size)
{
    for (uint i = 0; i < size; ++i)
        if (fabs(a[i]) < precision)
            return true;
    return false;
}

bool test_remove_rows(void *func)
{
    cerr << "test remove_rows: ";
    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    void(*remove_rows)(double** &a, uint &rows, const uint cols, condition cond) = (void(*)(double** &, uint &, const uint, condition))func;

    uint rows, cols;
    double **m = test_sparce_matrix({ { 1,2,3 },{ 4,5,6 },{ 7,8,9 } }, rows, cols);
    uint result_rows, result_cols;
    double **result = test_sparce_matrix({ { 1,2,3 },{ 4,5,6 },{ 7,8,9 } }, result_rows, result_cols);
    
    remove_rows(m, rows, cols, test_has_zero);
    assert(cols == result_cols && rows == result_rows);
    assert(is_equal_matrix(m, result, rows, cols));

    delete_matrix(m, rows, cols);
    delete_matrix(result, result_rows, result_cols);
    
    m = test_sparce_matrix({ { 1,0,3 },{ 4,5,6 },{ 7,0,9 } }, rows, cols);
    result = test_sparce_matrix({ { 4,5,6 } }, result_rows, result_cols);

    remove_rows(m, rows, cols, test_has_zero);
    assert(cols == result_cols && rows == result_rows);
    assert(is_equal_matrix(m, result, rows, cols));

    delete_matrix(m, rows, cols);
    delete_matrix(result, result_rows, result_cols);

    cerr << "OK" << endl;
    return true;
}

bool test_lab11_full()
{
#ifdef _DEBUG
    return test_min_positive() &&
        test_min_positive_matrix() &&
        test_major_div_minor(/*ваша реализация здесь*/) &&
        test_append_col(/*ваша реализация здесь*/) &&
        test_remove_rows(/*ваша реализация здесь*/);
#else
    return true;
#endif    
}
