//------------------------------------------------------------------------------
// triangle.cpp - �������� ������� ��������� ������������
//------------------------------------------------------------------------------

#include "triangle.h"

//------------------------------------------------------------------------------
// ���� ���������� ������������ �� ������
void In(triangle& t, ifstream& ifst) {
    ifst >> t.x1 >> t.y1 >> t.x2 >> t.y2 >> t.x3 >> t.y3;
}

// ��������� ���� ���������� ������������
void InRnd(triangle& t) {
    t.x1 = Random();
    t.y1 = Random();

    do {
        t.x2 = Random();
        t.y2 = Random();
    } while (t.x1 == t.x2 || t.y1 == t.y2);

    double a = sqrt((t.x2 - t.x1) * (t.x2 - t.x1) + (t.y2 - t.y1) * (t.y2 - t.y1));
    double b, c;

    do {
        t.x3 = Random();
        t.y3 = Random();

        b = sqrt((t.x3 - t.x1) * (t.x3 - t.x1) + (t.y3 - t.y1) * (t.y3 - t.y1));
        c = sqrt((t.x3 - t.x2) * (t.x3 - t.x2) + (t.y3 - t.y2) * (t.y3 - t.y2));
    } while ((c >= (a + b))
        || (a >= (c + b))
        || (b >= (c + a)));
}


//------------------------------------------------------------------------------
// ����� ���������� ������������ � �����
void Out(triangle& t, ofstream& ofst) {
    ofst << "It is Triangle: x1 = " << t.x1 << ", y1 = " << t.y1
        << ", x2 = " << t.x2 << ", y2 = " << t.y2
        << ", x3 = " << t.x3 << ", y3 = " << t.y3
        << ". Perimeter = " << Perimeter(t) << "\n";
}


//------------------------------------------------------------------------------
// ���������� ��������� ������������
double Perimeter(triangle& t) {
    double a = sqrt((t.x2 - t.x1) * (t.x2 - t.x1) + (t.y2 - t.y1) * (t.y2 - t.y1));

    double b = sqrt((t.x3 - t.x1) * (t.x3 - t.x1) + (t.y3 - t.y1) * (t.y3 - t.y1));

    double c = sqrt((t.x3 - t.x2) * (t.x3 - t.x2) + (t.y3 - t.y2) * (t.y3 - t.y2));

    return double(a + b + c);
}
