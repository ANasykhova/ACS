#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - �������� �������� ���������� �������������� ������.
//------------------------------------------------------------------------------

#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include <iostream>

//------------------------------------------------------------------------------
// ���������, ���������� ��� ��������� ������.
struct shape {
    // �������� ������ ��� ������ �� �����.
    enum key { RECTANGLE, TRIANGLE, CIRCLE };
    key k; // ����.
    // ������������ ������������.
    union { // ���������� ���������� ����������.
        rectangle r;
        triangle t;
        circle c;
    };

    enum color { RED, ORANGE, YELLOW, GREEN, BLUE, DARKBLUE, PURPLE };
};

// ���� ���������� ������
bool In(ifstream& ifdt, shape& s);

// ��������� ���� ���������� ������
bool InRnd(shape& s);

// ����� ���������� ������
void Out(shape& s, ofstream& ofst);

// ���������� ��������� ���������� ������
double Perimeter(shape& s);

#endif
