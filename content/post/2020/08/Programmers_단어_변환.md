---
title: "Programmers - 단어 변환"
date: 2020-08-14T14:12:09+09:00
categories:
- Programmers
tags:
- Programmers
- 프로그래머스
- 단어 변환
draft: false
---

[[프로그래머스](https://programmers.co.kr/learn/courses/30/lessons/43163) - [단어 변환](https://programmers.co.kr/learn/courses/30/lessons/43163)]

&nbsp;dfs를 이용한 완전 탐색으로 풀었다.

<hr>

# 풀이

- dfs 안에서 단어가 다른 개수를 저장하는 `diff`를 만들었다.

- 만약 `diff = 1`이라면 dfs 실행, 아니라면 dfs 실행하지 않는다.

- `str`과 `gv_target`의 값이 같다면 dfs를 `answer = min(answer, cnt)`를 실행 후 dfs를 종료한다.

<hr>

# Code

```c++
#include <bits/stdc++.h>

using namespace std;

bool isCheck[50];
int answer;
string gv_begin = "", gv_target = "";
vector<string> gv_words;

void dfs(int cur, string str, int cnt)
{
    if (cur == -1) {
    }
    else if (isCheck[cur]) {
        return;
    }
    if (str == gv_target) {
        answer = min(answer, cnt);
        return;
    }

    isCheck[cur] = true;
    int size = gv_words.size();
    for (int i = 0; i < size; ++i) {
        int diff = 0;
        int wordSize = gv_words[i].size();
        for (int j = 0; j < wordSize; ++j) {
            if (str[j] != gv_words[i][j]) {
                ++diff;
            }
        }
        if (diff == 1) {
            dfs(i, gv_words[i], cnt + 1);
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    memset(isCheck, 0, sizeof(isCheck));
    gv_begin = begin, gv_target = target;
    gv_words = words;
    answer = 2112345678;

    dfs(-1, begin, 0);

    if (answer == 2112345678) {
        answer = 0;
    }
    return answer;
}

int main()
{
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }) << '\n';
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" }) << '\n';
}
```

<hr>