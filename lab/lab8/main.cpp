//
// Лабораторная №5. Сортировкии, рекурсия в массивах.
// main.cpp
//
// Замер времени выполнения функции быстрой сортировки.

#include <iomanip>
#include <iostream>
#include "lab8.h"

double cotan(double x) {
	return 1 / tan(x);
}

int main() 
{
   

	simple_func f[] = { sin, cos, tan, cotan };
	double x[] = {0,30,60,90,120,150,180,210,240,270,300,330,360};
	table(f, sizeof(f) / sizeof(*f), x, sizeof(x) / sizeof(*x));

	tab(sin, 0.0, 3.1415, 0.1);
		

    system("pause");
    return 0;
}
