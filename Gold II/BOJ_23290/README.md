# BOJ_23290 - 마법사 상어와 복제

&nbsp;구현 문제. 문제에서 물고기 도는 방향이랑 실제 방향 순서랑 반대라서 헷갈렸다.

## 문제/코드 링크

- [BOJ_23290 - 마법사 상어와 복제](https://www.acmicpc.net/problem/23290)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 물고기, 상어가 이동 가능한 방향인지를 정하는 함수 `isFishSafe`, `isSharkSafe`를 따로 두었다.

  - 물고기는 피냄새가 나는 곳과 상어가 있는 곳을 갈 수 없어서 추가해줬다.

- 문제에서 주어진 1번부터 5번까지를 실행하는 `Simul` 함수를 만들었다.

- 모든 상어의 이동 케이스를 처리하는 `sharkMove` 함수를 만들었다.

- 나머지는 일반적인 구현 문제와 유사하다(삼성 SW 기출 문제와).

- 문제에서 유의할 점은 상어가 기존에 머물던 위치로 돌아오는 경우가 있기 때문에 `DFS` 형식으로 구현하였다면 `DFS` 재귀 호출 전에 처리하는 배열에 대한 값 변경 처리가 필요할 것이다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int m, s;

pair<int, int> sharkPos;
vector<vector<vector<int>>> fishInfo(4, vector<vector<int>>(4, vector<int>(8, 0)));
vector<vector<vector<int>>> newFishInfo(4, vector<vector<int>>(4, vector<int>(8, 0)));
vector<vector<int>> smellInfo(4, vector<int>(4, 0));

int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int maxFish = 0;             // 잡을 수 있는 물고기의 최대량
string maxFishMove = "555";  // 최대량을 잡는 이동방향, 상 좌 하 우 : 1, 2, 3, 4

bool isFishSafe(int y, int x)
{
    if (0 <= y && y < 4 && 0 <= x && x < 4 && smellInfo[y][x] == 0 && make_pair(y, x) != sharkPos) {
        return true;
    }
    return false;
}

bool isSharkSafe(int y, int x)
{
    if (0 <= y && y < 4 && 0 <= x && x < 4) {
        return true;
    }
    return false;
}

long long getFish()
{
    long long ret = 0;

    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            for (int dir = 0; dir < 8; ++dir) {
                ret += 1LL * fishInfo[r][c][dir];
            }
        }
    }

    return ret;
}

void sharkMove(int y, int x, int cnt, int killFish, string dirInfo)
{
    if (cnt == 3) {
        /* print test */
        // cout << "dirInfo, killFIsh :" << dirInfo << ", " << killFish << '\n';

        if (maxFish < killFish) {
            maxFish = killFish;
            maxFishMove = dirInfo;
        }
        else if (maxFish == killFish) {
            if (dirInfo < maxFishMove) {
                maxFishMove = dirInfo;
            }
        }

        return;
    }

    // 2, 1, 4, 3
    vector<string> dirMapping = {"2", "1", "4", "3"};
    for (int i = 0; i < 8; i += 2) {
        int fishInHere = 0;
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (!isSharkSafe(cy, cx)) {
            continue;
        }

        for (int dir = 0; dir < 8; ++dir) {
            fishInHere += newFishInfo[cy][cx][dir];
        }

        vector<int> temp = newFishInfo[cy][cx];
        newFishInfo[cy][cx] = vector<int>(8, 0);
        sharkMove(cy, cx, cnt + 1, killFish + fishInHere, dirInfo + dirMapping[i / 2]);
        newFishInfo[cy][cx] = temp;
    }
}

