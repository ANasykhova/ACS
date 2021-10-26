#ifndef __Rectangle__
#define __Rectangle__

//------------------------------------------------------------------------------
// Rectangle.h - содержит описание дерева
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "math.h"
#include "rnd.h"
#include "Shape.h"

//------------------------------------------------------------------------------
// Прямоугольник.
class Rectangle : public Shape {
public:
    ~Rectangle();

    // Ввод прямоугольника из файла.
    void In(std::ifstream &ifst) override;

    // Случайный ввод прямоугольника.
    void InRnd() override;

    // Вывод прямоугольника в форматируемый поток.
    void Out(std::ofstream &ofst) override;

    // Вычисление периметра прямоугольника.
    double Perimeter() override;

private:
    // Цвет прямоугольника.
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

    Color rectangle_color;

    // Координаты прямоугольника.
    int x1, x2, y1, y2;

    static Color GetColor(const int& color);
};

#endif //__Rectangle__
