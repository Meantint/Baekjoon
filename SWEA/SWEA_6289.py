num_list = [i for i in range(1, 21)]

answer = [i ** 2 for i in num_list if i % 3 != 0 or i % 5 != 0]
print(answer)
