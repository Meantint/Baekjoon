---
title: "Programmers - 크레인 인형뽑기 게임"
date: 2020-07-09T22:10:55+09:00
categories:
- Programmers
tags:
- Programmers
- 프로그래머스
- 크레인 인형뽑기 게임
draft: false
---

[[프로그래머스](https://programmers.co.kr/learn/courses/30/lessons/64061) - [크레인 인형뽑기 게임](https://programmers.co.kr/learn/courses/30/lessons/64061)]

<hr>

# 풀이

- 인형들을 담아두는 basket(vector&lt;int&gt; 변수)을 선언하였다.

- 집은 인형과 바구니의 맨 위에 있는 인형이 같을 때 바구니 젤 위에 있는 인형을 제거해주었다.

- 집은 인형과 바구니의 맨 위에 있는 인형이 다를 때 집은 인형을 바구니의 맨 위에 올리고 종료한다.

<hr>

# Code

```C++
#include <bits/stdc++.h>

using namespace std;

// 바구니
vector<int> basket(0);
int answer = 0;

void change(vector<vector<int>>& board, int idx)
{
        int rowSize = board.size();
        for (int i = 0; i < rowSize; ++i) {
                // 배열의 원소 값이 0일 때
                if (board[i][idx - 1] == 0)
                        continue;
                // 바구니의 마지막 인형과 방금 넣은 인형이 같을 때
                if (!basket.empty() && board[i][idx - 1] == basket.back()) {
                        basket.pop_back();
                        board[i][idx - 1] = 0;
                        answer += 2;
                        break;
                }
                else {
                        basket.push_back(board[i][idx - 1]);
                        board[i][idx - 1] = 0;
                        break;
                }
        }
}

int solution(vector<vector<int>> board, vector<int> moves)
{
        int Size = moves.size();
        for (int i = 0; i < Size; ++i) {
                change(board, moves[i]);
        }

        return answer;
}
```

<hr>
