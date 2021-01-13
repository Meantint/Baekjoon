class Shape:
    def __init__(self, row, col):
        self.__row = row
        self.__col = col

    def area(self):
        return self.__row * self.__col


class Square(Shape):
    def __init__(self, length):
        self.__length = length

    def area(self):
        return self.__length ** 2


ans = Square(3)
print("정사각형의 면적: {0}".format(ans.area()))
