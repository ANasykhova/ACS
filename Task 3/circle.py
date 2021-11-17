# ------------------------------------------------------------------------------
#  Circle.py - содержит функции обработки круга
# ------------------------------------------------------------------------------

from rnd import random
from shape import Shape
import math


# ------------------------------------------------------------------------------
#  Круг.
class Circle(Shape):
    # Ввод круга из файла.
    def __init__(self, x = 0, y = 0, r = 0, color = 0):
        super().__init__(color)
        self.x = x
        self.y = y
        self.r = r

    #  Случайный ввод круга.
    def in_rnd(self):
        self.x = random()
        self.y = random()
        self.r = random()
        self.color = super().get_color(random() % 7 + 1)

    #  Вывод круга в форматируемый поток.
    def out(self):
        return f'It is Circle: x = {self.x}, y = {self.y}, r = {self.r}, ' \
               f'Color = {super().get_str()}. Perimeter = {self.perimeter()}\n'

    #  Вычисление периметра круга.
    def perimeter(self):
        return 2.0 * math.pi * self.r

