// hello_for.cpp
#include <iostream>
using namespace std;

/* 
    Дана последовательность из N чисел.
    Вывести все нечетные значения кроме последнего.
*/

int _4_main() {
	
	setlocale(LC_ALL, "");

	int n;
	cout<<"Введите количество чисел"<<endl;
	cin>>n;

	cout<<"Введите "<<n<<" чисел в строчку"<<endl;

	int x, y=0;
	for ( int i=1; i<n-1; ++i ) 
	{
		cin>>x;
		if (x % 2 > 0)
		{
			if( y>0 ) cout<<y<<endl;
			y = x;
		}
	}	
	system("pause");
	return 0;
}