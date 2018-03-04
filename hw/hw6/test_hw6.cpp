//
// Домашняя работа №6. Динамические двумерные массивы
// test_hw6.cpp
//
#include <iostream>
#include "crtdynmem.h"
#include "test_hw6.h"

using namespace std;

double *test_compact_matrix(const std::initializer_list<std::initializer_list<double>> &m, uint &rows, uint &cols)
{
    rows = m.size();
    cols = m.begin()->size();
    int k = 0;
    
    double *a = new double[rows*cols];

    for (auto i = m.begin(); i != m.end(); ++i)
        for (auto j = i->begin(); j != i->end(); ++j)
            a[k++] = *j;
    return a;
}

double **test_sparce_matrix(const std::initializer_list<std::initializer_list<double>> &m, uint &rows, uint &cols)
{
    rows = m.size();
    cols = m.begin()->size();
    int ik = 0;

    double **a = new double*[rows];

    for (auto i = m.begin(); i != m.end(); ++i) 
    {
        a[ik] = new double[cols];
        int jk = 0;
        for (auto j = i->begin(); j != i->end(); ++j)
            a[ik][jk++] = *j;
        ik += 1;
    }
    return a;
}

bool test_is_equal_matrix()
{
    cerr << "test is_equal_matrix: ";

    uint rows1, cols1;
    double **m1 = test_sparce_matrix({ {1,2},{3,4},{5,6} }, rows1, cols1);
    assert(is_equal_matrix(m1, m1, rows1, cols1));

    uint rows2, cols2;
    double **m2 = test_sparce_matrix({ { 1,2 },{ 3,4 },{ 5,6 } }, rows2, cols2);

    assert(is_equal_matrix(m1, m2, rows1, cols1));
    assert(is_equal_matrix(m2, m1, rows2, cols2));

    delete_matrix(m2, rows2, cols2);

    m2 = test_sparce_matrix({ { 0,0 },{ 0,4 },{ 5,0 } }, rows2, cols2);
    assert(!is_equal_matrix(m1, m2, rows2, cols2));

    delete_matrix(m1, rows1, cols1);
    delete_matrix(m2, rows2, cols2);

    cerr << "OK" << endl;
    return true;
}

bool test_is_zeros()
{
    cerr << "test is_zeros: ";

    const uint len = 10;
    double a[len] = { 10, 1, 2, 3, 4, 5, 6,7, 8, 9 };
    assert(!is_zeros(a, len));

    a[0] = 0;
    assert(!is_zeros(a, len));

    double b[len] = {};
    assert(is_zeros(b, len));

    b[0] = 0.1;
    assert(is_zeros(b, len, 0.1));

    cerr << "OK" << endl;
    return true;
}

bool test_has_zero_row_compact()
{
    cerr << "test has_zero_row compact: ";

    uint rows = 3, cols = 3;
    double a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    assert(!has_zero_row(a, rows, cols));

    a[0] = a[1] = a[2] = 0;
    assert(has_zero_row(a, rows, cols));

    a[1] = 1;
    assert(!has_zero_row(a, rows, cols));

    cerr << "OK" << endl;
    return true;
}

bool test_has_zero_row_sparce()
{
    cerr << "test has_zero_row sparce: ";

    uint rows,cols;
    double **a = test_sparce_matrix({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} }, rows,cols);

    assert(!has_zero_row(a, rows, cols));

    a[0][0] = a[0][1] = a[0][2] = 0;
    assert(has_zero_row(a, rows, cols));

    a[0][1] = 1;
    assert(!has_zero_row(a, rows, cols));

    delete_matrix(a, rows, cols);
    cerr << "OK" << endl;
    return true;
}

bool test_has_zero_col_compact()
{
    cerr << "test has_zero_col compact: ";

    uint rows = 3, cols = 3;
    double a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    assert(!has_zero_col(a, rows, cols));

    a[0] = a[3] = a[6] = 0;
    assert(has_zero_col(a, rows, cols));

    a[3] = 1;
    assert(!has_zero_col(a, rows, cols));

    cerr << "OK" << endl;
    return true;
}

bool test_has_zero_col_sparce()
{
    cerr << "test has_zero_col sparce: ";

    uint rows, cols;
    double **a = test_sparce_matrix({ { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } }, rows, cols);

    assert(!has_zero_col(a, rows, cols));

    a[0][0] = a[1][0] = a[2][0] = 0;
    assert(has_zero_col(a, rows, cols));

    a[0][0] = 1;
    assert(!has_zero_col(a, rows, cols));

    delete_matrix(a, rows, cols);
    cerr << "OK" << endl;
    return true;
}

bool test_full_hw6()
{
#ifdef _DEBUG
    return test_is_equal_matrix() &&
        test_is_zeros() &&
        test_has_zero_row_sparce() &&
        test_has_zero_row_compact() &&
        test_has_zero_col_sparce() &&
        test_has_zero_col_compact();
#elif
    return true;
#endif
}