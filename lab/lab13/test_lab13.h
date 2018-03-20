//
// Лабораторная работа №13. Динамические строки
// test_lab13.h
//
#pragma once

// Тестирование функции:
// char * replace (const char *source, const char *from, const char* to);
// Проверяет 
//    обычную замену, 
//    повторяющиеся символы 
//    корректную работу при отсутствующей подстроке
bool test_replace_charptr();

// Тестирование функции:
// void replace ( string& source, const string &from, const string &to);
// Проверяет 
//    обычную замену, 
//    повторяющиеся символы 
//    корректную работу при отсутствующей подстроке
bool test_replace_string();

// Тестирование функции:
// void remove_chr(string &str, char c);
// Проверяет 
//     замену отсутствующего символа
//     замену одного символа
//     замену нескольких символов
bool test_remove_chr(void *func = nullptr);

// Тестирование функции:
// void insert_str(string &source, const string &new_str, char after_c);
// Проверяет 
//     вставку при отсутствии и наличии символа
bool test_insert_str(void *func = nullptr);

// Тестирование функции:
// uint word_count(const string &str);
// Проверяет 
//     количество слов в строке без слов
//     количество слов в строке с различным количеством пробелов
bool test_word_count(void *func = nullptr);

// Тестирование функции:
// void replace_even_words(string &source, const string &new_word);
// Проверяет 
//     замену в пустой строке
//     замену в строке с одним, двумя, четырьмя словами
//     замену на большее количество символов
bool test_replace_even_words(void *func = nullptr);

// Запуск подряд всех тестов из этой библиотеки
bool test_full_lab13();
