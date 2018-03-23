//
// Ћабораторна€ работа є13. ƒинамические строки
// test_lab13.cpp
//
#include <cstring>
#include <cassert>
#include <iostream>
#include "crtdynmem.h"
#include "lab13.h"
#include "test_lab13.h"

using namespace std;

bool test_replace_charptr()
{
    cerr << "test replace char*: ";
    // проста€ замена
    {
        char *source = "eeny meeny miny moe";
        char *from = "eny";
        char *to = "arly";
        char *result = "early mearly miny moe";
        char *test = replace(source, from, to);

        assert(strcmp(result, test) == 0);

        delete[] test;
    }
    // замена повтор€ющихс€ символов
    {
        char *source = "xxXxxxXxxxxxX";
        char *from = "xx";
        char *to = "0";
        char *result = "0X0xX00xX";
        char *test = replace(source, from, to);

        assert(strcmp(result, test) == 0);

        delete[] test;
    }
    // отсутсвие подстроки
    {
        char *source = "eeny meeny miny moe";
        char *from = "xx";
        char *to = "0";
        char *result = nullptr;
        char *test = replace(source, from, to);

        assert(result == test);

        delete[] test;
    }
    // замена пустой строки
    {
        char *source = "eeny meeny miny moe";
        char *from = "";
        char *to = "0";
        try {
            replace(source, from, to);
            assert(false);
        }
        catch (...) {
            assert(true);
        }
    }

    cerr << "OK" << endl;
    return true;
}

bool test_replace_string()
{
    cerr << "test replace string: ";
    // обычна€ замена
    string source = "eeny meeny miny moe";
    string from = "eny";
    string to = "arly";
    string result = "early mearly miny moe";
    assert(result == replace(source, from, to));

    // замена повтор€ющихс€ символов
    source = "xxXxxxXxxxxxX";
    from = "xx";
    to = "0";
    result = "0X0xX00xX";
    assert(result == replace(source, from, to));

    // отсутсвующа€ подстрока
    source = "eeny meeny miny moe";
    from = "xx";
    to = "0";
    result = "eeny meeny miny moe";
    assert(result == replace(source, from, to));

    // замена пустой строки
    source = "eeny meeny miny moe";
    from = "";
    to = "0";

    try {
        replace(source, from, to);
        assert(false);
    }
    catch (char *error) {
        assert(true);
    }
    
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
    void(*remove_chr)(string &, char) = (void(*)(string &, char)) func;

    string str = " Hello, world! ";
    char c = 'c';
    string result = " Hello, world! ";

    remove_chr(str, c);
    assert(str == result);

    c = ' ';
    result = "Hello,world!";
    remove_chr(str, c);
    assert(str == result);

    c = 'o';
    result = "Hell,wrld!";
    remove_chr(str, c);
    assert(str == result);

    c = 'l';
    result = "He,wrd!";
    remove_chr(str, c);
    assert(str == result);

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
    void(*insert_str)(string &, const string &, char) = (void(*)(string &, const string &, char)) func;

    string str = "Hello, world!";
    char c = 'c';
    string str2 = " my";
    string result = "Hello, world!";

    insert_str(str, str2, c);
    assert(str == result);

    c = ',';
    result = "Hello, my world!";
    insert_str(str, str2, c);
    assert(str == result);

    cerr << "OK" << endl;
    return true;
}

bool test_word_count(void *func)
{
    cerr << "test word_count: ";

    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    uint(*word_count)(const string &) = (uint(*)(const string &)) func;

    string str = "";
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

bool test_replace_even_words(void *func)
{
    cerr << "test remove_even_words: ";
    if (func == nullptr) {
        cerr << "NOT IMPLEMENTED" << endl;
        return true;
    }
    void(*replace_even_words)(string &, const string &) = (void(*)(string &, const string &))func;

    string str = "Hello,world!";
    string new_word = "worry!";
    string result = "Hello,world!";

    replace_even_words(str, new_word);
    assert(str == result);

    str     = "Hello, world!";
    result  = "Hello, worry!";
    replace_even_words(str, new_word);
    assert(str == result);

    str     = "  Hello,   world! ";
    result  = "  Hello,   worry! ";
    replace_even_words(str, new_word);
    assert(str == result);

    str    = "Dont't worry! Be happy!";
    result = "Dont't worry! Be worry!";
    replace_even_words(str, new_word);
    assert(str == result);

    str    = " Dont't worry ! Be happy !  ";
    result = " Dont't worry! ! worry! happy worry!  ";
    replace_even_words(str, new_word);
    assert(str == result);
    cerr << "OK" << endl;
    return true;
}

bool test_full_lab13()
{
#ifdef _DEBUG
    return test_replace_charptr() &&
        test_replace_string() &&
        test_remove_chr(/*ваша реализаци€ здесь*/) &&
        test_insert_str(/*ваша реализаци€ здесь*/) &&
        test_word_count(/*ваша реализаци€ здесь*/) &&
        test_replace_even_words(/*ваша реализаци€ здесь*/);

#else
    return true;
#endif    
}
