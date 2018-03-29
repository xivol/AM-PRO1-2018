//
// Лабораторная работа №15. Текстовые файлы. Обработка строк
// test_lab15.cpp
//
#include <cstring>
#include <cassert>
#include <iostream>
#include <fstream>
#include "lab15.h"
#include "test_lab15.h"

using namespace std;

bool is_equal_text(const char *filename1, const char *filename2)
{
	assert(filename1);
	assert(filename2);

	ifstream f1(filename1);
	if (!f1.is_open()) {
		char error[128] = "Couldn't open file ";
		strcat_s(error, 128, filename1);
		throw error;
	}

	ifstream f2(filename2);
	if (!f2.is_open()) {
		char error[128] = "Couldn't open file ";
		strcat_s(error, 128, filename2);
		throw error;
	}

	while (!f1.eof() && !f2.eof())
		if (f1.get() != f2.get())
			return false;

	if (!f1.eof() || !f2.eof())
		return false;

	f1.close();
	f2.close();
	return true;
}

bool test_is_equal_text(const char *filename1, const char *filename2)
{
	cerr << "test is_equal_text : ";
	assert(filename1);
	assert(filename2);

	assert(is_equal_text(filename1, filename1));

	assert(is_equal_text(filename2, filename2));

	assert(!is_equal_text(filename2, filename1));

	assert(!is_equal_text(filename1, filename2));

	cerr << "OK" << endl;
	return true;
}

//
bool test_print_len(const char *input, const char *output)
{
    assert(input);
    assert(output);

	cerr << "test print_len : ";

    // создаём временный файл
    const char* test_out_name = "test_print_len.tmp";
    ofstream test_out(test_out_name);

     // сохраняем старый буфер вывода
    streambuf *cout_buffer = cout.rdbuf();
    // перенаправляем буфер вывода в файл
    cout.rdbuf(test_out.rdbuf());         
    // теперь весь вывод в std::cout уходит в файл test_out

    print_len(input);

    // завершаем операции с буфером
    cout.flush();
    // восстанавливаем старый буфер вывода
    cout.rdbuf(cout_buffer);
    // закрвываем файл с выводом
    test_out.close();

    // сравним содержимое файла вывода с ожидаемым содержимым файла
    assert(is_equal_text(test_out_name, output));

    // удалим временный файл
    remove(test_out_name);

	cerr << "OK" << endl;
    return true;
}

bool test_alpha_count(void *func)
{
	cerr << "test alpha_count : ";

	if (func == nullptr) {
		cerr << "NOT IMPLEMENTED" << endl;
		return true;
	}
	uint* (*alpha_count)(const char *filename, uint &size) = (uint* (*)(const char *, uint &)) func;

	const char *test_filename = "test_alpha_count.tmp";
	uint result[] = { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0 };
	uint result_size = 26;

	// пустой файл
	ofstream fout(test_filename);
	assert(fout.is_open());
	fout.close();

	uint size = 0;
	uint *abc = alpha_count(test_filename, size);
	assert(result_size == size);
	for (uint i = 0; i < size; ++i)
		assert(abc[i] == result[i]);

	// файл с неполным алфавитом
	fout.open(test_filename);
	assert(fout.is_open());
	const char *test_string = "Hello, world!";
	fout << test_string;	
	fout.close();

	result[7] = 1;
	result[4] = 1;
	result[11] = 3;
	result[14] = 2;
	result[22] = 1;
	result[17] = 1;
	result[3] = 1;

	abc = alpha_count(test_filename, size);
	assert(result_size == size);
	for (uint i = 0; i < size; ++i)
		assert(abc[i] == result[i]);

	// файл с полным алфавитом
	fout.open(test_filename);
	assert(fout.is_open());
	test_string = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	fout << test_string;
	fout.close();

	for (uint i = 0; i < result_size; ++i)
		result[i] = 2;

	abc = alpha_count(test_filename, size);
	assert(result_size == size);
	for (uint i = 0; i < size; ++i)
		assert(abc[i] == result[i]);

	remove(test_filename);

	cerr << "OK" << endl;
	return true;
}

bool test_word_count(void *func)
{
	cerr << "test word_count : ";

	if (func == nullptr) {
		cerr << "NOT IMPLEMENTED" << endl;
		return true;
	}
	uint (*word_count)(const char *filename) = (uint (*)(const char *)) func;

	const char *test_filename = "test_word_count.tmp";

	// пустой файл
	ofstream fout(test_filename);
	assert(fout.is_open());
	fout.close();

	assert(word_count(test_filename) == 0);

	// файл без слов
	fout.open(test_filename);
	assert(fout.is_open());
	const char *test_string = "\n\s\s\n\s";
	fout << test_string;
	fout.close();

	assert(word_count(test_filename) == 0);

	// файл с одним словом
	fout.open(test_filename);
	assert(fout.is_open());
	test_string = "Hello,world!";
	fout << test_string;
	fout.close();

	assert(word_count(test_filename) == 1);

	// файл с одним словом
	fout.open(test_filename);
	assert(fout.is_open());
	test_string = "\r\nHello,world!\r\n ";
	fout << test_string;
	fout.close();

	assert(word_count(test_filename) == 1);

	// файл с двумя словами
	fout.open(test_filename);
	assert(fout.is_open());
	test_string = "Hello, world!";
	fout << test_string;
	fout.close();

	assert(word_count(test_filename) == 2);
	
	// файл с четырьмя словами
	fout.open(test_filename);
	assert(fout.is_open());
	test_string = "Don't worry!\r\nBe happy!";
	fout << test_string;
	fout.close();

	assert(word_count(test_filename) == 4);

	remove(test_filename);

	cerr << "OK" << endl;
	return true;
}

bool test_remove_word(const char *input, const char *output, const char * word, void *func)
{
	cerr << "test remove_word : ";

	if (func == nullptr) {
		cerr << "NOT IMPLEMENTED" << endl;
		return true;
	}
	void(*remove_word)(const char*, const char *) = (void(*)(const char*, const char *)) func;
	
	const char *test_filename = "test_remove_word.tmp";

	// сделаем копию входных данных
	ifstream  src(input, std::ios::binary);
	ofstream  dst(test_filename, std::ios::binary);
	dst << src.rdbuf();

	remove_word(test_filename, word);

	assert(is_equal_text(output, test_filename));

	// удаляем несуществующее слово
	word = "{}{}{}";

	remove_word(test_filename, word);

	assert(is_equal_text(output, test_filename));

	remove(test_filename);

	cerr << "OK" << endl;
	return true;
}

bool test_full_lab15()
{
#ifdef _DEBUG
	const char *input = "jabberwocky.txt";

	return test_is_equal_text(input, "jabberwocky_test_print_len.txt") &&
		test_print_len(input, "jabberwocky_test_print_len.txt") &&
		test_alpha_count(/*ваша реализация здесь*/) &&
		test_word_count(/*ваша реализация здесь*/);
		test_remove_word(input, "jabberwocky_test_remove_the.txt", "the", /*ваша реализация здесь*/);

#else
	return true;
#endif    
}