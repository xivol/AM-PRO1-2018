//
// Лабораторная работа №6. Тестирование
// test_lab5.h
//

#pragma once

 // Точность сравнения вещественных чисел
const double precision = 1E-10;

// Тесты функциии:
// double sqr ( double x)
// Проверка отрицательных, положительных и нулевых значений.
bool test_sqr();

// Тесты функциии:
// double distance ( double x1, double y1, double x2, double y2 )
// Проверка случаев единичного отрезка, 
// отрезка иррациональной длины и отрезка нулевой длины.
bool test_distance();

// Тесты функциии:
// void sort ( double &a, double &b, double &c, bool asc = 0)
// Проверка работы с параметром по умолчанию и без,
// на упорядоченной и не упорядоченной последовательности.
bool test_sort();

// Тесты функциии:
// triangle_type check_triangle_type ( double xa, double ya, double xb, double yb, double xc, double yc )
// Проверка случаев прямоугольного, остроугольного, 
// тупоугольного и вырожденного треугольников.
bool test_check_triangle_type();

// Тесты функциии:
// double square ( double xa, double ya, double xb, double yb, double xc, double yc )
// Проверка для равностороннего, прямоугольного 
// и вырожденного треугольников.
bool test_square();

// Тесты функциии:
// double distance_to_line ( double point_x, double point_y, double line_x1, double line_y1, double line_x2, double line_y2 )
// Проверка корректности вычислений, 
// случая принадлежности точки прямой, 
// совпадения точки с одним из концов отрезка.
bool test_distance_to();


bool test_full_lab5();