#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - содержит описание треугольника
//------------------------------------------------------------------------------

#include "rnd.h"
#include <fstream>
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
// Треугольник
struct triangle {
    int x1, y1, x2, y2, x3, y3; // Координаты углов
};

// Ввод параметров треугольника из файла
void In(triangle& t, ifstream& ifst);

// Случайный ввод параметров треугольника
void InRnd(triangle& t);

// Вывод параметров треугольника в форматируемый поток
void Out(triangle& t, ofstream& ofst);

// Вычисление периметра треугольника
double Perimeter(triangle& t);

#endif //__triangle__
