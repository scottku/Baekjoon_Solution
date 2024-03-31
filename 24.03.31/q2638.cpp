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

int N, M;
int arr[100][100];
int dx[] = { -1, 1, 0 ,0 };
int dy[] = { 0, 0, -1, 1 };
bool air[100][100];

bool isThereCheese()
{
    // 외곽은 무조건 치즈가 없기 때문에 0,0 에서 고정 시작
    memset(air, false, sizeof(air)); // 100 * 100 크기라 매번 초기화에 시간 부담 크게 없음
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] == 0)
            {
                if (!air[nx][ny]) // 공기의 위치를 BFS로 파악
                {
                    air[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!air[i][j]) // 공기가 아닌 곳이 있다.
                return true; // 치즈가 있다.
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }

    int answer = 0;
    while (isThereCheese())
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (arr[i][j] == 1)
                {
                    int air_count = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                        {
                            if (air[nx][ny]) // 공기의 위치를 파악했으니 치즈 주변 공기 여부만 파악하면 된다.
                                air_count++;
                        }
                    }
                    if (air_count > 1)
                        arr[i][j] = 0;
                }
            }
        }
        answer++;
    }

    cout << answer;
}