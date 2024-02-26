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

int h, w;
int arr[9][9];
int t_arr[9][9];
vector<pair<int, int>> v;
int answer = 0;
int o_wall = 0;
int o_virus = 0;
int virus = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void DFS(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int _dx = x + dx[i];
		int _dy = y + dy[i];
		if (_dx > 0 && _dx <= h && _dy > 0 && _dy <= w && t_arr[_dx][_dy] == 0)
		{
			t_arr[_dx][_dy] = 2;
			virus++;
			DFS(_dx, _dy);
		}
	}
}

void findMN(int m, int n, int& x, int& y)
{
	x = m / n + 1;
	y = m % n + 1;
}

int main(void)
{
	memset(arr, 0, sizeof(arr));
	scanf("%d %d", &h, &w);
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			int temp;
			scanf("%d", &temp);
			arr[i][j] = temp;
			if (temp == 1)
				o_wall++;
			else if (temp == 2)
			{
				o_virus++;
				v.push_back({ i, j });
			}
		}
	}

	int _max = 0;
	for (int i = 0; i < h * w; i++)
	{
		int x1, y1;
		findMN(i, w, x1, y1);
		if (arr[x1][y1] != 0)
			continue;

		for (int j = i + 1; j < h * w; j++)
		{
			int x2, y2;
			findMN(j, w, x2, y2);
			if (arr[x2][y2] != 0)
				continue;

			for (int k = j + 1; k < h * w; k++)
			{
				int x3, y3;
				findMN(k, w, x3, y3);
				if (arr[x3][y3] != 0)
					continue;

				memcpy(t_arr, arr, sizeof(arr));
				t_arr[x1][y1] = 1;
				t_arr[x2][y2] = 1;
				t_arr[x3][y3] = 1;
				virus = 0;

				for (int p = 0; p < v.size(); p++)
				{
					DFS(v[p].first, v[p].second);
				}

				int land = 0;
				for (int i = 1; i <= h; i++)
				{
					for (int j = 1; j <= w; j++)
					{
						if (t_arr[i][j] == 0)
							land++;
					}
				}
				if (land > _max)
					_max = land;
				//_max = max(_max, land/*h * w - (o_wall + 3) - virus - o_virus*/);
			}
		}
	}

	printf("%d", _max);
}