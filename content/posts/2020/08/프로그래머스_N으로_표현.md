---
title: "프로그래머스 - N으로 표현"
date: 2020-08-11T17:17:50+09:00
categories:
- Programmers
tags:
- Programmers
- 프로그래머스
- N으로 표현
draft: false
---

[[프로그래머스](https://programmers.co.kr/learn/courses/30/lessons/42895) - [N으로 표현](https://programmers.co.kr/learn/courses/30/lessons/42895)]

&nbsp;[https://woongsin94.tistory.com/232](https://woongsin94.tistory.com/232)를 참고하여 풀었습니다.

&nbsp;처음에 dp로 풀면서 `dp[1] = 2`, `dp[11] = 3`, `dp[111] = 4` ... 이런 식으로 지정 해놓고 풀었는데 한번의 dfs에서 재귀로 호출하는 dfs가 12개..가 넘는 대참사가 일어나서 결국 인터넷을 뒤적뒤적거렸다.

&nbsp;참조한 코드를 보면서 특수 케이스(1, 11, 111...)을 어떻게 for문 안에 저런 식으로 표현하지라고 감탄했다.

<hr>

# 풀이

- dp가 아닌 dfs로 해결하였다.

- `N`부터 `NNNNNNNN`까지 순차적으로 늘어나면서 for문을 돈다.

- `(55 / 5) + (5 / 5)` 같은 경우 나타낼 수 없지 않나?라고 생각했는데 애초에 이 케이스 자체가 정답이 아닌 케이스다. `(55 + 5 / 5)`를 하면 위의 케이스 보다 1만큼 작은 값이 정답이 되기 때문이다.

- 한가지 더, 미리 `11`, `111`인 케이스일 때 쓰이는 숫자 개수를 저장 해놓았는데 이런식으로 한다면 예외 케이스가 존재한다.
  - `N = 5`, `number = 270`인 경우 `55 * 5 - 5`가 정답이기 때문에 `55`를 써야하는데 `11`을 저장해놓은 경우 정답을 제대로 도출할 수가 없다.

<hr>

# Code

```C++
#include <bits/stdc++.h>

using namespace std;

int gvN, gvnumber;
int gvAnswer = 9;

void dfs(int cnt, int cur)
{
    if (cnt > 8) {
        return;
    }
    if (cur == gvnumber) {
        gvAnswer = min(gvAnswer, cnt);
        return;
    }

    int n = 0;
    for (int i = 0; i < 8; ++i) {
        n = n * 10 + gvN;
        dfs(cnt + i + 1, cur + n);
        dfs(cnt + i + 1, cur - n);
        dfs(cnt + i + 1, cur * n);
        dfs(cnt + i + 1, cur / n);
    }
}

int solution(int N, int number)
{
    gvN = N, gvnumber = number;

    dfs(0, 0);
    int answer = gvAnswer;
    if (answer == 9) {
        answer = -1;
    }
    return answer;
}
```

<hr>