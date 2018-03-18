//
// Лабораторная №12. С-строки. Библиотека cstring
// lab12.h
// 
#pragma once

typedef unsigned int uint;
// Максимальная длина статической строки
const uint Max_Length = 256;

// Функция сравнения строк.
// Входные параметры:
//     str1 - начало первой строки;
//     str2 - начало второй строки.
// Результат:
//      0 - строки равны;
//     >0 - первый различный символ строки 1 > строки 2;
//     <0 - первый различный символ строки 1 < строки 2.
int str_cmp(const char *str1, const char *str2);

// Функция вычисления количества слов в строке.
// Входные параметры:
//     str - начало строки.
// Результат:
//     количество последовательностей не пробельных символов, разделенный пробелами.
uint word_count(const char* str);

uint word_count_cyr(const char* str);

const char* str_chr(const char *str, char c);

void remove_chr(char *str, char c);

const char* str_str(const char *str, const char *word);

void insert_str(char *str1, const char *str2, char c);