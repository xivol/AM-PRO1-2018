//
// Лабораторная №12. С-строки. Библиотека cstring
// main.cpp
// 
#include <iostream>
#include "lab12.h"
#include "test_lab12.h"

using namespace std;

int main()
{
    // Установка кодировки выходных данных
    // Set Locale – установка локали окружения
    
    // по умолчанию – ANSI
    cout << setlocale(LC_ALL, nullptr) << endl;

    // при ошибке возвращает 0
    if (!setlocale(LC_ALL, "Hello_world"))
        cout << "Unidentified locale" << endl;

    // название локали можно передавать по разному
    cout << setlocale(LC_ALL, "Russian_Russia.1251") << endl;
    cout << setlocale(LC_ALL, "Russian") << endl;
    cout << setlocale(LC_ALL, "ru-RU") << endl;
    cout << setlocale(LC_ALL, "Ru") << endl;
    cout << setlocale(LC_ALL, ".1251") << endl;

    // Установка кодировки входных данных
    // CHange CodePage – утилита командной строки для установки кодировки консоли
    
    // по умолчанию – DOS-866
    system("chcp");
    system("chcp 1251");

    test_full_lab12();
    
    char str[Max_Length];
    
    cout << "Введите строку(без кириллицы): ";
    
    cin.getline(str, Max_Length);

    cout << str << endl;
    cout << "Введено слов: " << word_count(str) << endl;

    system("pause");
    return 0;
}