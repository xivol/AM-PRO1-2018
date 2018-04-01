//
// Лабораторная №16. Двоичнвые файлы. Шаблонные функции
// lab16.cpp
//
#include <iostream>
#include <string>
#include <sstream>
#include "lab16.h"

using namespace std;

person read_person(const std::string &s)
{
    person prs;
    // поток данных из строки
    istringstream sin(s);

    // считывание до первого символа табуляции
    sin.getline(prs.fullname, sizeof(prs.fullname), '\t');

    sin >> prs.birthday.day >> prs.birthday.month >> prs.birthday.year;

    // если были ошибки чтения
    if (!sin.eof() || strlen(prs.fullname) == 0)
        throw "Неверный формат входной строки";

    return prs;
}