/* test_l4.h
 * Опесание Тестов функций из библиотеки func_l3.h
 */

#pragma once

// bool test_distance()
// Функциия:
// double distance ( double x1, double y1, double x2, double y2 )
// Проверка случаев единичного отрезка, 
// отрезка иррациональной длины и отрезка нулевой длины.
bool test_distance();

// bool test_sort()
// Функциия:
// void sort ( double &a, double &b, double &c, bool asc = 0)
// Проверка работы с параметром по умолчанию и без,
// на упорядоченной и не упорядоченной последовательности.
bool test_sort();

// bool test_checkTriangleType()
// Функциия:
// triangleType checkTriangleType ( double xa, double ya, double xb, double yb, double xc, double yc )
// Проверка случаев прямоугольного, остроугольного, 
// тупоугольного и вырожденного треугольников.
bool test_checkTriangleType();

// bool test_square()
// Функциия:
// double square ( double xa, double ya, double xb, double yb, double xc, double yc )
// Проверка для равностороннего, прямоугольного 
// и вырожденного треугольников.
bool test_square();

// bool test_distanceTo()
// Функциия:
// double distanceTo ( double from_x, double from_y, double to_x1, double to_y1, double to_x2, double to_y2 )
// Проверка корректности вычислений, 
// случая принадлежности точки прямой, 
// совпадения точки с одним из концов отрезка.
bool test_distanceTo();
