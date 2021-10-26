//------------------------------------------------------------------------------
// Circle.cpp - содержит функции обработки круга
//------------------------------------------------------------------------------

#include "Circle.h"
#define _USE_MATH_DEFINES
#include <math.h>


//------------------------------------------------------------------------------
// Функция для определения цвета круга. по его номеру.
Circle::Color Circle::GetColor(const int& color) {
    switch (color) {
    case 1:
        return Circle::Color::RED;
    case 2:
        return Circle::Color::ORANGE;
    case 3:
        return Circle::Color::YELLOW;
    case 4:
        return Circle::Color::GREEN;
    case 5:
        return Circle::Color::BLUE;
    case 6:
        return Circle::Color::DARKBLUE;
    case 7:
        return Circle::Color::PURPLE;
    default:
        return Circle::Color::INVALID_COLOR;
    }
}

// Ввод параметров круга из потока.
void Circle::In(std::ifstream &ifst) {
    // Переменная для определения цвета.
    int color;
    ifst >> this->x >> this->y >> this->r >> color;
    this->circle_color = GetColor(color);
}

// Случайный ввод параметров круга.
void Circle::InRnd() {
    this->x = Random();
    this->y = Random();
    this->r = Random();
    
    int color = Random() % 7 + 1;
    this->circle_color = GetColor(color);
}

//------------------------------------------------------------------------------
// Вывод параметров круга в поток.
void Circle::Out(std::ofstream &ofst) {
    ofst << "It is Circle: x = " << this->x
        << ", y = " << this->y
        << ", r = " << this->r
        << ", Color = ";
    switch (this->circle_color) {
    case Circle::Color::RED:
        ofst << "Red";
        break;
    case Circle::Color::ORANGE:
        ofst << "Orange";
        break;
    case Circle::Color::YELLOW:
        ofst << "Yellow";
        break;
    case Circle::Color::GREEN:
        ofst << "Green";
        break;
    case Circle::Color::BLUE:
        ofst << "Blue";
        break;
    case Circle::Color::DARKBLUE:
        ofst << "Darkblue";
        break;
    case Circle::Color::PURPLE:
        ofst << "Purple";
        break;
    default:
        ofst << "Invalid color!";
    }
        
    ofst << ". Perimeter = " << Perimeter() << "\n";

}

//------------------------------------------------------------------------------
// Вычисление периметра круга.
double Circle::Perimeter() {
    return 2.0 * M_PI * this->r;
}

Circle::~Circle() {
    
}
