
#include <iostream>

// Объявление пременных из пространства имен std
using std::cout;
using std::endl;
using std::cin;

// Другой вариант:
// using namespace std;

// Сравнение возраста с возрастом C++
void cmp_age_to_cpp(int age)
{
	if( age < 30 ) 
		cout << "Вы — моложе чем C++!" << endl;
	else
		if( age == 30 ) 
			cout << "Вы — ровесники с C++!" << endl;
		else
			cout << "Вы — старше чем C++!" << endl;

}

int _2_main ()
{
	// Установка кодировки строк по умолчанию.
	setlocale(LC_ALL, "");
	// Необходима для корректного отображения кириллицы на консоли.

	char name [20];	

	cout << "Как Вас зовут?" << endl;

	cin >> name;

	int age;

	cout << "Сколько Вам лет?" << endl;

	cin >> age;

	cout << "Здравствуйте, " << name << "!" << endl;

	cmp_age_to_cpp(age);

	system("pause");

	return 0;
}