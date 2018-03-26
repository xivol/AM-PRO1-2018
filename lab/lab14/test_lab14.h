//
// Лабораторная работа №14. Текстовые файлы. Обработка чисел
// test_lab14.h
//
#pragma once

// Функция сравнения двух текстовых файлов 
// на равенство посимвольно.
// Входные данные:
//     filename1 - имя первого файла входных данных;
//     filename2 - имя второго файла входных данных.
// Возвращает true, если файлы имют одинаковое содержимое.
// Выбрасывает исключение char*, если файл не может быть открыт
bool is_equal_text(const char *filename1, const char *filename2);

// Тестирования работы функции
// bool is_equal_file(const char*filename1, const char *filename2)
// Входные параметры:
//     filename1 - имя файла входных данных;
//     filename2 - имя другого файла входных данных.
// Проверка на равенство и не равество двух файлов.
bool test_is_equal_text(const char *filename1, const char *filename2);

// Тестирование функции:
// double find_abs_min(const char *fname)
// Проверка для пустого и не пустого файлов.
bool test_find_abs_min(void *func = nullptr);

// Тестирование функции:
// void min_max_for_line(const char *inputName, const char* outputName)
// Проверка для пустого и не пустого файлов.
bool test_min_max_for_line(void *func = nullptr);

// Запуск подряд всех тестов из этой библиотеки
bool test_full_lab14();
