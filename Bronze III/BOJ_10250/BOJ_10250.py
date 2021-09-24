tc = int(input())

for _ in range(tc):
    info = list(map(int, input().split()))
    info[2] -= 1

    front_num = info[2] % info[0] + 1
    end_num = info[2] // info[0] + 1  # 몫에 1을 더해준다.

    front_num *= 100

    print(front_num + end_num)
