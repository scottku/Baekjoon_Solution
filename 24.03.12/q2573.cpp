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
int arr[301][301];
bool b_arr[301][301];
bool visit[301][301];
int ice = 0;
int day = 0;
queue<pair<int, int>> q;

void melting();

int _count = 0;
bool b_current = false;
void iceDiv_dfs(int x, int y, bool _first);

int main(void)
{
	memset(arr, 0, sizeof(arr));
	memset(b_arr, false, sizeof(b_arr));
	scanf("%d %d", &height, &width);
	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			int temp;
			scanf("%d", &temp);
			arr[i][j] = temp;

			if (temp != 0)
			{
				b_arr[i][j] = true;
				ice++;
			}
		}
	}

	while (true)
	{
		melting();
		if (ice == 0)
			break;

		_count = 0;
		iceDiv_dfs(1, 1, true);

		if (ice > _count)
			break;
		// 매번 visit 배열을 false로 초기화 하면 301 * 301 * 1000 만 해도 연산이 1억번(얼추 1초) 근처로 진행됨
		// 어차피 모든 곳을 다 확인해서 visit 배열이 false -> true -> false -> true 로 변하니까 그걸 이용해서 초기화 작업을 없앰
		if (b_current)
			b_current = false;
		else
			b_current = true;
	}


	if (ice == 0) // 얼음 없다
		printf("%d", 0);
	else // 빙산이 나누어졌다
		printf("%d", day);
}

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void melting()
{
	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			if (b_arr[i][j])
			{
				for (int k = 0; k < 4; k++)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					if (x >= 1 && x <= height && y >= 1 && y <= width && !b_arr[x][y])
					{
						if (arr[i][j] > 0)
							arr[i][j] -= 1;
					}
				}
			}
		}
	}

	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			if (b_arr[i][j])
			{
				if (arr[i][j] == 0)
				{
					b_arr[i][j] = false;
					ice--;
				}
			}
		}
	}

	day++;
}

void iceDiv_dfs(int x, int y, bool _first)
{
	if (!b_current)
	{
		if (visit[x][y])
		{
			if (y + 1 > width)
			{
				if (x + 1 > height)
					return;
				else
					iceDiv_dfs(x + 1, 1, true);
			}
			else
				iceDiv_dfs(x, y + 1, true);

			return;
		}

		visit[x][y] = true;

		if (_first)
		{
			if (!b_arr[x][y])
			{
				if (y + 1 > width)
				{
					if (x + 1 > height)
						return;
					else
						iceDiv_dfs(x + 1, 1, true);
				}
				else
					iceDiv_dfs(x, y + 1, true);
			}
			else
			{
				_count++;
				for (int i = 0; i < 4; i++)
				{
					int _dx = x + dx[i];
					int _dy = y + dy[i];
					if (_dx >= 1 && _dx <= height && _dy >= 1 && _dy <= width && b_arr[_dx][_dy] && !visit[_dx][_dy])
					{
						_count++;
						iceDiv_dfs(_dx, _dy, false);
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int _dx = x + dx[i];
				int _dy = y + dy[i];
				if (_dx >= 1 && _dx <= height && _dy >= 1 && _dy <= width && b_arr[_dx][_dy] && !visit[_dx][_dy])
				{
					_count++;
					iceDiv_dfs(_dx, _dy, false);
				}
			}
		}
	}
	else
	{
		if (!visit[x][y])
		{
			if (y + 1 > width)
			{
				if (x + 1 > height)
					return;
				else
					iceDiv_dfs(x + 1, 1, true);
			}
			else
				iceDiv_dfs(x, y + 1, true);

			return;
		}

		visit[x][y] = false;

		if (_first)
		{
			if (!b_arr[x][y])
			{
				if (y + 1 > width)
				{
					if (x + 1 > height)
						return;
					else
						iceDiv_dfs(x + 1, 1, true);
				}
				else
					iceDiv_dfs(x, y + 1, true);
			}
			else
			{
				_count++;
				for (int i = 0; i < 4; i++)
				{
					int _dx = x + dx[i];
					int _dy = y + dy[i];
					if (_dx >= 1 && _dx <= height && _dy >= 1 && _dy <= width && b_arr[_dx][_dy] && visit[_dx][_dy])
					{
						_count++;
						iceDiv_dfs(_dx, _dy, false);
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int _dx = x + dx[i];
				int _dy = y + dy[i];
				if (_dx >= 1 && _dx <= height && _dy >= 1 && _dy <= width && b_arr[_dx][_dy] && visit[_dx][_dy])
				{
					_count++;
					iceDiv_dfs(_dx, _dy, false);
				}
			}
		}
	}
}