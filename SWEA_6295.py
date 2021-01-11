row, col = map(int, input().split(','))

answer = [[i * j for j in range(col)] for i in range(row)]
print(answer)
