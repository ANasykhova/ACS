# ------------------------------------------------------------------------------
#  Shape.py - содержит описание фигуры (обобщающего типа данных)
# ------------------------------------------------------------------------------

from enum import Enum


class Color(Enum):
    INVALID_COLOR = 0
    RED = 1
    ORANGE = 2
    YELLOW = 3
    GREEN = 4
    BLUE = 5
    DARKBLUE = 6
    PURPLE = 7


# ------------------------------------------------------------------------------
#  Класс, обобщающий все имеющиеся фигуры.
class Shape:
    #  Ввод обобщенной фигуры из файла.
    def __init__(self, color):
        self.color = self.get_color(color)

    @staticmethod
    def get_color(color: int):
        if color == 1:
            return Color.RED
        elif color == 2:
            return Color.ORANGE
        elif color == 3:
            return Color.YELLOW
        elif color == 4:
            return Color.GREEN
        elif color == 5:
            return Color.BLUE
        elif color == 6:
            return Color.DARKBLUE
        elif color == 7:
            return Color.PURPLE
        else:
            return Color.INVALID_COLOR

    def get_str(self):
        if self.color == Color.RED:
            return "Red"
        elif self.color == Color.ORANGE:
            return "Orange"
        elif self.color == Color.YELLOW:
            return "Yellow"
        elif self.color == Color.GREEN:
            return "Green"
        elif self.color == Color.BLUE:
            return "Blue"
        elif self.color == Color.DARKBLUE:
            return "Darkblue"
        elif self.color == Color.PURPLE:
            return "Purple"
        else:
            return "Invalid color!"
