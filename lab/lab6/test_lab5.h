//
// Лабораторная работа №6. Тестирование
// test_lab5.h
//

#pragma once

 // Точность сравнения вещественных чисел
const double precision = 1E-15;

// bool test_sqr(int number_of_tests)
// Функциия:
// double sqr ( double x)
// проверка отрицательных, положительных и дробных значений.
bool test_sqr(int number_of_tests);

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

// bool test_check_triangle_type()
// Функциия:
// triangle_type check_triangle_type ( double xa, double ya, double xb, double yb, double xc, double yc )
// Проверка случаев прямоугольного, остроугольного, 
// тупоугольного и вырожденного треугольников.
bool test_check_triangle_type();

// bool test_square()
// Функциия:
// double square ( double xa, double ya, double xb, double yb, double xc, double yc )
// Проверка для равностороннего, прямоугольного 
// и вырожденного треугольников.
bool test_square();

// bool test_distance_to()
// Функциия:
// double distance_to ( double from_x, double from_y, double to_x1, double to_y1, double to_x2, double to_y2 )
// Проверка корректности вычислений, 
// случая принадлежности точки прямой, 
// совпадения точки с одним из концов отрезка.
bool test_distance_to();
