//------------------------------------------------------------------------------
// container_Constr.cpp - �������� ������� ��������� ����������.
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// ������������� ����������.
void Init(container& c, shape* arr, int size) {
    std::cout << "Start Init\n";
    c.cont = arr;
    c.len = size;
    std::cout << "End Init\n";
}

//------------------------------------------------------------------------------
// ������� ���������� �� ��������� (������������ ������)
void Clear(container& c) {
    delete[] c.cont;
    c.len = 0;
}

//------------------------------------------------------------------------------
// ���� ����������� ���������� �� ���������� ������
void In(container& c, ifstream& ifst) {
    while (!ifst.eof()) {
        In(ifst, c.cont[c.len]);
        c.len++;
    }
}

// ��������� ���� ����������� ����������
void InRnd(container& c, int size) {
    std::cout << "Start Rnd\n";
    c.len = size;
    for (int i = 0; i < size; i++) {
        InRnd(c.cont[i]);
    }
    std::cout << "End Rnd\n";
}

//------------------------------------------------------------------------------
// ����� ����������� ���������� � ��������� �����
void Out(container& c, ofstream& ofst) {
    for (int i = 0; i < c.len; i++) {
        Out(c.cont[i], ofst);
    }
}

//------------------------------------------------------------------------------
// ������� ���������� ���������� �� ���������.
void QuickSort(container& c) {
    int size = c.len;
    double* mas = new double[size];

    for (int i = 0; i < size; i++) {
        switch (c.cont->k) {
        case shape::RECTANGLE:
            mas[i] = Perimeter(c.cont->r);
            break;
        case shape::TRIANGLE:
            mas[i] = Perimeter(c.cont->t);
            break;
        case shape::CIRCLE:
            mas[i] = Perimeter(c.cont->c);
            break;
        default:
            mas[i] = Perimeter(c.cont->r);
            break;
        }
    }

    qsortRecursive(mas, size, c);
}


void qsortRecursive(double* mas, int size, container& c) {
    //��������� � ������ � � ����� �������
    int i = 0;
    int j = size - 1;

    //����������� ������� �������
    double mid = mas[size / 2];

    //����� ������
    do {
        //��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
        //� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
        while (mas[i] < mid) {
            i++;
        }
        //� ������ ����� ���������� ��������, ������� ������ ������������
        while (mas[j] > mid) {
            j--;
        }

        //������ �������� �������
        if (i <= j) {
            shape s = c.cont[i];
            c.cont[i] = c.cont[j];
            c.cont[j] = s;

            double tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //����������� ������, ���� ��������, ��� �����������
    if (j > 0) {
        //"����� �����"
        qsortRecursive(mas, j + 1, c);
    }
    if (i < size) {
        //"����� �����"
        qsortRecursive(&mas[i], size - i, c);
    }
}

