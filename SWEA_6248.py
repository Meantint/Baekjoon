s = input()
answer = [val for idx, val in enumerate(s) if idx % 2 == 0]
print("".join(answer))
