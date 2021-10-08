#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include "rnd.h"
#include <fstream>
#include <iostream>

using namespace std;

// Прямоугольник
struct rectangle {
    int x1, y1, x2, y2; // Координаты левого верхнего, правого нижнего.
};

// Ввод параметров прямоугольника из файла
void In(rectangle& r, ifstream& ifst);

// Случайный ввод параметров прямоугольника
void InRnd(rectangle& r);

// Вывод параметров прямоугольника в форматируемый поток
void Out(rectangle& r, ofstream& ofst);

// Вычисление периметра прямоугольника
double Perimeter(rectangle& r);

#endif  //__rectangle__
