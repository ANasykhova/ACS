//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include "container.h"
#include <iostream>
#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>

void errMessage1();

void errMessage2();

int main(int argc, char* argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    cout << "Start" << endl;
    container c;
    int size = 100;
    bool isFile;

    if (!strcmp(argv[1], "-f")) {
        isFile = true;
    }
    else if (!strcmp(argv[1], "-n")) {
        isFile = false;
        size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            cout << "incorrect numer of figures = "
                << size
                << ". Set 0 < number <= 10000\n";
            return 3;
        }
    }
    else {
        errMessage2();
        return 2;
    }

    // Автоматическое выделение памяти для массива
    shape* arr = new shape[size];
    Init(c, arr, size);
    std::cout << "Size = " << size << "\n";

    // Проверка источника данных
    if (isFile) {
        ifstream ifst(argv[2]);
        In(c, ifst);
    }
    else {
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        InRnd(c, size);
    }

    // Вывод содержимого контейнера в файл
    ofstream ofst1(argv[3]);
    Out(c, ofst1);

    // Сортировка контейнера (8 вариант)
    ofstream ofst2(argv[4]);
    QuickSort(c);
    Out(c, ofst2);

    // Очищение памяти.
    Clear(c);

    cout << "Stop" << endl;
    return 0;
}

void errMessage1() {
    cout << "Incorrect command line!\n"
        "  Waited:\n"
        "     command -f InFile FirstOutFile SecondOutFile\n"
        "  Or:\n"
        "     command -n number FirstOutFile SecondOutFile\n";
}

void errMessage2() {
    cout << "Incorrect qualifier value!\n"
        "  Waited:\n"
        "     command -f infile outfile01 outfile02\n"
        "  Or:\n"
        "     command -n number outfile01 outfile02\n";
}
