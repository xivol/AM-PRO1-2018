//
// Лабораторная №8. С-строки. Библиотека cstring
// test_my_cstring.cpp
// 

#include <cassert>
#include <cstring>
#include <iostream>
#include "lab12.h"
#include "test_lab12.h"

using namespace std;

bool test_strcmp()
{
    cerr << "test_strcmp: ";

    char *str1 = "Hello,world!";
    assert(str_cmp(str1, str1) == 0);

    char *str2 = "Hello,world!";
    assert(str_cmp(str1, str2) == 0);

    str2 = "World, hello!";
    assert(str_cmp(str1, str2) < 0);
    assert(str_cmp(str2, str1) > 0);

    assert(str_cmp(str1, str2) - strcmp(str1, str2) == 0);

    cerr << "OK" << endl;
    return true;
}


bool test_word_count()
{
    cerr << "test_word_count: ";

    char *str = "";
    assert(word_count(str) == 0);
    str = "    ";
    assert(word_count(str) == 0);

    str = "Hello,world!";
    assert(word_count(str) == 1);

    str = "Hello, world!";
    assert(word_count(str) == 2);
    str = "Hello,   world!";
    assert(word_count(str) == 2);
    str = "Hello,   world!  ";
    assert(word_count(str) == 2);    
    str = "  Hello,   world!";
    assert(word_count(str) == 2);    
    str = "  Hello,   world!  ";
    assert(word_count(str) == 2);
    
    str = "  H e l l o ,   w o r l d !  ";
    assert(word_count(str) == 12);

    cerr << "OK" << endl;
    return true;
}

bool test_word_count_cyr(void *func)
{
    cerr << "test word_count_cyr: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    uint(*word_count_cyr)(const char*) = (uint(*)(const char*)) func;

    char *str = "";
    assert(word_count_cyr(str) == 0);
    str = "    ";
    assert(word_count_cyr(str) == 0);

    str = "Hello, world!";
    assert(word_count_cyr(str) == 2);
    str = " Hello, world! ";
    assert(word_count_cyr(str) == 2);
    str = "  Hello,   world!  ";
    assert(word_count_cyr(str) == 2);
    
    str = "Здравствуй, мир!";
    assert(word_count_cyr(str) == 2);
    str = "Здравствуй , мир!";
    assert(word_count_cyr(str) == 3);
    str = "  Здравствуй  ,  мир  !";
    assert(word_count_cyr(str) == 4);

    cerr << "OK" << endl;
    return true;
}

bool test_str_chr(void *func)
{
    cerr << "test str_chr: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    const char* (*str_chr)(const char *, char) = (const char* (*)(const char*, char)) func;

    char *str = "Hello, world!";
    char c = 'o';
    char *result = str + 4;
    assert(str_chr(str, c) == result);
    
    c = 'l';
    result = str + 2;
    assert(str_chr(str, c) == result);

    c = '#';
    result = nullptr;
    assert(str_chr(str, c) == result);

    cerr << "OK" << endl;
    return true;
}

bool test_str_str(void *func)
{
    cerr << "test str_str: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    const char* (*str_str)(const char *, const char *) = (const char* (*)(const char *, const char *)) func;

    char *str = "Hello, world!";
    assert(str_str(str, str) == str);

    char *word = "Hello";
    assert(str_str(str, word) == str);

    word = "world";
    assert(str_str(str, word) == str + 7);

    word = "zero";
    assert(str_str(str, word) == nullptr);

    cerr << "OK" << endl;
    return true;
}

bool test_remove_chr(void *func)
{
    cerr << "test remove_chr: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    void(*remove_chr)(char *, char) = (void (*)(char *, char )) func;

    char str[Max_Length] = " Hello, world! ";
    char c = 'c';
    char *result = " Hello, world! ";

    remove_chr(str, c);
    assert(str_cmp(str, result));

    c = ' ';
    result = "Hello,world!";
    remove_chr(str, c);
    assert(str_cmp(str, result));
    
    c = 'o';
    result = "Hell,wrld!";
    remove_chr(str, c);
    assert(str_cmp(str, result));

    c = 'l';
    result = "He,wrd!";
    remove_chr(str, c);
    assert(str_cmp(str, result));

    cerr << "OK" << endl;
    return true;
}

bool test_insert_str(void *func)
{
    cerr << "test insert_str: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    void (*insert_str)(char *, const char *, char ) = (void (*)(char *, const char *, char )) func;

    char str[Max_Length] = "Hello, world!";
    char c = 'c';
    char *str2 = " my";
    char *result = "Hello, world!";

    insert_str(str, str2, c);
    assert(str_cmp(str, result));

    c = ',';
    result = "Hello, my world!";
    insert_str(str, str2, c);
    assert(str_cmp(str, result));

    char max[Max_Length] = "\
_______________-_______________-_______________-_______________-\
_______________-_______________-_______________-_______________-\
_______________-_______________-_______________-_______________-\
_______________-_______________-_______________-_______________";

    try {
        insert_str(max, "_", '-');
        assert(false);
    }
    catch (char *error) {
        assert(true);
    }

    cerr << "OK" << endl;
    return true;
}
bool test_full_lab12()
{
#ifdef _DEBUG
    return test_strcmp() &&
        test_word_count() &&
        test_word_count_cyr(/*ваша реализация здесь*/) &&
        test_str_chr(/*ваша реализация здесь*/) &&
        test_str_str(/*ваша реализация здесь*/) &&
        test_remove_chr(/*ваша реализация здесь*/) &&
        test_insert_str(/*ваша реализация здесь*/);
#else
    return true;
#endif    
}