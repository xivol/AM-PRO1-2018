//
// Лабораторная №16. Двоичнвые файлы. Шаблонные функции
// test_lab16.h
//
#pragma once
#include <cassert>

// Тест шаблонной функции 
// uint number_of<T>(const char *filename)
bool test_number_of(const char *filename);

// Тест шаблонной функции 
// void swap(const char *filename, uint i, uint j)
template<typename T>
bool test_swap(const char *filename, void *func = nullptr)
{
    std::cerr << "test swap: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    void(*swap)(const char *, uint, uint) = (void(*)(const char*, uint, uint))func;

    assert(filename);
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    assert(file.is_open());

    uint i = 0, j = 1;    
    T result_j = read_binary<T>(file);
    T result_i = read_binary<T>(file);
    file.close();

    swap(filename, i, j);

    file.open(filename, std::ios::in | std::ios::binary);
    T prs_i = read_binary<T>(file);
    assert(prs_i == result_i);
    T prs_j = read_binary<T>(file);
    assert(prs_j == result_j);
    file.close();

    swap(filename, i, j);

    file.open(filename, std::ios::in | std::ios::binary);
    prs_i = read_binary<T>(file);
    assert(prs_i == result_j);
    prs_j = read_binary<T>(file);
    assert(prs_j == result_i);
    file.close();

    cerr << "OK" << endl;
    return true;
}

bool test_full_lab16();