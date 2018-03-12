#include <iostream>
#include "lab11.h"
#include "test_lab11.h"
using namespace std;

int main()
{
    test_lab11_full();

    setlocale(LC_ALL, "Rus");
    uint size = 0;
    int * a = nullptr;
    read_new(a, size);
    try {
        duplicate_between_zeros(a, size);
    }
    catch (char* c) {
        cout << c << endl;
    }
    print(a, size);

    system("pause");
    return 0;
}