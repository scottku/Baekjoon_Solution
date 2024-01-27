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

using namespace std;

int n;
queue<pair<pair<int, int>, int>> q;

int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 }; // 10시 -> 7시
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
bool visit[300][300];

int main(void)
{
	memset(visit, false, sizeof(visit));
	scanf("%d", &n);
	for (int p = 0; p < n; p++)
	{
		int _width;
		scanf("%d", &_width);

		int x, y;
		scanf("%d %d", &x, &y);
		pair<int, int> _p = { x, y };
		int z, k;
		scanf("%d %d", &z, &k);

		q.push({ _p , 0 });
		visit[x][y] = true;
		while (!q.empty())
		{
			int x_current = q.front().first.first;
			int y_current = q.front().first.second;
			int _count = q.front().second;
			q.pop();

			if (x_current == z && y_current == k)
			{
				printf("%d\n", _count);
				break;
			}

			for (int i = 0; i < 8; i++)
			{
				int x_dx = x_current + dx[i];
				int y_dy = y_current + dy[i];

				if (x_dx >= 0 && x_dx < _width && y_dy >= 0 && y_dy < _width && !visit[x_dx][y_dy])
				{	// 사각형의 내부 & 방문한 적이 없음
					visit[x_dx][y_dy] = true;
					q.push({ {x_dx, y_dy}, _count + 1 });
				}
			}
		}

		while (!q.empty())
			q.pop();
		memset(visit, false, sizeof(visit));
	}
}