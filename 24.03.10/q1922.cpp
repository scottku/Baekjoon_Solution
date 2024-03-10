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

int n, m;
int arr[1001][1001];
#define INF 987654321
bool visit[1001];
int value[1001];

int main()
{
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < 1001; i++)
    {
        if (i == 1)
            value[i] = 0;
        else
            value[i] = INF;
        for (int j = 0; j < 1001; j++)
        {
            arr[i][j] = INF;
        }
    }
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int a, b, v;
        scanf("%d %d %d", &a, &b, &v);
        arr[a][b] = v;
        arr[b][a] = v;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 1 });
    while (!pq.empty())
    {
        int _v = pq.top().first;
        int _start = pq.top().second;
        pq.pop();
        if (visit[_start] || value[_start] != _v)
            continue;

        visit[_start] = true;
        for (int i = 1; i <= n; i++)
        {
            if (i == _start)
                continue;

            if (arr[_start][i] != INF)
            {
                if (visit[i])
                    continue;

                if (value[i] > arr[_start][i])
                {
                    value[i] = arr[_start][i];
                    pq.push({ value[i], i });
                }
            }
        }
    }

    int answer = 0;
    for (int i = 2; i <= n; i++)
    {
        if (value[i] != INF)
            answer += value[i];
    }
    printf("%d", answer);
}