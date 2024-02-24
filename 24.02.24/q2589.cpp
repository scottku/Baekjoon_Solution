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

bool arr[50][50];
bool visit[50][50];
int max_Length = 0;
int h, w;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main()
{
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			char c;
			scanf("%1c", &c);
			if ((int)c == (int)'\n')
			{
				j--;
				continue;
			}

			if ((int)c == (int)'W')
				arr[i][j] = false;
			else
				arr[i][j] = true;
		}
	}
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (arr[i][j]) // 땅이면
			{
				memset(visit, false, sizeof(visit));
				visit[i][j] = true;
				q.push({ {i,j},0 });
				while (!q.empty())
				{
					int _h = q.front().first.first;
					int _w = q.front().first.second;
					int _length = q.front().second;
					q.pop();

					bool b = true;
					for (int i = 0; i < 4; i++)
					{
						int _dx = _w + dx[i];
						int _dy = _h + dy[i];
						if (_dx >= 0 && _dx < w && _dy >= 0 && _dy < h && arr[_dy][_dx] && !visit[_dy][_dx])
						{
							b = false;
							visit[_dy][_dx] = true;
							q.push({ {_dy, _dx}, _length + 1 });
						}
					}
					if (b && _length > max_Length)
						max_Length = _length;
				}
			}
		}
	}
	printf("%d", max_Length);
}