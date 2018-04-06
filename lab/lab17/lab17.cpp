//
// Лабораторная работа №17. Структуры в динамической памяти
// structs_dynamic.cpp
//
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include "structs.h"
#include "lab17.h"


using namespace std;

uint credits_sum(const student &stud)
{
    uint sum = 0;
    for (int i = 0; i < student::assign_count; ++i) {
        sum += stud.credits[i];
    }
    return sum;
}

student read_student(const string &s)
{
    student stud;
    // поток данных из строки
    istringstream sin(s);

    // считывание до первого символа табуляции
    sin.getline(stud.fullname, student::name_size, '\t');

    sin >> stud.course >> stud.group;
    
    for (uint i = 0; i < student::assign_count; ++i) {
        sin >> stud.credits[i];
    }
    // если были ошибки чтения
    if (!sin.eof() || strlen(stud.fullname) == 0)
        throw "Неверный формат входной строки";

    return stud;
}

void binary_from_text(const char *filename)
{
    assert(filename != nullptr);
    ifstream fin(filename);
    if (!fin.is_open())
        throw "Невозможно открыть файл";
    
    // создаём имя нового файла
    string dataname = filename;
    uint dot = dataname.find_last_of('.');
    dataname.replace(dot, dataname.length() - dot, ".dat");

    ofstream fout(dataname, ios::binary);
    if (!fout.is_open())
        throw "Невозможно открыть файл";

    while (!fin.eof()) {
        string student_str;
        getline(fin, student_str);

        if (student_str.length() != 0) {
            student stud = read_student(student_str);
            write_binary(fout, stud);
        }
    }

    fin.close();
    fout.close();
}

void print_student(const student &stud)
{
    cout << stud.fullname << '\t';
    cout << stud.course << '.' << stud.group << '\t';
    cout << "[ " << stud.credits[0];
    for (uint i = 1; i < student::assign_count; ++i) {
        cout << ", " << stud.credits[i];
    }
    cout << " ]" << endl;
}