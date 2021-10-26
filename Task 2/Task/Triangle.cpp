//------------------------------------------------------------------------------
// Triangle.cpp - содержит функции обработки треугольника
//------------------------------------------------------------------------------

#include "Triangle.h"

//------------------------------------------------------------------------------
// Функция для определения цвета треугольника по его номеру.
Triangle::Color Triangle::GetColor(const int &color) {
    switch (color) {
        case 1:
            return Triangle::Color::RED;
        case 2:
            return Triangle::Color::ORANGE;
        case 3:
            return Triangle::Color::YELLOW;
        case 4:
            return Triangle::Color::GREEN;
        case 5:
            return Triangle::Color::BLUE;
        case 6:
            return Triangle::Color::DARKBLUE;
        case 7:
            return Triangle::Color::PURPLE;
        default:
            return Triangle::Color::INVALID_COLOR;
    }
}

// Ввод параметров треугольника из потока.
void Triangle::In(std::ifstream &ifst) {
    // Переменная для определения цвета.
    int color;

    ifst >> this->x1 >> this->y1 >> this->x2 >> this->y2 >> 
    	this->x3 >> this->y3 >> color;
    this->triangle_color = GetColor(color);
}

// Случайный ввод параметров треугольника.
void Triangle::InRnd() {
    this->x1 = Random();
    this->y1 = Random();

    do {
        this->x2 = Random();
        this->y2 = Random();
    } while (this->x1 == this->x2 && this->y1 == this->y2);

    double a = sqrt((this->x2 - this->x1) * (this->x2 - this->x1) + 
        (this->y2 - this->y1) * (this->y2 - this->y1));
    double b, c;

    do {
        this->x3 = Random();
        this->y3 = Random();

        b = sqrt((this->x3 - this->x1) * (this->x3 - this->x1) + 
            (this->y3 - this->y1) * (this->y3 - this->y1));

        c = sqrt((this->x3 - this->x2) * (this->x3 - this->x2) + 
            (this->y3 - this->y2) * (this->y3 - this->y2));

    } while ((c >= (a + b))
        || (a >= (c + b))
        || (b >= (c + a)));
        
    int color = Random() % 7 + 1;
    this->triangle_color = GetColor(color);

}

//------------------------------------------------------------------------------
// Вывод параметров треугольника в поток.
void Triangle::Out(std::ofstream &ofst) {
    ofst << "It is Triangle: x1 = " << this->x1 << ", y1 = " << this->y1
        << ", x2 = " << this->x2 << ", y2 = " << this->y2
        << ", x3 = " << this->x3 << ", y3 = " << this->y3
        << ", Color = ";
    switch (this->triangle_color) {
    case Triangle::Color::RED:
        ofst << "Red";
        break;
    case Triangle::Color::ORANGE:
        ofst << "Orange";
        break;
    case Triangle::Color::YELLOW:
        ofst << "Yellow";
        break;
    case Triangle::Color::GREEN:
        ofst << "Green";
        break;
    case Triangle::Color::BLUE:
        ofst << "Blue";
        break;
    case Triangle::Color::DARKBLUE:
        ofst << "Darkblue";
        break;
    case Triangle::Color::PURPLE:
        ofst << "Purple";
        break;
    default:
        ofst << "Invalid color!";
    }
        
    ofst << ". Perimeter = " << this->Perimeter() << "\n";

}

//------------------------------------------------------------------------------
// Вычисление периметра треугольника.
double Triangle::Perimeter() {
    double a = sqrt((this->x2 - this->x1) * (this->x2 - this->x1) + 
        (this->y2 - this->y1) * (this->y2 - this->y1));

    double b = sqrt((this->x3 - this->x1) * (this->x3 - this->x1) 
        + (this->y3 - this->y1) * (this->y3 - this->y1));

    double c = sqrt((this->x3 - this->x2) * (this->x3 - this->x2) 
        + (this->y3 - this->y2) * (this->y3 - this->y2));

    return double(a + b + c);

}

Triangle::~Triangle() {

}
