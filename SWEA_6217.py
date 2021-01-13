class Student:
    def __init__(self, name):
        self.__name = name

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, name):
        self.__name = name


class GraduateStudent(Student):
    def __init__(self, name, major):
        super().__init__(name)
        self.__major = major

    @property
    def major(self):
        return self.__major

    @major.setter
    def major(self, major):
        self.__major = major


ans1 = Student("홍길동")
ans2 = GraduateStudent("이순신", "컴퓨터")

print("이름: {0}".format(ans1.name))
print("이름: {0}, 전공: {1}".format(ans2.name, ans2.major))
