//------------------------------------------------------------------------------
// Container.cpp - содержит функции обработки контейнера.
//------------------------------------------------------------------------------

#include "Container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера.
void Container::Init() {
    this->len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти).
void Container::Clear() {
    for (int i = 0; i < this->len; ++i) {
        delete this->cont[i];
    }
    this->len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока.
void Container::In(std::ifstream &ifst) {
    while (!ifst.eof()) {
        int input_type;
        ifst >> input_type;
        switch (input_type) {
            case 1:
                this->cont[this->len] = new Rectangle();
                this->cont[this->len]->In(ifst);
                ++(this->len);
                break;
            case 2:
                this->cont[this->len] = new Triangle();
                this->cont[this->len]->In(ifst);
                ++(this->len);
                break;
            case 3:
                this->cont[this->len] = new Circle();
                this->cont[this->len]->In(ifst);
                ++(this->len);
                break;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера.
void Container::InRnd(int size) {
    while (this->len < size) {
        int input_type = Random() % 3;
        switch (input_type) {
            case 0:
                this->cont[this->len] = new Rectangle();
                this->cont[this->len]->InRnd();
                ++(this->len);
                break;
            case 1:
                this->cont[this->len] = new Triangle();
                this->cont[this->len]->InRnd();
                ++(this->len);
                break;
            case 2:
                this->cont[this->len] = new Circle();
                this->cont[this->len]->InRnd();
                ++(this->len);
                break;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток.
void Container::Out(std::ofstream &ofst) {
    ofst << "Container contains " << this->len << " elements.\n";
    for (int i = 0; i < this->len; ++i) {
        ofst << i + 1 << ": ";
        this->cont[i]->Out(ofst);
    }
}

//------------------------------------------------------------------------------
// Быстрая сортировка контейнера по периметру.
void Container::Sort() {
	quickSort(this->cont, this->len);
}

void Container::quickSort(Shape* cont[], int size) {
	//Указатели в начало и в конец массива
	int i = 0;
	int j = size - 1;

	//Центральный элемент массива
	double mid = cont[size / 2]->Perimeter();

	//Делим массив
	do {
		//Пробегаем элементы, ищем те, которые нужно перекинуть 
		//в другую часть.
		
		//В левой части массива пропускаем(оставляем на месте)
		// элементы, которые меньше центрального
		while (cont[i]->Perimeter() < mid) {
			i++;
		}
		//В правой части пропускаем элементы, которые больше центрального
		while (cont[j]->Perimeter() > mid) {
			j--;
		}

		//Меняем элементы местами
		if (i <= j) {
			std::swap(cont[i], cont[j]);
			i++;
			j--;
		}
	} while (i <= j);


	//Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) {
		//"Левый кусок"
		quickSort(cont, j + 1);
	}
	if (i < size) {
		//"Првый кусок"
		quickSort(&cont[i], size - i);
	}
}
