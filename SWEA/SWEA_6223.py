class Circle:
    def __init__(self, rad):
        self.__rad = rad

    def area(self):
        return (self.__rad ** 2) * 3.14


ans = Circle(2)
print("원의 면적: {0}".format(ans.area()))
