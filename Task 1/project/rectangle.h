#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - �������� �������� ��������������  � ��� ����������
//------------------------------------------------------------------------------

#include "rnd.h"
#include <fstream>
#include <iostream>

using namespace std;

// �������������
struct rectangle {
    int x1, y1, x2, y2; // ���������� ������ ��������, ������� �������.
};

// ���� ���������� �������������� �� �����
void In(rectangle& r, ifstream& ifst);

// ��������� ���� ���������� ��������������
void InRnd(rectangle& r);

// ����� ���������� �������������� � ������������� �����
void Out(rectangle& r, ofstream& ofst);

// ���������� ��������� ��������������
double Perimeter(rectangle& r);

#endif  //__rectangle__
