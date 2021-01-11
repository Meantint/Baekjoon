num_list = list(map(int, input().split(', ')))
answer = [i for i in num_list if i % 2 == 1]
print(', '.join(map(str, answer)))
