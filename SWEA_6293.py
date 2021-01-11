num_list = list(map(int, input().split(',')))

pi = 3.1415

answer = [round(i * 2 * pi, 2) for i in num_list]
print(', '.join(map(str, answer)))
