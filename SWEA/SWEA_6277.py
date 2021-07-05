n1 = int(input())
n2 = int(input())
n3 = int(input())
n4 = int(input())
n5 = int(input())
num_list = [n1, n2, n3, n4, n5]

div_list = [x / 5 for x in num_list]
answer = 0.0

for i in div_list:
    answer += i
print("입력된 값 {0}의 평균은 {1}입니다.".format(num_list, answer))
