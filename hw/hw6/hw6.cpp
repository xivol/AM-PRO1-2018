//
// Домашняя работа №6. Динамические двумерные массивы
// hw6.cpp
//
#include <cassert>
#include <iomanip>
#include <iostream>
#include "crtdynmem.h"
#include "hw6.h"

using namespace std;

void read_new(double* &a, uint &rows, uint &cols)
{
    assert(a == nullptr);
    cout << "Введите количество строк " << endl;
    cin >> rows;
    cout << "Введите количество столбцов " <<  endl;
    cin >> cols;

    a = new double[rows*cols];

    cout << "Введите " << rows*cols << " элементов" << endl;
    for (uint i = 0; i < rows; ++i)
        for (uint j = 0; j < cols; ++j)
            cin >> a[i*cols + j];
}

void print(const double *a, const uint rows, const uint cols)
{
    assert(a != nullptr);

    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            // Форматированый вывод для выравнивания столбцов
            cout << setw(cout.precision() * 2 + 1);
            cout << a[i*cols + j] << " ";
        }
        cout << endl;
    }
}

void read_new(double** &m, uint &rows, uint &cols)
{
    assert(m == nullptr);
    cout << "Введите количество строк " << endl;
    cin >> rows;
    cout << "Введите количество столбцов " << endl;
    cin >> cols;

    // выделяем массив указателей
    m = new double*[rows];

    cout << "Введите " << rows*cols << " элементов" << endl;
    for (uint i = 0; i < rows; ++i) {
        // выделяем память под каждую строку отдельно
        m[i] = new double[cols];
        for (uint j = 0; j < cols; ++j)
            cin >> m[i][j];
    }
}

void delete_matrix(double **& m, const uint rows, const uint cols)
{
    assert(m != nullptr);

    // Освобождаем память занимаемую строками
    for (uint i = 0; i < rows; ++i)
        delete[] m[i];

    // Освобождаем память занимаемую массивом строк
    delete[] m;
    // Обнуляем указатель
    m = nullptr;
}

void print(double const*const* m, const uint rows, const uint cols)
{
    assert(m != nullptr);

    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            cout << setw(cout.precision() * 2 + 1);
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}


bool is_zeros(const double *a, const uint len, const double precision)
{
    for (uint i = 0; i < len; ++i) {
        if (fabs(a[i])>precision)
            return false;
    }
    return true;
}

bool has_zero_col(const double *a, const uint rows, const uint cols, const double precision)
{
    // Элемнта столбца находятся в разреженых ячейках памяти
    for (int j = 0; j < cols; ++j) 
    {
        bool is_zero_col = true;
        for (int i = 0; i < rows; ++i) 
        {
            // Проверка на наличие не нулевых элементов в столбце
            is_zero_col = is_zero_col && fabs( a[i*cols+j] ) <= precision;
        }
        if (is_zero_col)
            return true;
    }
    return false;
}

bool has_zero_col(double const* const* m, const uint rows, const uint cols, const double precision)
{
    // Элемнта столбца находятся в не связанных ячейках памяти
    for (int j = 0; j < cols; ++j) 
    {
        bool is_zero_col = true;
        for (int i = 0; i < rows; ++i) 
        {
            // Проверка на наличие не нулевых элементов в столбце
            is_zero_col = is_zero_col && fabs( m[i][j] ) <= precision;
        }
        if (is_zero_col)
            return true;
    }
    return false;
}

bool has_zero_row(const double * a, const uint rows, const uint cols, const double precision)
{
    // Строки матрицы располагаются в памяти линейно
    for (int i = 0; i < rows; ++i) {
        // каждая строка начинается с индекса 
        // кратного количеству элементов в строке
        if (is_zeros(a + (i * cols), cols, precision))
            return true;
    }
    return false;
}

bool has_zero_row( double const* const* m, const uint rows, const uint cols, const double precision)
{
    // Строки матрицы располагаются в памяти линейно
    for (int i = 0; i < rows; ++i) {
        // каждый элемент массива - указатель на строку
        if (is_zeros(m[i], cols, precision))
            return true;
    }
    return false;
}
