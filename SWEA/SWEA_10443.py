tc = int(input())

answer = 0
str_list = []
for i in range(tc):
    str_list.append(input())

for i in str_list:
    answer += i.count("MINCO")

print(answer)
