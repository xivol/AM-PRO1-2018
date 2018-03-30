//
// Лабораторная работа №15. Текстовые файлы. Обработка строк
// test_lab15.h
//

// Функция сравнения двух текстовых файлов 
// на равенство посимвольно.
// Входные данные:
//     filename1 - имя первого файла входных данных;
//     filename2 - имя второго файла входных данных.
// Возвращает true, если файлы имют одинаковое содержимое.
// Выбрасывает исключение char*, если файл не может быть открыт
bool is_equal_text(const char *filename1, const char *filename2);

// Тестирования работы функции
// bool is_equal_file(const char*filename1, const char *filename2)
// Входные параметры:
//     filename1 - имя файла входных данных;
//     filename2 - имя другого файла входных данных.
bool test_is_equal_text(const char *filename1, const char *filename2);

// Тестирования работы функции
// void print_len(const char *filename)
// Входные параметры:
//     input - имя файла входных данных;
//     output -  имя фала с ожидаемым результатом.
bool test_print_len(const char *input, const char *output);

// Тестирования работы функции
// uint* alpha_count(const char *filename, uint &size);
// Проверяет случаи пустого файла, 
// файла содержащего весть алфавит в смешаном регистре, 
// файла содержащего произвольную строку.
bool test_alpha_count(void *f = nullptr);

// Тестирования работы функции
// uint word_count(const char* filename);
// Проверяет случаи пустого файла и различного количества слов в файле.
bool test_word_count(void *f = nullptr);

// Тестирования работы функции
// void remove_word(const char* filename, const char *word);
// Входные параметры:
//     input – имя файла входных данных;
//     output – имя фала с ожидаемым результатом;
//     word – удалённое в файле слово.
bool test_remove_word(const char *input, const char *output, const char *word, void *f = nullptr);

// Полный тест библиотеки
bool test_full_lab15();