#ifndef __Circle__
#define __Circle__

//------------------------------------------------------------------------------
// Circle.h - содержит описание цветка
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "math.h"
#include "rnd.h"
#include "Shape.h"

//------------------------------------------------------------------------------
// Круг.
class Circle : public Shape {
public:
    ~Circle();

    // Ввод круга из файла.
    void In(std::ifstream &ifst) override;

    // Случайный ввод круга.
    void InRnd() override;

    // Вывод круга в форматируемый поток.
    void Out(std::ofstream &ofst) override;

    // Вычисление периметра круга.
    double Perimeter() override;

private:
    // Цвет круга.
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

    Color circle_color;

    // Координаты круга и его радиус.
    int x, y, r;

    static Color GetColor(const int& color);
};

#endif //__Circle__
