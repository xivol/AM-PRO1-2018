//
// Лабораторная №12. С-строки. Библиотека cstring
// lab12.cpp
// 

#include <cassert>
#include <cstring>
#include <cctype>
#include "lab12.h"

int str_cmp(const char *str1, const char *str2)
{
    assert(str1 != nullptr);
    assert(str2 != nullptr);
    // пока очередной символ *str1 != 0, *str2 != 0 и *str1 == *str2
    while (*str1 && *str2 && *str1 == *str2)
        str1++, str2++;
    // разность символов даёт необходимое значение
    return (*str1 - *str2 < 0) ? -1 : (*str1 - *str2 > 0);
}

uint word_count(const char *str)
{
    assert(str != nullptr);
    uint count = 0;
    while (*str) {
        // проверка на пробельные символы из cctype
        while ( isspace(*str)) str++;
        if (*str) count++;
        // проверка на не пробельные символы из cctype
        while ( isgraph(*str)) str++;
    }
    return count;
}