from collections import deque


def DFS(adj, start):
    visitedOrder = []
    stack = [start]

    while stack:
        cur = stack.pop()
        if cur not in visitedOrder:
            visitedOrder.append(cur)
            stack.extend(sorted(adj[cur], reverse=True))

    return visitedOrder


def BFS(adj, start):
    visitedOrder = []
    queue = deque()

    queue.append(start)
    while queue:
        cur = queue.popleft()  # Equeueual "queue.front(); queue.pop()" in C++
        if cur not in visitedOrder:
            visitedOrder.append(cur)
            queue.extend(sorted(adj[cur]))

    return visitedOrder


# Input
n, m, v = map(int, input().split())
adj = [set([]) for _ in range(n + 1)]
for _ in range(m):
    v1, v2 = map(int, input().split())
    adj[v1].add(v2)
    adj[v2].add(v1)

# Test
# Set은 자동정렬이 되나?
# for info in adj:
#     print(info)

# DFS & BFS
# 리스트에 *를 붙이면 '[' ']' ','를 제외하고 출력이 된다.
print(*DFS(adj, v))
print(*BFS(adj, v))
