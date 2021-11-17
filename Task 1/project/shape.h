#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры.
//------------------------------------------------------------------------------

#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include <iostream>

//------------------------------------------------------------------------------
// Структура, обобщающая все имеющиеся фигуры.
struct shape {
    // Значения ключей для каждой из фигур.
    enum key { RECTANGLE, TRIANGLE, CIRCLE };
    key k; // Ключ.
    // Используемые альтернативы.
    union { // Используем простейшую реализацию.
        rectangle r;
        triangle t;
        circle c;
    };

    enum color { RED, ORANGE, YELLOW, GREEN, BLUE, DARKBLUE, PURPLE };
};

// Ввод обобщенной фигуры
bool In(ifstream& ifdt, shape& s);

// Случайный ввод обобщенной фигуры
bool InRnd(shape& s);

// Вывод обобщенной фигуры
void Out(shape& s, ofstream& ofst);

// Вычисление периметра обобщенной фигуры
double Perimeter(shape& s);

#endif
