s = [
    ["A", "B", "C", "D", "E"],
    ["B", "B", "B", "C", "C"],
    ["C", "C", "C", "B", "B"],
    ["C", "C", "C", "B", "B"],
    ["B", "B", "B", "C", "C"],
]

n = int(input())
q_list = []
answer = {}

for i in range(n):
    ss = input()
    q_list.append(ss)
    answer[ss] = 0

for i in range(5):
    for j in range(3):
        if s[i][j] + s[i][j + 1] + s[i][j + 2] in q_list:
            answer[s[i][j] + s[i][j + 1] + s[i][j + 2]] += 1

for i in range(3):
    for j in range(5):
        if s[i][j] + s[i + 1][j] + s[i + 2][j] in q_list:
            answer[s[i][j] + s[i + 1][j] + s[i + 2][j]] += 1

for i in range(3):
    for j in range(3):
        if s[i][j] + s[i + 1][j + 1] + s[i + 2][j + 2] in q_list:
            answer[s[i][j] + s[i + 1][j + 1] + s[i + 2][j + 2]] += 1

for key, val in answer.items():
    print("{0} {1}".format(key, val))
