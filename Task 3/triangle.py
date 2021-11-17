# ------------------------------------------------------------------------------
#  Triangle.py - содержит функции обработки треугольника
# ------------------------------------------------------------------------------

import math
from shape import Shape
from rnd import random


# ------------------------------------------------------------------------------
#  Треугольник.
class Triangle(Shape):
    #  Ввод треугольника из файла
    def __init__(self, x1 = 0, x2 = 0, y1 = 0, y2 = 0, x3 = 0, y3 = 0,
        color = 0):
        super().__init__(color)
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
        self.x3 = x3
        self.y3 = y3

    #  Случайный ввод треугольника
    def in_rnd(self):
        self.x1 = random()
        self.y1 = random()

        while True:
            self.x2 = random()
            self.y2 = random()
            if (self.x1 != self.x2) and (self.y1 != self.y2):
                break

        a = math.sqrt((self.x2 - self.x1) * (self.x2 - self.x1) + (self.y2 - self.y1) * (self.y2 - self.y1))

        while True:
            self.x3 = random()
            self.y3 = random()

            b = math.sqrt((self.x3 - self.x1) * (self.x3 - self.x1) +
                      (self.y3 - self.y1) * (self.y3 - self.y1))

            c = math.sqrt((self.x3 - self.x2) * (self.x3 - self.x2) +
                          (self.y3 - self.y2) * (self.y3 - self.y2))

            if (c < a + b) and (a < c + b) and (b < c + a):
                break

        self.color = super().get_color(random() % 7 + 1)

    #  Вывод треугольника в форматируемый поток
    def out(self):
        return f'It is Triangle: x1 = {self.x1}, y1 = {self.y1}, x2 = {self.x2}, y2 = {self.y2}, ' \
               f'x3 = {self.x3} , y3 = {self.y3}, Color = {super().get_str()}. Perimeter = {self.perimeter()}\n'

    #  Вычисление периметра треугольника.
    def perimeter(self):
        a = math.sqrt((self.x2 - self.x1) * (self.x2 - self.x1) +
                      (self.y2 - self.y1) * (self.y2 - self.y1))

        b = math.sqrt((self.x3 - self.x1) * (self.x3 - self.x1) +
                      (self.y3 - self.y1) * (self.y3 - self.y1))

        c = math.sqrt((self.x3 - self.x2) * (self.x3 - self.x2) +
                      (self.y3 - self.y2) * (self.y3 - self.y2))

        return a + b + c
