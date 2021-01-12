num_list = [12, 24, 35, 70, 88, 120, 155]

answer = [val for idx, val in enumerate(
    num_list) if idx != 0 and idx != 4 and idx != 5]
print(answer)
