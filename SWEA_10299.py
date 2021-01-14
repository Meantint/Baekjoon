num = int(input())

num_list = list(map(int, input().split()))
num_list[num] = 'change'

print(' '.join(map(str, num_list)))
