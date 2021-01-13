class Person:
    def __init__(self, gender="Unknown"):
        self.__gender = gender

    def getGender(self):
        return self.__gender


class Male(Person):
    def __init__(self):
        super().__init__("Male")


class Female(Person):
    def __init__(self):
        super().__init__("Female")


ans1 = Male()
ans2 = Female()
print(ans1.getGender())
print(ans2.getGender())
