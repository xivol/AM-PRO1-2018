/* func_l3.cpp
 * Реализация функция из лабораторной №3.
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#include "func_l3.h"

double exp_of(const double x, const double eps)
{
    double e = 1;
    double t = x;
    double k = 1;
    while (abs(t) > eps) {
        e += t;
        t *= x;
        t /= ++k;
    }

    return e;
}

uint sum_prime_factors(const uint k)
{
    if (k == 1 || k == 0)
        return 0;
    uint d = 1;
    while (k % ++d);    
    return d + sum_prime_factors(k / d);
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
