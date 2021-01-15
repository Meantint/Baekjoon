tc = int(input())
imo_list = []

for i in range(tc):
    imo_list.append(input())

answer = []
for imo in imo_list:
    new_str = ""
    i = 0
    while i < len(imo):
        if imo[i] == '(':
            new_str += '('
            i += 1
            while i < len(imo) and imo[i] == '(':
                i += 1
            i -= 1
        elif imo[i] == ')':
            new_str += ')'
            i += 1
            while i < len(imo) and imo[i] == ')':
                i += 1
            i -= 1
        elif imo[i] == '^' and i + 1 < len(imo) and imo[i + 1] == '^':
            new_str += '^^'
            i += 1
            while i + 1 < len(imo) and imo[i] == '^' and imo[i] == '^':
                i += 1
        else:
            new_str += imo[i]
        i += 1
    # print(new_str)

    i = 0
    new_str = list(new_str)
    while i < len(new_str):
        if i + 2 < len(new_str) and new_str[i] == '^' and new_str[i + 2] == '^':
            new_str[i + 1] = '_'
        i += 1
    answer.append(new_str)

for ans in answer:
    print(''.join(ans))
