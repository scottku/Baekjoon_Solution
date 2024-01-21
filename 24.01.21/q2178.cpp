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

using namespace std;

int arr[101][101];
int dp[101][101];
bool visit[101][101];
deque<pair<int, int>> dq_next;
int h, w;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void BFS(int _x, int _y)
{
	visit[_x][_y] = true;
	dq_next.push_back({ _x, _y });

	while (!dq_next.empty())
	{
		int x = dq_next.front().first;
		int y = dq_next.front().second;
		dq_next.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int d_x = x + dx[i];
			int d_y = y + dy[i];
			if (d_x >= 1 && d_x <= h && d_y >= 1 && d_y <= w)
			{
				if (arr[d_x][d_y] == 1 && visit[d_x][d_y] != 1)
				{
					dp[d_x][d_y] = dp[x][y] + 1;
					visit[d_x][d_y] = true;
					dq_next.push_back({ d_x, d_y });
				}
			}
		}
	}
}

int main(void)
{
	memset(arr, 0, sizeof(arr));
	memset(dp, 0, sizeof(dp));
	memset(visit, false, sizeof(visit));

	scanf("%d %d", &h, &w);

	int temp;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			scanf("%1d", &temp);
			arr[i][j] = temp;
		}
	}
	dp[1][1] = 1;
	BFS(1, 1);

	printf("%d", dp[h][w]);
}