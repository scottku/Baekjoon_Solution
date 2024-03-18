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

int height, width;
int arr[1001][1001];
pair<bool, bool> visit[1001][1001]; // 벽 뚫고 지나갔을 때 방문 여부, 그냥 지나갔을 때 방문 여부
queue<pair<pair<int, int>, pair<int, bool>>> q;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main(void)
{
	scanf("%d %d", &height, &width);
	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			arr[i][j] = 0;
			visit[i][j] = { false, false };

			int temp;
			scanf("%1d", &temp);
			arr[i][j] = temp;
		}
	}

	q.push({ {1, 1}, {1, true} });
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second.first;
		if (x == height && y == width)
		{
			printf("%d", dist);
			return 0;
		}
		bool breakable = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x_dx = x + dx[i];
			int y_dy = y + dy[i];

			if (x_dx == height && y_dy == width)
			{
				printf("%d", dist + 1);
				return 0;
			}

			if (x_dx >= 1 && x_dx <= height && y_dy >= 1 && y_dy <= width)
			{
				if (breakable) // 아직 벽을 뚫을 수 있는 상태
				{
					if (arr[x_dx][y_dy] == 0) // 벽 없는 곳
					{
						if (!visit[x_dx][y_dy].second) // 벽을 뚫지 않은 상태에서 해당 지점을 방문했는가?
						{
							visit[x_dx][y_dy].second = true;
							q.push({ {x_dx,y_dy}, {dist + 1, breakable } });
						}
					}
					else // 벽 있는 곳
					{
						if (!visit[x_dx][y_dy].first) // 이전에 뚫려본 적이 있는 벽인가?
						{
							visit[x_dx][y_dy].first = true;
							q.push({ {x_dx,y_dy},{dist + 1,false} });
						}
					}
				}
				else // 벽 뚫을 수 없는 상태
				{
					if (arr[x_dx][y_dy] == 0)
					{
						if (!visit[x_dx][y_dy].first) // 벽이 뚫린 상태에서 방문된 지점인가?
						{
							visit[x_dx][y_dy].first = true;
							q.push({ {x_dx,y_dy},{dist + 1,breakable } });
						}
					}
				}
			}
		}
	}

	printf("%d", -1);
}