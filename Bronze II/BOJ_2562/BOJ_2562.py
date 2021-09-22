info = [[int(input()), i + 1] for i in range(9)]
# print(info)

print(*max(info), sep='\n')
