#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <map>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

int K;
int W, H;
int arr[201][201];
bool visit[30][201][201];
int answer = 987654321;
queue<pair<pair<int, int>, pair<int, int>>> q; // (x, y) / (move_count, jump_count)

int d8x[] = { -2, -1, 1, 2, 2, 1 ,-1 ,-2 };// 1시부터 11시 방향으로
int d8y[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int d4x[] = { -1, 1, 0, 0 };
int d4y[] = { 0, 0, -1, 1 };

void BFS()
{
    int _count = 0;
    while (!q.empty())
    {
        int q_size = q.size();
        for (int qs = 0; qs < q_size; qs++)
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int move_count = q.front().second.first;
            int jump_count = q.front().second.second;
            q.pop();

            if (x == H && y == W)
            {
                cout << _count;
                exit(0);
                return;
            }

            if (jump_count < K)
            {
                for (int i = 0; i < 8; i++)
                {
                    int nx = x + d8x[i];
                    int ny = y + d8y[i];
                    if (nx >= 1 && nx <= H && ny >= 1 && ny <= W && arr[nx][ny] != 1)
                    {
                        if (!visit[jump_count + 1][nx][ny])
                        {
                            visit[jump_count + 1][nx][ny] = true;
                            q.push({ { nx, ny }, {move_count + 1, jump_count + 1} });
                        }
                    }
                }
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = x + d4x[i];
                int ny = y + d4y[i];
                if (nx >= 1 && nx <= H && ny >= 1 && ny <= W && arr[nx][ny] != 1)
                {
                    if (!visit[jump_count][nx][ny])
                    {
                        visit[jump_count][nx][ny] = true;
                        q.push({ { nx, ny }, {move_count + 1, jump_count} });
                    }
                }
            }
        }
        _count++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(arr, 0, sizeof(arr));

    cin >> K;
    cin >> W >> H;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }

    memset(visit, false, sizeof(visit));
    q.push({ { 1, 1 }, {0, 0} });
    BFS();

    cout << -1;
}