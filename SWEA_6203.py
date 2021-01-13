class score:
    def __init__(self, korean, math, english):
        self.korean = korean
        self.math = math
        self.english = english

    def total(self):
        return self.korean + self.math + self.english


score_list = list(map(int, input().split(', ')))
answer = score(score_list[0], score_list[1], score_list[2])
print("국어, 영어, 수학의 총점: {0}".format(answer.total()))
