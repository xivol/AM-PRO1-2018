#pragma once

typedef double(*simple_func)(double);
typedef unsigned int uint;

// ѕоиск элементов массива x с минимальным рассто€нием между точками (x, y = f(x)).
// ѕараметры:
//      f - указатель на целевую функцию,
//      x - указатель на массив значений абсцисс точек,
//      size - количество тоек,
//      index1, index2 - выходные параметры.
// ¬озвращаемое значение:
//      минимальное рассто€ние между точками,
//      index1, index2 - индексы точек с минимальным рассто€нием.
double min_distance(const simple_func f, const double *x, const uint size, int &min_index1, int &min_index2);
