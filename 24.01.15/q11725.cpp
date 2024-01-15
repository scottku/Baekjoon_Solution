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
#include <algorithm>
#include <queue>

using namespace std;

bool visit[100001];
vector<int> v[100001];
int answer[100001];

void findParent(int _start)
{
	visit[_start] = true;
	for (int i = 0; i < v[_start].size(); i++)
	{
		if (visit[v[_start][i]]) // 이미 방문했다면
			continue;
		answer[v[_start][i]] = _start;
		findParent(v[_start][i]);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int x, y;
	memset(visit, false, sizeof(visit));
	memset(answer, false, sizeof(answer));
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}

	findParent(1);

	for (int i = 2; i <= n; i++)
	{
		printf("%d\n", answer[i]);
	}
}