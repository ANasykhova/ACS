# ------------------------------------------------------------------------------
# Rectangle.py - содержит функции обработки прямоугольника.
# ------------------------------------------------------------------------------

from shape import Shape
from rnd import random


# ------------------------------------------------------------------------------
# Прямоугольник.
class Rectangle(Shape):
    # Ввод прямоугольника из файла.
    def __init__(self, x1 = 0, x2 = 0, y1 = 0, y2 = 0, color = 0):
        super().__init__(color)
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2

    # Случайный ввод прямоугольника.
    def in_rnd(self):
        self.x1 = random()
        self.y1 = random()
        while True:
            self.x2 = random()
            self.y2 = random()
            if (self.x1 != self.x2) and (self.y1 != self.y2):
                break

        self.color = super().get_color(random() % 7 + 1)

    # Вывод прямоугольника в форматируемый поток.
    def out(self):
        return f'It is Rectangle: x1 = {self.x1}, y1 = {self.y1}, x2 = {self.x2}, y2 = {self.y2}, ' \
               f'Color = {super().get_str()}. Perimeter = {self.perimeter()} \n'

    # Вычисление периметра прямоугольника.
    def perimeter(self):
        return 2.0 * abs(self.x2 - self.x1) + 2.0 * abs(self.y2 - self.y1)
