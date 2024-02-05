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
char arr[100][100];
bool visit[100][100];
bool visit_cb[100][100];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int _count = 0;

void findArea(int x, int y, char c, bool b_cb, bool b_first)
{
	if (b_cb)
	{
		if (visit_cb[x][y])
		{
			if (y + 1 >= n)
			{
				if (x + 1 < n)
					findArea(x + 1, 0, arr[x + 1][0], b_cb, true);
			}
			else
				findArea(x, y + 1, arr[x][y + 1], b_cb, true);

			return;
		}

		visit_cb[x][y] = true;
		if (b_first) // 처음 시작 위치를 잡으려고 한다.
		{
			_count++;
			for (int i = 0; i < 4; i++)
			{
				int _dx = x + dx[i]; // 위 아래
				int _dy = y + dy[i]; // 양 옆
				if ((int)c == (int)'R' || (int)c == (int)'G')
				{
					if (_dx >= 0 && _dx < n && _dy >= 0 && _dy < n && !visit_cb[_dx][_dy] && ((int)arr[_dx][_dy] == (int)'R' || (int)arr[_dx][_dy] == (int)'G'))
					{
						findArea(_dx, _dy, c, b_cb, false);
					}
				}
				else // c == 'B'
				{
					if (_dx >= 0 && _dx < n && _dy >= 0 && _dy < n && !visit_cb[_dx][_dy] && (int)arr[_dx][_dy] == (int)c)
					{
						findArea(_dx, _dy, c, b_cb, false);
					}
				}
			}

			if (y + 1 >= n)
			{
				if (x + 1 < n)
					findArea(x + 1, 0, arr[x + 1][0], b_cb, true);
			}
			else
				findArea(x, y + 1, arr[x][y + 1], b_cb, true);
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int _dx = x + dx[i]; // 위 아래
				int _dy = y + dy[i]; // 양 옆
				if ((int)c == (int)'R' || (int)c == (int)'G')
				{
					if (_dx >= 0 && _dx < n && _dy >= 0 && _dy < n && !visit_cb[_dx][_dy] && ((int)arr[_dx][_dy] == (int)'R' || (int)arr[_dx][_dy] == (int)'G'))
					{
						findArea(_dx, _dy, c, b_cb, false);
					}
				}
				else // c == 'B'
				{
					if (_dx >= 0 && _dx < n && _dy >= 0 && _dy < n && !visit_cb[_dx][_dy] && (int)arr[_dx][_dy] == (int)c)
					{
						findArea(_dx, _dy, c, b_cb, false);
					}
				}
			}
		}
	}
	else
	{
		if (visit[x][y])
		{
			if (y + 1 >= n)
			{
				if (x + 1 < n)
					findArea(x + 1, 0, arr[x + 1][0], b_cb, true);
			}
			else
				findArea(x, y + 1, arr[x][y + 1], b_cb, true);

			return;
		}

		visit[x][y] = true;
		if (b_first) // 처음 시작 위치를 잡으려고 한다.
		{
			_count++;
			for (int i = 0; i < 4; i++)
			{
				int _dx = x + dx[i]; // 위 아래
				int _dy = y + dy[i]; // 양 옆
				if (_dx >= 0 && _dx < n && _dy >= 0 && _dy < n && !visit[_dx][_dy] && (int)arr[_dx][_dy] == (int)c)
				{
					findArea(_dx, _dy, c, b_cb, false);
				}
			}

			if (y + 1 >= n)
			{
				if (x + 1 < n)
					findArea(x + 1, 0, arr[x + 1][0], b_cb, true);
			}
			else
				findArea(x, y + 1, arr[x][y + 1], b_cb, true);
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int _dx = x + dx[i]; // 위 아래
				int _dy = y + dy[i]; // 양 옆
				if (_dx >= 0 && _dx < n && _dy >= 0 && _dy < n && !visit[_dx][_dy] && (int)arr[_dx][_dy] == (int)c)
				{
					findArea(_dx, _dy, c, b_cb, false);
				}
			}
		}
	}
}

int main(void)
{
	memset(visit, false, sizeof(visit));
	memset(visit_cb, false, sizeof(visit_cb));

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char t;
			scanf("%c", &t);
			if ((int)t == (int)'\n')
			{
				j -= 1;
				continue;
			}
			arr[i][j] = t;
		}
	}

	findArea(0, 0, arr[0][0], false, true); // x, y, 문자, 색약인가?, 첫 시작점인가?
	printf("%d ", _count);
	_count = 0;
	findArea(0, 0, arr[0][0], true, true);
	printf("%d", _count);
}