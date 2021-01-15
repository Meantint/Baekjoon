dummy = int(input())

s1 = input()
s2 = input()

isDone = False
answer = ""
for i in range(len(s1), 0, -1):
    for j in range(0, len(s1) - i + 1, 1):
        # 있다면
        if s2.find(s1[j:(j + i)]) != -1:
            answer = s1[j:(j + i)]
            isDone = True
            break
    if isDone:
        break

print(answer)
