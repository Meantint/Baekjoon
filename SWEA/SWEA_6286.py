fibo_list = [1, 1]

[fibo_list.append(fibo_list[-2] + fibo_list[-1]) for i in range(2, 10)]
print(fibo_list)
