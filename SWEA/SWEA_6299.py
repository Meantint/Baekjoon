num_list = [12, 24, 35, 70, 88, 120, 155]
answer = [val for idx, val in enumerate(num_list) if idx % 2 == 1]
print(answer)
