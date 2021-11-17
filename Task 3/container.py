# ------------------------------------------------------------------------------
# Container.py - содержит функции обработки контейнера.
# ------------------------------------------------------------------------------

from rectangle import Rectangle
from circle import Circle
from triangle import Triangle
from rnd import random


# ------------------------------------------------------------------------------
# Простейший контейнер на основе одномерного массива
class Container:
    # Инициализация контейнера.
    def __init__(self):
        self.cont = []

    # Очистка контейнера от элементов(освобождение памяти).
    def clear(self):
        self.cont = []

    # Ввод содержимого контейнера из указанного потока.
    def in_file(self, path):
        with open(path, 'r') as file:
            for shape in file:
                try:
                    line = shape.strip().split()
                    if line[0] == "1":
                        self.cont.append(Rectangle(int(line[1]), int(line[2]), int(line[3]),
                                                   int(line[4]), int(line[5])))
                    elif line[0] == "2":
                        self.cont.append(Triangle(int(line[1]), int(line[2]), int(line[3]), int(line[4]),
                                                  int(line[5]), int(line[6]), int(line[7])))
                    elif line[0] == "3":
                        self.cont.append(Circle(int(line[1]), int(line[2]), int(line[3]), int(line[4])))
                except Exception:
                    raise ValueError("Invalid argument")

    # Случайный ввод содержимого контейнера.
    def in_rnd(self, size: int):
        while len(self.cont) < size:
            shape = random() % 3
            if shape == 0:
                self.cont.append(Rectangle())
            elif shape == 1:
                self.cont.append(Triangle())
            else:
                self.cont.append(Circle())
            self.cont[-1].in_rnd()

    # Вывод содержимого контейнера в указанный поток.
    def out(self, path):
        with open(path, 'w') as file:
            file.write("Filled container:\n")
            file.write(f'Container contains {len(self.cont)} elements.\n')
            i = 1
            for shape in self.cont:
                file.write(f'{i}: {shape.out()}')
                i += 1

    # Сортировка контейнера по возрастанию QuickSort.
    def sort(self):
        self.quicksort(self.cont, 0, len(self.cont))

    def quicksort(self, cont, start, end):
        if end - start > 1:
            p = self.partition(cont, start, end)
            self.quicksort(self.cont, start, p)
            self.quicksort(self.cont, p + 1, end)

    def partition(self, cont, start, end):
        cont = self.cont
        pivot = cont[start].perimeter()
        i = start + 1
        j = end - 1

        while True:
            while (i <= j) and (cont[i].perimeter() <= pivot):
                i = i + 1
            while (i <= j) and (cont[j].perimeter() >= pivot):
                j = j - 1

            if i <= j:
                cont[i], cont[j] = cont[j], cont[i]
            else:
                cont[start], cont[j] = cont[j], cont[start]
                return j
