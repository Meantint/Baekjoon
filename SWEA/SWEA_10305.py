def AA(s):
    return s.upper()


def BB(i):
    return i + 10


lt = input().split()

answer = []
if lt[0].isdigit():
    answer.append(BB(int(lt[0])))
    answer.append(AA(lt[1]))
else:
    answer.append(AA(lt[0]))
    answer.append(BB(int(lt[1])))

print(' '.join(list(map(str, answer))))
