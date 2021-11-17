#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - �������� �������� ������������
//------------------------------------------------------------------------------

#include "rnd.h"
#include <fstream>
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
// �����������
struct triangle {
    int x1, y1, x2, y2, x3, y3; // ���������� �����
};

// ���� ���������� ������������ �� �����
void In(triangle& t, ifstream& ifst);

// ��������� ���� ���������� ������������
void InRnd(triangle& t);

// ����� ���������� ������������ � ������������� �����
void Out(triangle& t, ofstream& ofst);

// ���������� ��������� ������������
double Perimeter(triangle& t);

#endif //__triangle__
