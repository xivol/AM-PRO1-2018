#include <cmath>
#include <iomanip>
#include <iostream>
#include "lab8.h"

using namespace std;

void table(const simple_func funcs[], int func_size, const double points[], int points_size)
{
	std::cout << std::fixed;     // фиксированный формат чисел с плавающей точкой
	std::cout << std::setprecision(4);      // задание количества знаков после запятой

	cout << " | " << setw(10) << "X" << " | ";
	for (int j = 0; j < func_size; ++j) {
		cout << setw(9) << "func" << j << " | ";
	}
	cout << endl;

	for (int i = 0; i < points_size; ++i) 
	{
		double rad = points[i] / 180.0 * 3.14;
		cout << " | " << setw(10) << rad << " | ";
		for (int j = 0; j < func_size; ++j)
		{
			cout << setw(10) << funcs[j](rad) << " | ";
		}
		cout << endl;
	}
}


void tab(double(*const f)(double), const double a, const double b, const double h)
{
	std::cout << std::fixed << std::setprecision(6);
	for (double x = a; x < b; x += h) {
		std::cout << " | ";
		std::cout << std::setw(10) << x;
		std::cout << '|';
		std::cout << std::setw(10) << f(x);
		std::cout << " | ";
		std::cout << std::endl;
	}

	std::cout << " | ";
	std::cout << std::setw(10) << b;
	std::cout << '|';
	std::cout << std::setw(10) << f(b);
	std::cout << " | ";
	std::cout << std::endl;
}