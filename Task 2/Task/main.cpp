//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>

#include <chrono> // для вычисления времени
typedef std::chrono::high_resolution_clock Clock;

#include "Container.h"

void errMessage1() {
    std::cout << "Incorrect command line!\n"
        "  Waited:\n"
        "     command -f InputFile OutputFile SortedFile\n"
        "  Or:\n"
        "     command -n number OutputFile SortedFile\n";
}

void errMessage2() {
    std::cout << "Incorrect qualifier value!\n"
        "  Waited:\n"
        "     command -f InputFile OutputFile SortedFile\n"
        "  Or:\n"
        "     command -n number OutputFile SortedFile\n";
}

//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    auto t1 = Clock::now();
    
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    std::cout << "Start\n";

    Container c;
    c.Init();

    if (!strcmp(argv[1], "-f")) {
        std::ifstream ifst(argv[2]);
        c.In(ifst);
    } else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            std::cout << "incorrect numer of figures = "
                      << size
                      << ". Set 0 < number <= 10000\n";
            return 3;
        }

        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        c.InRnd(size);
    } else {
        errMessage2();
        return 2;
    }
    
    // Вывод содержимого контейнера в файл
    std::ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    c.Out(ofst1);

    // Сортировка контейнера по периметру.
    c.Sort();

    std::ofstream ofst2(argv[4]);
    ofst2 << "Container after sorting:\n";
    c.Out(ofst2);

    // Очищение памяти.
    c.Clear();

    // Завершение программы.
    std::cout << "Stop\n";
    
    auto t2 = Clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>
        (t2 - t1).count() << " nanoseconds\n";
    
    return 0;
}
