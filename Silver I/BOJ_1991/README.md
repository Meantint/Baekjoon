# BOJ_1991 - 트리 순회

&nbsp;인접 그래프를 이용해 풀었다.

## 문제/코드 링크

- [BOJ_1991 - 트리 순회](https://www.acmicpc.net/problem/1991)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `preorder`, `inorder`, `postorder` 모두 왼쪽과 오른쪽 노드가 `'.' - 'A'`가 아닐 경우 자식 노드가 있는 것이다.

- `preorder`, `inorder`, `postorder` 각각 `VLR`, `LVR`, `LRV`를 적용시켜서 재귀 함수를 만들어주면 된다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
char v1, v2, v3;
vector<vector<int>> adj;

void preorder(int start)
{
    cout << (char)(start + 'A');
    if (adj[start][0] != '.' - 'A') {
        preorder(adj[start][0]);
    }
    if (adj[start][1] != '.' - 'A') {
        preorder(adj[start][1]);
    }
}

void inorder(int start)
{
    if (adj[start][0] != '.' - 'A') {
        inorder(adj[start][0]);
    }
    cout << (char)(start + 'A');
    if (adj[start][1] != '.' - 'A') {
        inorder(adj[start][1]);
    }
}

void postorder(int start)
{
    if (adj[start][0] != '.' - 'A') {
        postorder(adj[start][0]);
    }
    if (adj[start][1] != '.' - 'A') {
        postorder(adj[start][1]);
    }
    cout << (char)(start + 'A');
}

int main()
{
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v1 >> v2 >> v3;
        adj[v1 - 'A'].push_back(v2 - 'A');
        adj[v1 - 'A'].push_back(v3 - 'A');
    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';

    return 0;
}
```
