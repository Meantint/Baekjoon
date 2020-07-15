---
title: "BOJ_1038 감소하는 수"
date: 2020-07-14T21:37:04+09:00
categories: [
	"BOJ",
]
tags: [
	"BOJ",
	"Baekjoon",
	"BOJ_1038",
]
cover: ""
draft: true
---

[[BOJ_1038](https://www.acmicpc.net/problem/1038) - [감소하는 수](https://www.acmicpc.net/problem/1038)]

낚시하려고 만든건지 N값이 쓸데없이 크다.<br>
감소하는 수의 가장 큰 수인 9876543210이 `N = 1022`이기 때문에..

# 풀이

- i + 1번째 자릿수의 값이 j일 때 나오는 경우의 수를 저장해놓는 vec 변수를 선언하였다.

<center>

| i, j  |    0 |    1 |    2 |    3 |    4 |    5 |    6 |    7 |    8 |    9 |
| :---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
|   0   |    1 |    1 |    1 |    1 |    1 |    1 |    1 |    1 |    1 |    1 |
|   1   |    0 |    1 |    2 |    3 |    4 |    5 |    6 |    7 |    8 |    9 |
|   2   |    0 |    0 |    1 |    3 |    6 |   10 |   15 |   21 |   28 |   36 |
|   3   |    0 |    0 |    0 |    1 |    4 |   10 |   20 |   35 |   56 |   84 |
|   4   |    0 |    0 |    0 |    0 |    1 |    5 |   15 |   35 |   70 |  126 |
|   5   |    0 |    0 |    0 |    0 |    0 |    1 |    6 |   21 |   56 |  126 |
|   6   |    0 |    0 |    0 |    0 |    0 |    0 |    1 |    7 |   28 |   84 |
|   7   |    0 |    0 |    0 |    0 |    0 |    0 |    0 |    1 |    8 |   36 |
|   8   |    0 |    0 |    0 |    0 |    0 |    0 |    0 |    0 |    1 |    9 |
|   9   |    0 |    0 |    0 |    0 |    0 |    0 |    0 |    0 |    0 |    1 |
</center>
<figcaption>vec[i][j] : i + 1번째 자릿수가 j일 때 만들 수 있는 모든 경우의 수(i + 1이 제일 큰 자릿수)</figcaption>

- vec[i][j] = vec[i - 1][0] + vec[i - 1][1] + ... + vec[i - 1][j - 1]

- `vec[0][0] = 1`이기 때문에 입력받은 값 `answer`에 `+1` 해주어야한다.

- `answer <= 0`이 되는 곳이 그 자릿수의 값이다.
  
  - 이 경우 `answer` 값을 `answer <= 0`이 되기 직전으로 


# Code

```C++
#include <bits/stdc++.h>

using namespace std;

int main()
{
        vector<vector<int>> vec(10, vector<int>(10, 0));
        vector<int> tmp(10, 1);
        vec[0] = tmp;
        for (int i = 1; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                        for (int k = 0; k < j; ++k) {
                                vec[i][j] += vec[i - 1][k];
                        }
                }
        }

        long long num = 0;

        int answer;
        cin >> answer;
        ++answer;
        for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                        answer -= vec[i][j];
                        if (answer <= 0) {
                                answer += vec[i][j];
                                num += (long long)pow(10, i) * (long long)j;
                                if (i != 0)
                                        i -= 2; // 한칸 내림
                                else {
                                        cout << num << '\n';
                                        return 0;
                                }
                                break;
                        }
                }
        }

        cout << "-1\n";
        return 0;
}
```