#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - �������� ��� ������,
// �������������� ���������� ���������
//------------------------------------------------------------------------------

#include "shape.h"
#include <fstream>
#include <iostream>

//------------------------------------------------------------------------------
// ���������� ��������� �� ������ ����������� �������
struct container {
    enum { max_len = 10000 }; // ������������ �����
    int len; // ������� �����
    shape* cont;
};

// ������������� ����������
void Init(container& c, shape* arr, int size);

// ������� ���������� �� ��������� (������������ ������)
void Clear(container& c);

// ���� ����������� ���������� �� ���������� ������
void In(container& c, ifstream& ifst);

// ��������� ���� ����������� ����������
void InRnd(container& c, int size);

// ����� ����������� ���������� � ��������� �����
void Out(container& c, ofstream& ofst);

void QuickSort(container& c);

void qsortRecursive(double* mas, int size, container& c);

#endif
