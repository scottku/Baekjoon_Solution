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

int N;
int arr[101][101];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
bool visit[101][101];

class comp
{
public:
    bool operator() (const pair<int, pair<int, int>>& p1, const pair<int, pair<int, int>>& p2)
    {
        return p1.first > p2.first;
    }
};

int BFS(int num)
{
    int result = 0;

    queue<pair<int, int>> q;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (arr[i][j] == num)
            {
                visit[i][j] = true;
                q.push({ i,j });
            }
        }
    }

    while (!q.empty())
    {
        int q_size = q.size();
        for (int i = 0; i < q_size; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (xx >= 1 && xx <= N && yy >= 1 && yy <= N && !visit[xx][yy])
                {
                    if (arr[xx][yy] == 0) // 바다
                    {
                        visit[xx][yy] = true;
                        q.push({ xx, yy });
                    }
                    else
                    {
                        if (arr[xx][yy] != num) // 다른 섬
                        {
                            return result;
                        }
                    }
                }
            }
        }
        result++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }

    int num = 2; // 각 섬에 대한 번호를 붙이겠다 ( 2번부터 시작 )
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (arr[i][j] == 1) // 섬이라면
            {
                queue<pair<int, int>> q;
                q.push({ i, j });
                visit[i][j] = true;

                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    arr[x][y] = num;
                    for (int k = 0; k < 4; k++)
                    {
                        int xx = x + dx[k];
                        int yy = y + dy[k];
                        if (xx >= 1 && xx <= N && yy >= 1 && yy <= N && !visit[xx][yy])
                        {
                            visit[xx][yy] = true;
                            if (arr[xx][yy] == 1) // 시작점에 붙어있는 섬
                            {
                                q.push({ xx, yy });
                            }
                        }
                    }
                }
                num++;
            }
        }
    }

    int answer = INT_MAX;
    for (int i = 2; i < num; i++)
    {
        memset(visit, false, sizeof(visit));
        answer = min(answer, BFS(i));
    }

    cout << answer;
}