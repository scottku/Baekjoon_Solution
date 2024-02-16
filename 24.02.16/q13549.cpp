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
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
bool visit[100001];

int main(void)
{
	memset(visit, false, sizeof(visit));
	scanf("%d %d", &n, &m);
	pq.push({ 0, n });

	int answer = 0;
	while (!pq.empty())
	{
		int time = pq.top().first;
		int num = pq.top().second;
		pq.pop();

		if (num == m)
		{
			printf("%d", time);
			break;
		}

		visit[num] = true;

		if (num + 1 <= 100000 && !visit[num + 1])
		{
			pq.push({ time + 1, num + 1 });
		}
		if (num - 1 >= 0 && !visit[num - 1])
		{
			pq.push({ time + 1, num - 1 });
		}
		if (num * 2 <= 100000 && !visit[num * 2])
		{
			pq.push({ time, num * 2 });
		}
	}
}