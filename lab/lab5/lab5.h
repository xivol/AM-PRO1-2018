//
// Лабораторная работа №5. Библиотека функций
// lab5.h
//

#pragma once
/* Директива pragma с параметром once гарантирует, 
 * что данный загоовочный файл будет включен в компилируемый файл 
 * не более одного раза.
 *
 * Но только в Visual C++, и некоторых других системах разработки.
 */

// double distance ( double x1, double y1, double x2, double y2 )
// Вычисляет эвклидово расстояние между двумя точками на плоскости.
// Параметры:
//      x1, y1, x2, y2 – вещественные координаты точек.
// Возвращаемое значение:
//      расстояние между точками  ( x1; y1 ), ( x2; y2 ). 
double distance ( double x1, double y1, double x2, double y2 );


// void sort ( double &a, double &b, double &c, bool asc = 0)
// Вспомогательная функция сортировки трех значений.
// Параметры:
//      a, b, c - значения для сортировки,
//      asc - флаг направления сортировки:
//          false - по убыванию (по умолчанию),
//          true - по возростанию.
// Результат:
//      a, b, c отсортированные в соответствии со значением asc.
void sort ( double &a, double &b, double &c, bool asc = 0);


// enum triangleType
// Набор целочисленных констант, описывающих тип треугольника. 
enum triangle_type {
    tRight = 0,     // прямоугольный
    tAcute,         // остроугольный
    tObtuse         // тупоугольный
};

/* Перечисление - удобный способ ограничить набор значений, 
 * которые может принимать переменная или возвращать функция.
 */

// triangle_type check_triangle_type ( double xa, double ya, double xb, double yb, double xc, double yc )
// Определяет тип треугольника, заданного тремя точками.
// Параметры:
//      xa, ya, xb, yb, xc, yc – вещественные координаты точек
//          A ( xa, ya ), B ( xb, yb ), C ( xc, yc ).
// Возвращаемое значение:
//      tRight - прямоугольный,
//      tAcute - остроугольный,
//      tObtuse - тупоугольный.
triangle_type check_triangle_type ( double xa, double ya, double xb, double yb, double xc, double yc );


// double square ( double xa, double ya, double xb, double yb, double xc, double yc )
// Вычисляет площадь треугольника, заданного тремя точками.
// Параметры:
//      xa, ya, xb, yb, xc, yc – вещественные координаты точек 
//          A ( xa, ya ), B ( xb, yb ), C ( xc, yc ).
// Возвращаемое значение:
//      площадь треугольника ABC.
double square ( double xa, double ya, double xb, double yb, double xc, double yc );


// double distance_to ( double from_x, double from_y, double to_x1, double to_y1, double to_x2, double to_y2 )
// Вычисляет расстояние от точки до прямой, заданной двумя точками.
// Параметры:
//      from_x, from_y, to_x1, to_y1, to_x2, to_y2 –  вещественные координаты точек 
//          F ( from_x; from_y ), T1 ( to_x1; to_y1 ), T2 ( to_x2; to_y2 ).
// Возвращаемое значение:
//      расстояние от точки F ( from_x; from_y ) до прямой, заданной точками T1 ( to_x1; to_y1 ), T2 ( to_x2; to_y2 ).
double distance_to ( double from_x, double from_y, double to_x1, double to_y1, double to_x2, double to_y2 );
