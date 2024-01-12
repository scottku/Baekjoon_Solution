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

using namespace std;

int _connect[1001][1001];
deque<int> dq;
int visit[1001];
int answer = 0;

void findConnectedElements(int start, int node, bool first)
{
	if (visit[start] != 1)
		visit[start] = 1;
	else
		return;

	for (int j = 1; j <= node; j++) // start 와 연결되어있는 모든 친구들을 찾아내 순서대로 찾아 들어간다
	{
		if (start == j) continue;

		if (_connect[start][j] == 1) // 연결되어 있다면
		{
			// 기존 연결된 기록 삭제
			_connect[start][j] = 0;
			_connect[j][start] = 0;
			// 그 친구랑 연결된 또 다른 친구를 찾으러 간다
			if (visit[j] != 1)
				findConnectedElements(j, node, false);
		}
	}

	if (first)
		answer++;
}

int main(void)
{
	memset(_connect, 0, sizeof(_connect));
	memset(visit, 0, sizeof(visit));

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int tempX, tempY;
		scanf("%d %d", &tempX, &tempY);
		_connect[tempX][tempY] = 1;
		_connect[tempY][tempX] = 1;
	}

	if (n == 1)
	{
		printf("%d", 1);
		return 0;
	}

	for (int i = 1; i <= n; i++)
		findConnectedElements(i, n, true);

	printf("%d", answer);
}