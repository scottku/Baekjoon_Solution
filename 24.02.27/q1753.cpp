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

#define INF 30000000;

int vertex, line;
vector < pair<int, int>> v_arr[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int arr[20001];

int main(void)
{
	scanf("%d %d", &vertex, &line);
	for (int i = 1; i <= vertex; i++)
	{
		arr[i] = INF;
	}
	int _start;
	scanf("%d", &_start);
	arr[_start] = 0;
	for (int i = 0; i < line; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		v_arr[u].push_back({ v,w }); // 점 u와 점 v가 연결되며 그 가중치는 w이다.
	}

	arr[_start] = 0;
	pq.push({ 0, _start });
	while (!pq.empty())
	{
		int v = pq.top().first;
		int num = pq.top().second;
		pq.pop();

		for (int i = 0; i < v_arr[num].size(); i++)
		{
			int destination = v_arr[num][i].first;
			int value = v_arr[num][i].second;

			if (v + value < arr[destination])
			{
				arr[destination] = v + value;
				pq.push({ v + value, destination });
			}
		}
	}

	for (int i = 1; i <= vertex; i++)
	{
		if (i == _start)
			printf("%d\n", 0);
		else if (arr[i] == 30000000) // 한번도 진입된 적 없음
			printf("%s\n", "INF");
		else
			printf("%d\n", arr[i]);
	}
}