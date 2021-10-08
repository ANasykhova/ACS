//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры св€занные с обработкой обобщенной фигуры
// и создани€ произвольной фигуры.
//------------------------------------------------------------------------------

#include "shape.h"

//------------------------------------------------------------------------------
// ¬вод параметров обобщенной фигуры из файла
bool In(ifstream& ifst, shape& s) {
    int k;
    ifst >> k;
    switch (k) {
    case 1:
        s.k = shape::RECTANGLE;
        In(s.r, ifst);
        return true;
    case 2:
        s.k = shape::TRIANGLE;
        In(s.t, ifst);
        return true;
    case 3:
        s.k = shape::CIRCLE;
        In(s.c, ifst);
        return true;
    default:
        return false;
    }
}

// —лучайный ввод обобщенной фигуры
bool InRnd(shape& s) {
    auto k = rand() % 3 + 1;
    switch (k) {
    case 1:
        s.k = shape::RECTANGLE;
        InRnd(s.r);
        return true;
    case 2:
        s.k = shape::TRIANGLE;
        InRnd(s.t);
        return true;
    case 3:
        s.k = shape::CIRCLE;
        InRnd(s.c);
        return true;
    default:
        return false;
    }
}

//------------------------------------------------------------------------------
// ¬ывод параметров текущей фигуры в поток
void Out(shape& s, ofstream& ofst) {
    switch (s.k) {
    case shape::RECTANGLE:
        Out(s.r, ofst);
        break;
    case shape::TRIANGLE:
        Out(s.t, ofst);
        break;
    case shape::CIRCLE:
        Out(s.c, ofst);
        break;
    default:
        ofst << "Incorrect figure!" << endl;
        break;
    }
}

//------------------------------------------------------------------------------
// ¬ычисление периметра фигуры
double Perimeter(shape& s) {
    switch (s.k) {
    case shape::RECTANGLE:
        return Perimeter(s.r);
    case shape::TRIANGLE:
        return Perimeter(s.t);
    case shape::CIRCLE:
        return Perimeter(s.c);
    default:
        return 0.0;
    }
}
