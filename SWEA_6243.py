s = input()

h_list = s.split()
answer = list(set(h_list))
answer.sort()
print(",".join(answer))
