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
#include <time.h>

using namespace std;

int n, m;
int arr[1001][1001];
#define INF 987654321
pair<int, vector<int>> answer[1001];

class comp
{
public:
	bool operator() (const pair<int, int>& p1, const pair<int, int>& p2)
	{
		return p1.first > p2.first;
	}
};

void Dijkstra(int _start, int _end)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	bool visit[1001];
	memset(visit, false, sizeof(visit));

	pq.push({ 0, _start });
	answer[_start].first = 0;
	answer[_start].second.push_back(_start);

	while (!pq.empty())
	{
		int value = pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		if (visit[pos])
			continue;
		visit[pos] = true;

		for (int i = 1; i <= n; i++)
		{
			if (i == pos)
				continue;

			if (arr[pos][i] != INF)
			{
				if (answer[i].first > value + arr[pos][i])
				{
					answer[i].first = value + arr[pos][i];
					answer[i].second = answer[pos].second;
					answer[i].second.push_back(i);

					pq.push({ value + arr[pos][i], i });
				}
			}
		}
	}
}

int main(void)
{
	for (int i = 0; i < 1001; i++)
	{
		answer[i] = { INF, vector<int>() };
		for (int j = 0; j < 1001; j++)
		{
			arr[i][j] = INF;
		}
	}

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to, value;
		cin >> from >> to >> value;
		if (arr[from][to] > value)
			arr[from][to] = value;
	}
	int from, to;
	cin >> from >> to;

	Dijkstra(from, to);

	cout << answer[to].first << '\n';
	cout << answer[to].second.size() << '\n';
	for (int i = 0; i < answer[to].second.size(); i++)
	{
		cout << answer[to].second.at(i) << ' ';
	}
}