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

#define INF 987654321
int N, M, X;
vector<pair<int, int>> graph[2][1001];
vector<int> dist[2];

void dijkstra(int k)
{
    dist[k][X] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, X });

    while (!pq.empty())
    {
        int m_c = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (m_c > dist[k][cur])
            continue;

        for (int i = 0; i < graph[k][cur].size(); i++)
        {
            int next = graph[k][cur][i].second;
            int n_c = m_c + graph[k][cur][i].first;
            if (n_c < dist[k][next])
            {
                dist[k][next] = n_c;
                pq.push({ n_c, next });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;
    for (int i = 0; i < M; i++)
    {
        int from, to, value;
        cin >> from >> to >> value;
        graph[0][from].push_back({ value, to });
        graph[1][to].push_back({ value, from });
    }
    dist[0].resize(N + 1, INF);
    dist[1].resize(N + 1, INF);

    dijkstra(0);

    dijkstra(1);

    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        answer = max(answer, dist[0][i] + dist[1][i]);
    }
    cout << answer;
}