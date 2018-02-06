//
// Лабораторная работа №5. Библиотека функций
// main.cpp
//

#include <iostream>
#include "lab5.h"

using namespace std;

int main()
{
    // sqr(2);

    double x1, y1, x2, y2;
    cin >> x1, y1;
    cin >> x2, y2;
    cout << distance(x1, y1, x2, y2) << endl;

    system("pause");
    return 0;
}
