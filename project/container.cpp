//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера.
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера.
void Init(container& c, shape* arr, int size) {
    std::cout << "Start Init\n";
    c.cont = arr;
    c.len = size;
    std::cout << "End Init\n";
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container& c) {
    delete[] c.cont;
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In(container& c, ifstream& ifst) {
    while (!ifst.eof()) {
        In(ifst, c.cont[c.len]);
        c.len++;
    }
}

// Случайный ввод содержимого контейнера
void InRnd(container& c, int size) {
    std::cout << "Start Rnd\n";
    c.len = size;
    for (int i = 0; i < size; i++) {
        InRnd(c.cont[i]);
    }
    std::cout << "End Rnd\n";
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container& c, ofstream& ofst) {
    for (int i = 0; i < c.len; i++) {
        Out(c.cont[i], ofst);
    }
}

//------------------------------------------------------------------------------
// Быстрая сортировка контейнера по периметру.
void QuickSort(container& c) {
    int size = c.len;
    double* mas = new double[size];

    for (int i = 0; i < size; i++) {
        switch (c.cont->k) {
        case shape::RECTANGLE:
            mas[i] = Perimeter(c.cont->r);
            break;
        case shape::TRIANGLE:
            mas[i] = Perimeter(c.cont->t);
            break;
        case shape::CIRCLE:
            mas[i] = Perimeter(c.cont->c);
            break;
        default:
            mas[i] = Perimeter(c.cont->r);
            break;
        }
    }

    qsortRecursive(mas, size, c);
}


void qsortRecursive(double* mas, int size, container& c) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    double mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (mas[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            shape s = c.cont[i];
            c.cont[i] = c.cont[j];
            c.cont[j] = s;

            double tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {
        //"Левый кусок"
        qsortRecursive(mas, j + 1, c);
    }
    if (i < size) {
        //"Првый кусок"
        qsortRecursive(&mas[i], size - i, c);
    }
}

