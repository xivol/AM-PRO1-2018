// Выбираем номер варианта для индивидуальных заданий

#include <algorithm>
#include <cassert>
#include <locale>
#include <iostream>
#include <string>

using namespace std;

typedef unsigned int uint32_t;

uint32_t jenkins_one_at_a_time_hash(const char *key)
{
	uint32_t hash = 0;
	while (*key) {
		hash += *key++;
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}

char cyr_to_lower(const char c)
{
	return  tolower(c); //locale("rus_rus.866")
}

unsigned int whats_my_number(const string &name, const size_t count)
{
	assert(count);
	size_t current;
	size_t next = -1;
	uint32_t sum_of_hash = 0;
	do {
		current = next + 1;
		next = name.find_first_of(' ', current);
		string token = name.substr(current, next - current);
		transform(token.begin(), token.end(), token.begin(), cyr_to_lower);
		sum_of_hash |= jenkins_one_at_a_time_hash(token.c_str());
	} while (next != string::npos);
	return 1 + sum_of_hash % count;
}

int main()
{
	// Количество заданий
	const size_t number_of_tasks = 11;

	setlocale(LC_ALL, "Rus");

	string name;
	cout << "Введите имя и фамилию:" << endl;

	getline(cin, name);

	if (name.empty())
		return 0;

	cout << "Ваш номер: ";

	setlocale(LC_ALL, "rus_rus.866");

	cout << whats_my_number(name, number_of_tasks) << endl;

	system("pause");
	return 0;
}
