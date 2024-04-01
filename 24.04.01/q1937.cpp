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

int n;
int arr[501][501];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int dp[501][501]; // x,y 에서 갈 수 있는 최대 거리
int answer = 0;
int DFS(int x, int y);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int temp;
			cin >> temp;
			arr[i][j] = temp;

			dp[i][j] = 0;
		}
	}

	// 해당 위치 주변에 자기보다 작은 수의 대나무를 가지고 있는 지역이 있다
	// = 작은 수의 대나무 지역에서 시작하면 더 많은 위치를 이동할 수 있으므로 해당 위치는 시작점이 될 수 없다
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			bool b_small = false;
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
				{
					if (arr[i][j] > arr[nx][ny])
					{
						b_small = true;
						break;
					}
				}
			}
			if (!b_small)
				q.push({ i, j });
		}
	} // 주변에 해당 지점보다 작은 대나무를 가진 곳이 없는 곳만 시작점의 기준으로 삼는다.

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 자기보다 높은곳으로만 갈 것이므로 visit 배열은 굳이 필요없다.
		answer = max(answer, DFS(x, y));
	}

	cout << answer;
}

int DFS(int x, int y)
{
	if (dp[x][y] != 0)
		return dp[x][y];

	bool b_around = false;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && arr[nx][ny] > arr[x][y])
		{
			dp[x][y] = max(dp[x][y], DFS(nx, ny) + 1);
			b_around = true;
		}
	}

	if (b_around)
	{
		return dp[x][y];
	}
	else
	{
		return dp[x][y] = 1; // 주변에 갈 곳이 없엇다.
	}
}