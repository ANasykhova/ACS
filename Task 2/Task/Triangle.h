#ifndef __Triangle__
#define __Triangle__

//------------------------------------------------------------------------------
// Triangle.h - содержит описание кустарника
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "math.h"
#include "rnd.h"
#include "Shape.h"

//------------------------------------------------------------------------------
// Треугольник.
class Triangle : public Shape {
public:
    ~Triangle();
    // Ввод кустаринка из файла
    void In(std::ifstream &ifst) override;

    // Случайный ввод кустарника
    void InRnd() override;

    // Вывод кустарника в форматируемый поток
    void Out(std::ofstream &ofst) override;

    // Вычисление периметра треугольника.
    double Perimeter() override;

private:
    // Цвет треугольника.
    enum Color {
        RED,
        ORANGE,
        YELLOW,
        GREEN,
        BLUE,
        DARKBLUE,
        PURPLE,
        INVALID_COLOR
    };
    Color triangle_color;

    // Координаты треугольника.
    int x1, x2, x3, y1, y2, y3;

    static Color GetColor(const int &color);
};


#endif //__Triangle__
