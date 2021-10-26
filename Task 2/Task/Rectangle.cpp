//------------------------------------------------------------------------------
// Rectangle.cpp - содержит функции обработки прямоугольника.
//------------------------------------------------------------------------------

#include "Rectangle.h"

//------------------------------------------------------------------------------
// Функция для определения цвета прямоугольника по его номеру.
Rectangle::Color Rectangle::GetColor(const int& color) {
    switch (color) {
    case 1:
        return Rectangle::Color::RED;
    case 2:
        return Rectangle::Color::ORANGE;
    case 3:
        return Rectangle::Color::YELLOW;
    case 4:
        return Rectangle::Color::GREEN;
    case 5:
        return Rectangle::Color::BLUE;
    case 6:
        return Rectangle::Color::DARKBLUE;
    case 7:
        return Rectangle::Color::PURPLE;
    default:
        return Rectangle::Color::INVALID_COLOR;
    }
}

// Ввод параметров прямоугольника из потока.
void Rectangle::In(std::ifstream &ifst) {
    // Переменная для определения цвета.
    int color;
    ifst >> this->x1 >> this->y1 >> this->x2 >> this->y2 >> color;
    this->rectangle_color = GetColor(color);
}

// Случайный ввод параметров прямоугольника.
void Rectangle::InRnd() {
    this->x1 = Random();
    this->y1 = Random();

    do {
        this->x2 = Random();
        this->y2 = Random();
    } while (this->x1 == this->x2 && this->y1 == this->y2);
    int color = Random() % 7 + 1;
    this->rectangle_color = GetColor(color);
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в поток.
void Rectangle::Out(std::ofstream &ofst) {
    ofst << "It is Rectangle: x1 = " << this->x1 << ", y1 = " << this->y1
        << ", x2 = " << this->x2 << ", y2 = " << this->y2
        << ", Color = ";
    switch (this->rectangle_color) {
    case Rectangle::Color::RED:
        ofst << "Red";
        break;
    case Rectangle::Color::ORANGE:
        ofst << "Orange";
        break;
    case Rectangle::Color::YELLOW:
        ofst << "Yellow";
        break;
    case Rectangle::Color::GREEN:
        ofst << "Green";
        break;
    case Rectangle::Color::BLUE:
        ofst << "Blue";
        break;
    case Rectangle::Color::DARKBLUE:
        ofst << "Darkblue";
        break;
    case Rectangle::Color::PURPLE:
        ofst << "Purple";
        break;
    default:
        ofst << "Invalid color!";
    }
        
    ofst << ". Perimeter = " << this->Perimeter() << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника.
double Rectangle::Perimeter() {
    return 2.0 * abs(this->x2 - this->x1) + 2.0 * abs(this->y2 - this->y1);
}

Rectangle::~Rectangle() {

}
