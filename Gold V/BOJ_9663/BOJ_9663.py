import sys

n = int(sys.stdin.readline())
ans = 0  # 가능한 퀸 배치의 개수를 저장하는 변수

"""
nqueen에서 고려해야할 3가지

1. 행이 겹치는지

    - dfs로 각 행을 한 단계씩 나아가며 검사하는 것이기 때문에 자체 해결

2. 열이 겹치는지

    - 각 행이 몇번째 열에 퀸을 놓았는지 담아놓는 변수(여기서는 row_info) 생성

    - if row_info[prev_idx] == row_info[row_idx]:

3. 대각이 겹치는지

    - (비교 row - 현재 row)가 (비교 row의 col 위치 - 현재 row의 col 위치)와 절댓값이 같으면
      대각선 위치에 있는 것

    - if abs(prev_idx - row_idx) == abs(row_info[prev_idx] - row_info[row_idx]):
"""

row_info = [-1] * n


def dfs(row_idx):
    global ans
    if row_idx == n:  # 모든 행의 배치가 되었다면 가능한 경우
        ans += 1
        return

    for idx in range(0, n):
        row_info[row_idx] = idx

        for prev_idx in range(0, row_idx):  # 이전에 놓은 퀸들과 col, 대각선 검사
            # 열로 마주치는 경우
            if row_info[prev_idx] == row_info[row_idx]:
                break
            # 대각선으로 마주치는 경우
            if abs(prev_idx - row_idx) == abs(row_info[prev_idx] - row_info[row_idx]):
                break

        else:  # 아무 문제 없으면 다음 행으로 넘어간다.
            dfs(row_idx + 1)


dfs(0)

print(ans)