void Simul()
{
    // cout << "init\n";
    // init newFishInfo, maxFish, maxFishMove
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            for (int dir = 0; dir < 8; ++dir) {
                newFishInfo[r][c][dir] = 0;
            }
        }
    }
    maxFish = 0;
    maxFishMove = "555";

    // cout << "move fish\n";
    // move fish
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            for (int dir = 0; dir < 8; ++dir) {
                if (fishInfo[r][c][dir] != 0) {
                    int cr = r + dy[dir];
                    int cc = c + dx[dir];

                    if (isFishSafe(cr, cc)) {
                        newFishInfo[cr][cc][dir] += fishInfo[r][c][dir];
                    }
                    else {
                        int cnt = 0;
                        int findDir = dir;
                        while (cnt < 9 && !isFishSafe(cr, cc)) {
                            findDir = (findDir + 7) % 8;
                            cr = r + dy[findDir];
                            cc = c + dx[findDir];

                            ++cnt;
                        }
                        // 방법이 없는 경우
                        if (cnt == 9) {
                            newFishInfo[r][c][dir] += fishInfo[r][c][dir];
                        }
                        // 방법이 있는 경우
                        else {
                            newFishInfo[cr][cc][findDir] += fishInfo[r][c][dir];
                        }
                    }
                }
            }
        }
    }

    /* print test */
    // for (int r = 0; r < 4; ++r) {
    //     for (int c = 0; c < 4; ++c) {
    //         int ret = 0;
    //         for (int dir = 0; dir < 8; ++dir) {
    //             ret += newFishInfo[r][c][dir];
    //         }
    //         cout << ret << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // cout << "shark move\n";
    // find shark move
    sharkMove(sharkPos.first, sharkPos.second, 0, 0, "");

    /* print test */
    // cout << maxFish << ", " << maxFishMove << '\n';

    // cout << "1234\n";
    /* 상 좌 하 우 : 1 2 3 4 */
    for (int i = 0; i < 3; ++i) {
        if (maxFishMove[i] == '1') {
            --sharkPos.first;
        }
        else if (maxFishMove[i] == '2') {
            --sharkPos.second;
        }
        else if (maxFishMove[i] == '3') {
            ++sharkPos.first;
        }
        else if (maxFishMove[i] == '4') {
            ++sharkPos.second;
        }
        else {
            cout << "error!" << '\n';

            return;
        }

        bool fishExist = false;
        for (int dir = 0; dir < 8; ++dir) {
            if (newFishInfo[sharkPos.first][sharkPos.second][dir] != 0) {
                newFishInfo[sharkPos.first][sharkPos.second][dir] = 0;
                fishExist = true;
            }
        }
        if (fishExist) {
            smellInfo[sharkPos.first][sharkPos.second] = 3;
        }
    }

    // cout << "update smell\n";
    // update smell
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (smellInfo[r][c] != 0) {
                --smellInfo[r][c];
            }
        }
    }

    // newFishInfo, fishInfo 합치기
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            for (int dir = 0; dir < 8; ++dir) {
                fishInfo[r][c][dir] += newFishInfo[r][c][dir];
            }
        }
    }

    return;
}

int main()
{
    cin >> m >> s;
    int y, x, dir;
    for (int i = 0; i < m; ++i) {
        cin >> y >> x >> dir;

        ++fishInfo[y - 1][x - 1][dir - 1];
    }
    cin >> y >> x;
    sharkPos = make_pair(y - 1, x - 1);

    for (int i = 0; i < s; ++i) {
        Simul();

        /* print test */
        // for (int dir = 0; dir < 8; ++dir) {
        //     for (int r = 0; r < 4; ++r) {
        //         for (int c = 0; c < 4; ++c) {
        //             cout << fishInfo[r][c][dir] << ' ';
        //         }
        //         cout << '\n';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        /* print test */
        // for (int r = 0; r < 4; ++r) {
        //     for (int c = 0; c < 4; ++c) {
        //         int ret = 0;
        //         for (int dir = 0; dir < 8; ++dir) {
        //             ret += fishInfo[r][c][dir];
        //         }
        //         cout << ret << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }

    cout << getFish() << '\n';

    return 0;
}
```
