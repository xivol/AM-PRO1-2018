#include <iostream>
#include <iomanip>

using namespace std;

// void print_bin(int number)
// Вывод на консоль числа в двоичном формате. 
// Формат вывода разрядов — от младших к старшим.
void print_bin(int number)
{
    do {
        cout << (number & 1);
        number = number >> 1;
    } while (number);
}

int main()
{
    setlocale(LC_ALL, "Rus");

    cout << "Введите целое число:" << endl;
    int x;
    cin >> x;

    print_bin(x);
    cout << endl;

    system("pause");
    return 0;
}