input_list = map(int, input().split())

answer = 0
for i in input_list:
    if i != 7:
        answer += i
    else:
        print('lucky')

print(answer)
