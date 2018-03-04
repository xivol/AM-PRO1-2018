#include <iostream>
#include "test_lab10.h"

using namespace std;

bool test_is_equal_matrix()
{
    cerr << "test is_equal_matrix: ";

    matrix m1 = {};
    uint rows = max_ROWS, cols = max_COLS;
    assert(is_equal_matrix(m1, m1, rows, cols));

    matrix m2 = {};
    assert(is_equal_matrix(m1, m2, rows, cols));

    for (uint i = 0; i < max_COLS && i < max_ROWS; ++i)
        m1[i][i] = 0.1;
    assert(!is_equal_matrix(m1, m2, rows, cols));

    assert(is_equal_matrix(m1, m2, rows, cols, 0.1));
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

bool test_has_zero_row()
{
    cerr << "test has_zero_row: ";
    
    matrix m = {};
    assert(has_zero_row(m, max_ROWS, max_COLS));
    
    for (uint i = 0; i < max_COLS && i < max_ROWS; ++i)
        m[i][i] = 0.1;
    assert(has_zero_col(m, max_ROWS, max_COLS, 0.1));

    assert(!has_zero_row(m, max_ROWS, max_COLS));

    m[0][0] = 0;
    assert(has_zero_row(m, max_ROWS, max_COLS));

    cerr << "OK" << endl;
    return true;
}

bool test_has_zero_col()
{
    cerr << "test has_zero_col: ";

    matrix m = {};
    assert(has_zero_col(m, max_ROWS, max_COLS));

    for (uint i = 0; i < max_COLS && i < max_ROWS; ++i)
        m[i][i] = 0.1;
    assert(has_zero_col(m, max_ROWS, max_COLS, 0.1));

    assert(!has_zero_col(m, max_ROWS, max_COLS, 0.01));
    
    m[0][0] = 0;
    assert(has_zero_row(m, max_ROWS, max_COLS));

    cerr << "OK" << endl;
    return true;
}

bool test_remove_zero_cols(void *func)
{
    cerr << "test remove_zero_cols: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    void (*remove_zero_cols)(matrix m, const uint rows, uint &cols, const double precision ) = (void (*)(matrix m, const uint rows, uint &cols, const double precision))func;

    matrix m = {};
    uint cols = max_COLS;
    remove_zero_cols(m, max_ROWS, cols, 0);
    assert(cols == 0);

    m[0][0] = 0.1;
    cols = 2;
    remove_zero_cols(m, max_ROWS, cols, 0);
    assert(cols == 1 && m[0][0] == 0.1);

    cols = 2;
    remove_zero_cols(m, max_ROWS, cols, 0.1);
    assert(cols == 0);

    matrix m2 = { {1,2,3},{4,5,6},{7,8,9} };
    uint rows = 3;
    cols = 3;

    remove_zero_cols(m2, rows, cols, 0);
    assert(cols == 3);

    m[0][1] = 0; m[1][1] = 0; m[2][1] = 0;
    matrix result = { {1,3},{4,6},{7,9} };
    
    remove_zero_cols(m2, rows, cols, 0);
    assert(cols == 2);
    assert(is_equal_matrix(m2, result, rows, cols));

    cerr << "OK" << endl;
    return true;
}

bool test_insert_row(void *func)
{
    cerr << "test insert_row: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    void (*insert_row)(matrix m, uint &rows, const uint cols, const double *row, const uint index) = (void(*)(matrix m, uint &rows, const uint cols, const double *row, const uint index))func;

    matrix m = { {1,2,3},{4,5,6},{7,8,9} };
    uint cols = 3, rows = 3;
    double row[3] = { 0,0,0 };
    uint index = 2;

    matrix result = { { 1,2,3 },{ 4,5,6 },{ 0,0,0 },{ 7,8,9 } };
    uint result_rows = 4;
    insert_row(m, rows, cols, row, index);
    assert(rows == result_rows);
    assert(is_equal_matrix(m, result, rows, cols));
    
    index = rows + 1;
    matrix result2 = { { 1,2,3 },{ 4,5,6 },{ 0,0,0 },{ 7,8,9 },{ 0,0,0 } };
    result_rows = 5;

    insert_row(m, rows, cols, row, index);
    assert(rows == result_rows);
    assert(is_equal_matrix(m, result2, rows, cols));

    cerr << "OK" << endl;
    return true;
}

bool test_transpose(void *func)
{
    cerr << "test transpose: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }

    void(*transpose)(matrix m, uint &rows, uint &cols) = (void(*)(matrix m, uint &rows, uint &cols)) func;

    matrix m1 = { {1,2,3,4} }, result1 = { {1},{2},{3},{4} };
    uint rows = 1, cols = 4;
    
    transpose(m1, rows, cols);
    assert(rows == 4 && cols == 1);
    assert(is_equal_matrix(m1, result1, rows, cols));
    
    matrix result2 = { { 1,2,3,4 } };    
    rows = 4, cols = 1;

    transpose(m1, rows, cols);
    assert(rows == 1 && cols == 4);
    assert(is_equal_matrix(m1, result2, rows, cols));

    matrix m2 = { { 1,2,3 }, { 4,5,6} }, result3 = { { 1,4 },{ 2,5 },{ 3,6 } };
    rows = 2, cols = 3;

    transpose(m2, rows, cols);
    assert(rows == 3 && cols == 2);
    assert(is_equal_matrix(m2, result3, rows, cols));

    matrix result4 = { { 1,2,3 },{ 4,5,6 } };
    rows = 3, cols = 2;

    transpose(m2, rows, cols);
    assert(rows == 2 && cols == 3);
    assert(is_equal_matrix(m2, result4, rows, cols));

    cerr << "OK" << endl;
    return true;
}

bool test_multiply(void *func)
{
    cerr << "test multiply: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }

    void (*multiply)(const matrix a, const uint a_rows, const uint a_cols, const matrix b, const uint b_rows, const uint b_cols, matrix c) = (void(*)(const matrix a, const uint a_rows, const uint a_cols, const matrix b, const uint b_rows, const uint b_cols, matrix c)) func;

    matrix a = { {1, 2, 3}, {4,5,6},{7,8,9} };
    uint a_rows = 3, a_cols = 3;
    matrix b = { {1,0,0},{0,1,0},{0,0,1} };
    uint b_rows = 3, b_cols = 3;
    matrix c;

    multiply(a, a_rows, a_cols, b, b_rows, b_cols, c);
    assert(is_equal_matrix(c, a, a_rows, a_cols));

    matrix result = { {1,2,0},{4,5,0},{7,8,0} };

    multiply(a, a_rows, 2, b, 2, b_cols, c);
    assert(is_equal_matrix(c, result, a_cols, b_rows));

    matrix z = {};
    b[0][0] = 0, b[1][1] = 0, b[2][2] = 0;
    
    multiply(a, a_rows, a_cols, b, b_rows, b_cols, c);
    assert(is_equal_matrix(c, z, a_rows, b_cols));

    cerr << "OK" << endl;
    return true;
}

bool test_full_lab10()
{
#ifdef _DEBUG
    return test_is_equal_matrix() &&
        test_is_zeros() &&
        test_has_zero_col() &&
        test_has_zero_row() &&
        test_remove_zero_cols(/*ваша реализация здесь*/) &&
        test_insert_row(/*ваша реализация здесь*/) &&
        test_transpose(/*ваша реализация здесь*/) &&
        test_multiply(/*ваша реализация здесь*/);
#elif
    return true;
#endif
}
