num_list = list(map(int, input().split()))
answer = {}

for i in num_list:
    if i in answer:
        answer[i] += 1
    else:
        answer[i] = 1

for key, val in answer.items():
    if val == 1:
        print(key)
        break
