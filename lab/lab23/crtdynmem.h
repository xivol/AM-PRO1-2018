//
// Лабораторная работа №6. Динамические массивы.
// crtdynmem.h
// Контроль утечек памяти при помощи библиотеки crtdbg
//
// Этот файл необходимо подключать до любого другого файла, 
// содержащего выделение памяти опреатором new.
#pragma once

#if defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    #include "debug_new.h"
#else
    #include <crtdbg.h> // библиотека для отслеживания операций выделения памяти

    #ifndef DBG_NEW // макрос для обработки оператора new
    // Сохраняем файл и строку, где был вызван оператор new
        #define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
        #define new DBG_NEW
    #endif /* DBG_NEW */
#endif
