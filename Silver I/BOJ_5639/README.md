# BOJ_5639 - 이진 검색 트리

&nbsp;오랜만에 구조체 구현했는데 `insert`에서 에러가 너무 많이 나서 헤멨다 ㅠㅠ

## 문제/코드 링크

- [BOJ_5639 - 이진 검색 트리](https://www.acmicpc.net/problem/5639)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 후위 순회를 하는 함수 `PostOrder`와 삽입 함수 `Insert`를 만들어줬다.

- `getline(cin, str)`을 통해 입력의 끝을 몰라도 끝내줄 수 있다.

  - 참고로 `getline(cin, str)`을 사용하는 경우 공백이 있어도 편하게 입력받을 수 있다.

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;

typedef struct node {
    int key;
    node *left;
    node *right;

    node()
    {
        left = right = NULL;
    }
} node;

node *Insert(node *root, int target)
{
    if (root == NULL) {
        root = new node;
        root->key = target;
    }
    else {
        if (root->key < target) {  // 더 큰 경우 right
            root->right = SetPos(root->right, target);
        }
        else {  // 더 작은 경우 left
            root->left = SetPos(root->left, target);
        }
    }
    return root;
}

void PostOrder(node *root)
{
    if (root == NULL) {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->key << '\n';
}

int main()
{
    node *root = NULL;

    while (getline(cin, str)) {
        int cur = stoi(str);
        root = Insert(root, cur);
    }
    PostOrder(root);

    return 0;
}
```
