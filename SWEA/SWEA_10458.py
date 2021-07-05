n = int(input())

apt_list = list(map(int, input().split()))
real_apt_list = apt_list[:n + 1]

real_apt_list.reverse()
# print(real_apt_list)
answer = 1
max_h = real_apt_list[0]

for i in range(1, n + 1):
    if max_h <= real_apt_list[i]:
        answer += 1
        max_h = real_apt_list[i]

print(answer)
