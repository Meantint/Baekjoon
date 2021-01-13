class Rectangle:
    def __init__(self, row, col):
        self.__row = row
        self.__col = col

    def area(self):
        return self.__row * self.__col


ans = Rectangle(4, 5)
print("사각형의 면적: {0}".format(ans.area()))
