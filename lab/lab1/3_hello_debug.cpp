#include <iostream>

using namespace std;

/*
	јрифметические действи€ над числами пронумерованы следующим образом: 
	1 Ч сложение, 2 Ч вычитание, 3 Ч умножение, 4 Ч деление. 
	ƒан номер действи€ N (целое число в диапазоне 1Ц4) и вещественные числа A и B (B не равно 0). 
	¬ыполнить над числами указанное действие и вывести результат.
*/

int _3_main()
{
	setlocale(LC_ALL, "Rus");
	cout<<"¬ведите код оепрации:"<<endl
		<<"1 Ч сложение,"<<endl
		<<"2 Ч вычитание,"<<endl
		<<"3 Ч умножение,"<<endl
		<<"4 Ч деление."<<endl;
	int oper;
	cin >> oper;


	int x, y;
	cout<<"¬ведите два целых числа"<<endl;
	cin >> x >> y;

	double result;

	switch (oper)
	{
	case 1: result=x+y;
	case 2: result=x-y;
	case 3: result=x*y;
	case 4: result=x/y;
	default:
		cout<<"Ќеверна€ операци€"<<endl;		
	}

	if (oper >= 1 && oper <= 4)
		cout<<"–езультат: "<<result<<endl;

	system ("pause");
	return 0;
}