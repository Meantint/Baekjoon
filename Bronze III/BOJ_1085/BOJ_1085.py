# Python에서 여러개 값을 한 줄에 받을 수 있다.
x, y, w, h = map(int, input().split())
# Min 값을 추출해내는 것도 원하는 값들을 모두 넣고 편하게 처리할 수 있다(C++도 할 수 있긴함).
print(min(x, y, w - x, h - y))
