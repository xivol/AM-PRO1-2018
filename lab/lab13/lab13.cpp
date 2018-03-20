//
// Лабораторная работа №13. Динамические строки
// lab13.cpp
//
#define _CRT_SECURE_NO_WARNINGS
#include <cassert>
#include <cstring>
#include "crtdynmem.h"
#include "lab13.h"

char *replace(const char *source, const char *from, const char* to)
{
    assert(source);
    assert(from);
    assert(to);

    if (*from == 0)
        throw "Нельзя заменить пустую строку.";
   
    // найдем первое вхождение from
    const char *next = strstr(source, from);
    if (next == nullptr) return nullptr;

    // посчитаем длины заменяемых подстрок
    uint lenFrom = strlen(from);
    uint lenTo = strlen(to);

    // инициализируем результат
    char *result = new char[1];
    result[0] = 0;    
    do {
        // выделяем память под новый результат:
        // весь наклпленный результат + количество символов до вхождения + длина замены + 1
        char *tmp = new char[strlen(result) + (next - source) + lenTo + 1];

        // скопируем всесь предыдущий результат
        strcpy(tmp, result);

        // допишем к новой строке все символы до замены и саму замену
        strcat(strncat(tmp, source, next - source), to);

        // удалим старый результат
        delete[] result;
        result = tmp;

        // передвинем указатель за первое вхождение строки from
        source = next + lenFrom;
    }
    while (next = strstr(source, from)); // продолжим со следующего вхождения 

    // скопируем в результат символы после последнего вхождения
    char *tmp = new char[strlen(result) + strlen(source) + 1];
    strcpy(tmp, result);
    strcat(tmp, source);
    delete[]result;
    result = tmp;

    return result;
}

string replace(const string &source, const string &from, const string &to)
{
    if (from.length() == 0)
        throw "Нельзя заменить пустую строку.";
    
    string result = source;

    // найдём первое вхождение
    uint next = result.find(from, 0);     
    // пока есть вхождения
    while (next != string::npos) 
    {        
        // заменим заданное число символов строки на другую строку
        result.replace(next, from.length(), to);
        // продолжим со следующего вхождения
        next = result.find(from, next + to.length());
    }
    return result;
}
