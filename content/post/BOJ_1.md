---
title: "BOJ_1041 주사위"
date: 2020-07-12T02:12:25+09:00
categories: [
	"BOJ",
]
tags: [
	"BOJ",
	"Baekjoon",
	"BOJ_1041",
]
cover: ""
draft: false
---

[[BOJ_1041](https://www.acmicpc.net/problem/1041) - [주사위](https://www.acmicpc.net/problem/1041)]

처음에 주사위의 값들이 이동할 수 있다고 생각하고 6개의 값을 sort한 후에 풀었다..(당연히 그렇게 푸는거 아님)

# 풀이

- 5개의 면 중 3개의 면이 드러나는 주사위는 `4개`, 2개의 면이 드러나는 주사위는 `8n - 12개`,<br>1개의 면이 드러나는 주사위는 `5n^2 - 16n + 12개`이다.

- 면이 3개인 주사위의 최소값 : 마주보는 면 중에서 더 작은 값들 3개의 합이 최소값이다.

- 면이 2개인 주사위의 최소값 : 하나하나 다 해봄..

  - 각각의 마주보는 면 중에서 더 작은 값 3개를 추출한 후에 그 3개를 이용하여 면 1, 2, 3개를 모두 계산하면 훨씬 쉽다.

- 면이 1개인 주사위의 최소값 : 6개의 면 중에서 가장 작은 값

# Code

```C++
#include <bits/stdc++.h>

using namespace std;

int main()
{
        long long n;
        cin >> n;

        vector<long long> dice;
        for (int i = 0; i < 6; ++i) {
                long long num;
                cin >> num;

                dice.push_back(num);
        }

        if (n == 1) {
                cout << dice[0] + dice[1] + dice[2] + dice[3] + dice[4] + dice[5] -
                            max({dice[0], dice[1], dice[2], dice[3], dice[4], dice[5]})
                     << '\n';
                return 0;
        }
        long long side_3 = 4;
        long long dice_3 = min(dice[0], dice[5]) + min(dice[1], dice[4]) + min(dice[2], dice[3]);
        long long side_2 = 8 * n - 12;
        long long dice_2 = 1000;
        for (int i = 0; i < 6; ++i) {
                for (int j = 0; j < 6; ++j) {
                        if (i == j)
                                continue;
                        if (i + j == 5)
                                continue;
                        dice_2 = min(dice_2, dice[i] + dice[j]);
                }
        }
        long long side_1 = 5 * n * n - 16 * n + 12;
        long long dice_1 = min({dice[0], dice[1], dice[2], dice[3], dice[4], dice[5]});

        long long answer = side_3 * dice_3 + side_2 * dice_2 + side_1 * dice_1;
        cout << answer << '\n';

        return 0;
}
```
