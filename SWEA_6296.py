str_list = list(map(str, input().split(', ')))
# sort = 원본 변경, sorted = 원본 변경 안함
str_list.sort()
print(', '.join(str_list))
