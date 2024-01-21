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

int n;
int arr[25][25];
bool visit[25][25];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<int> v;
int temp = 0;

void BFS(int x, int y)
{
	if (visit[x][y]) // 방문했었으면 무시
		return;

	temp++;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int _dx = x + dx[i];
		int _dy = y + dy[i];

		if (_dx >= 0 && _dx < n && _dy >= 0 && _dy < n)
		{
			if (arr[_dx][_dy] == 1 && !visit[_dx][_dy])
			{
				BFS(_dx, _dy);
			}
		}
	}
}

void findStart(int x, int y, int size)
{
	//while (visit[size][size] != 1)
	{
		if (arr[x][y] != 1)
		{
			if (y + 1 >= size)
			{
				if (x + 1 >= size)
					return;
				else
					findStart(x + 1, 0, size);
			}
			else
			{
				findStart(x, y + 1, size);
			}

		}
		else
		{
			temp = 0;
			BFS(x, y);
			if (temp != 0)
				v.push_back(temp);

			if (y + 1 >= size)
			{
				if (x + 1 >= size)
					return;
				else
					findStart(x + 1, 0, size);
			}
			else
			{
				findStart(x, y + 1, size);
			}
		}
	}
}

int main(void)
{
	memset(arr, 0, sizeof(arr));
	memset(visit, false, sizeof(visit));

	scanf("%d", &n);
	int t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &t);
			arr[i][j] = t;
		}
	}

	findStart(0, 0, n);

	printf("%d\n", v.size());
	sort(v.begin(), v.end(), less<int>());
	for (int i = 0; i < v.size(); i++)
	{
		if (i == v.size() - 1)
			printf("%d", v[i]);
		else
			printf("%d\n", v[i]);
	}
}