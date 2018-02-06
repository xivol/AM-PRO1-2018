#include <iostream>

using namespace std;

typedef unsigned int uint;

// Вывод числа с пробелами между цифрами.
// Вариант без рекурсии.
void print_spaces_flat(uint number)
{
    do {
        cout << number % 10 << " ";
        number /= 10;
    } while (number != 0);
}

// Вывод числа с пробелами между цифрами.
// Рекурсивный вариант.
void print_spaces(uint number) 
{
    // Старшие разряды числа
    int remainder = number / 10;
    
	if(remainder != 0) // Пока есть старшие разряды 
        // Запускаем рекурсию
		print_spaces(remainder);

	// Вывод происходит на рекурсивном возврате
    cout << number % 10 << " ";
}


int main(int argc, char **argv)
{
	setlocale(LC_ALL,"Russian");
	system("chcp 1251");

	uint number;
	cout << "Введите целое число : ";
	cin >> number;

    cout << "Печать числа в виде цифр с пробелами в обратном порядке :";
    print_spaces_flat(number);
    cout << endl;

	cout << "Печать числа в виде цифр с пробелами :";
	print_spaces(number);

	

	cout << endl;
	
    system("pause");
	return 0;
}
