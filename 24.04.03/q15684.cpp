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

int N, M, H;
bool arr[31][11]; // a번째 라인에 가로선, b -> b+1을 잇는다
int answer = 987654321;

bool endGame()
{
    for (int i = 1; i <= N; i++)
    {
        int col = i;
        for (int j = 1; j <= H; j++)
        {
            if (arr[j][col])
                col++;
            else if (arr[j][col - 1])
                col--;
            else
            {

            }
        }
        if (col != i)
            return false;
    }
    return true;
}

void dfs(int n_line, int cnt)
{
    if (n_line == cnt)
    {
        if (endGame())
        {
            cout << n_line;
            exit(0);
        }
        return;
    }

    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; j <= H; ++j)
        {
            if (arr[j][i] || arr[j][i - 1] || arr[j][i + 1])
                continue; // 선 못그림
            arr[j][i] = true;
            dfs(n_line, cnt + 1);
            arr[j][i] = false; // 임시로 그린 선 리셋

            while (!arr[j][i - 1] && !arr[j][i + 1])
                j++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(arr, false, sizeof(arr));

    cin >> N >> M >> H;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
    }

    for (int i = 0; i < 4; i++)
    {
        dfs(i, 0);
    }

    cout << -1;
}