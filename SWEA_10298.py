a, b, c = map(int, input().split())

if a == b == c:
    print("모두 같다")
elif a == b != c or a == c != b or a != b == c:
    print("일부 같다")
else:
    print("모두 다르다")
