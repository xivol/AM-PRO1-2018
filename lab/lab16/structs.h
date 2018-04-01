//
// Лабораторная №16. Структуры. Двоичнвые файлы.
// structs.h
//
#pragma once
#include <cassert>
#include <fstream>

typedef unsigned int uint;
// Точка на плоскости 
// (x,y)
struct point 
{
    double x, y;    
};

// Календарная дата
// day. month. year
struct date
{
    uint day, month, year;
};

// Данные о человеке:
//     fullname - ФИО;
//     birthday - дата рождения;
//     gender - пол.
struct person
{
    char fullname[128];
    date birthday;
    char gender;
};

// Шаблонная функция чтения из файла данных в двоичной форме.
// Входные параметры:
//     fin - поток чтения из файла (должен быть открыт c ios::binary).
// Возвращает очередной элемент типа T, считаный из файла.
// Если чтение не удалось, fin.good() == false.
template <typename T>
T read_binary(std::ifstream &fin)
{
    assert(fin);
    T t;
    fin.read(reinterpret_cast<char*> (&t), sizeof(t));
    return t;
}

// Шаблонная функция записи в файл данных в двоичной форме.
// Входные параметры:
//     fout - поток записи в файл (должен быть открыт c ios::binary);
//     t - ссылка на записываемый элемент.
// Если запись не удалась, fout.good() == false.
template <typename T>
void write_binary(std::ofstream &fout, T &t)
{
    assert(fout);
    fout.write(reinterpret_cast<char*> (&t), sizeof(t));
}

// Шаблонная функция подсчёта количества элементов заданного типа в файле.
// Входные параметры:
//     filename - имя файла данных.
// Возвращает количество элементов типа Т в файле.
// Если файл не удалось открыть, выбрасывает исключение char*.
template <typename T>
uint number_of(const char *filename)
{
    assert(filename);
    
    std::ifstream fin(filename, std::ios::binary);
    if (!fin.is_open())
        throw "Невозможно открыть файл!";

    uint count = 0;
    while (!fin.eof()) {
        // считать очередной элемент из файла
        read_binary<T>(fin);
        if (fin)   // если чтение прошло успешно
            count++;
    }

    fin.close();
    return count;
}

