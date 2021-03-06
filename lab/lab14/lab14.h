﻿//
// Лабораторная работа №14. Текстовые файлы. Обработка чисел
// lab14.h
//
#pragma once
#include <iostream>

typedef unsigned int uint;

// Функция чтения массива целых чисел из текстового файла с заданным именем.
// Ожидаемый формат файла:
// n
// a1  a2  a3  a4 ... an
// Входные параметры:
//      fname - имя файла.
// Выходные параметры:
//      a - указатель на начало массива;
//      n - количество элементов в массиве.
// Если в файле оказывается меньше элементов, чем указанно,
// генерируется исключение char*.
void read_from_text(const char* fname, int *&a, uint &n);

// Вывод массива в указанный поток вывода
// Параметры:
//     os – поток вывода,
//     a - указатель на начало массива;
//     n - количество элементов в массиве.
void print_to_stream(std::ostream &os, const int *a, uint n);

// Найти минимальное по модулю значение в файле.
// Ожидаемый формат файла:
// a1  a2  a3  a4 ...
// Входные параметры:
//      fname - имя файла.
// Возращаемое значение:
//      минимальное по модулю значение в файле.
// Если чисел в файле нет, генерирует исключение char*.
double find_abs_min(const char *fname);

// Вычислить минимум и максимум в каждой строке. Результат записать в файл.
// Ожидаемый формат входного файла:
// a11  a12  a13  a14 ...
// a21  a22  a23  ...
// ...
// Ожидаемый формат выходного файла:
// min1 max1
// min2 max2
// ...
// Входные параметры:
//     inputName - имя входного файла;
//     outputName - имя выходного файла.
// Результат:
//     Файл outputName сожердит строки с минимальным и 
//     значением соответствующей строки файла inputName.
// Если чисел в файле нет, генерирует исключение char*.
// Если строка не содержит чисел, в выходной файл записывается пустая строка.
void min_max_for_line(const char *inputName, const char* outputName);