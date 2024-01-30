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

int h, w, k;
bool arr[101][101];
bool visit[101][101];
vector<int> v;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 }; // 상하좌우
int _count = 0;
int _area = 0;

void findArea(int x, int y, bool _start)
{
	if (x >= w) // 범위 밖이면
		return;

	if (_start) // 맨 처음 땅을 찾을 시작 지점을 구하는 상황
	{
		if (visit[x][y] || arr[x][y]) // 방문했거나, 사각형이 그려진 지역이라면
		{
			if (y + 1 >= h)
				findArea(x + 1, 0, true);
			else
				findArea(x, y + 1, true);
			return;
		}
		else // 방문하지 않았고, 시작이 가능한 지점이라면
		{
			_count++; // 땅의 시작
			_area++;
			visit[x][y] = true;
			for (int i = 0; i < 4; i++) // 해당 지점을 기준으로 탐색 시작
			{
				int x_dx = x + dx[i];
				int y_dy = y + dy[i];
				if (x_dx >= 0 && x_dx < w && y_dy >= 0 && y_dy < h && !visit[x_dx][y_dy] && !arr[x_dx][y_dy]) // 범위 내이며 방문한 적이 없고 이동 가능한 곳이다
				{
					visit[x_dx][y_dy] = true;
					_area++;
					findArea(x_dx, y_dy, false);
				}
			}
			// 땅 하나 탐색 완료
			v.push_back(_area);
			_area = 0; // 땅 크기 저장 후 초기화

			// 다시 땅이 시작되는 곳을 찾아 떠남
			if (y + 1 >= h)
				findArea(x + 1, 0, true);
			else
				findArea(x, y + 1, true);
		}
	}
	else // 처음 땅과 연결된 지점들을 찾는 중
	{
		// 방문하지 않았고 이동도 가능하며 범위 내의 점을 기준으로 입력되었으므로 따로 예외처리해줄 필요 없다.
		for (int i = 0; i < 4; i++) // 해당 지점을 기준으로 탐색 시작
		{
			int x_dx = x + dx[i];
			int y_dy = y + dy[i];
			if (x_dx >= 0 && x_dx < w && y_dy >= 0 && y_dy < h && !visit[x_dx][y_dy] && !arr[x_dx][y_dy]) // 범위 내이며 방문한 적이 없고 이동 가능한 곳이다
			{
				visit[x_dx][y_dy] = true;
				_area++;
				findArea(x_dx, y_dy, false);
			}
		}
	}
}

int main(void)
{
	memset(arr, false, sizeof(arr));
	memset(visit, false, sizeof(visit));
	scanf("%d %d %d", &h, &w, &k); // h = y, w = x
	for (int tc = 0; tc < k; tc++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int i = x1; i < x2; i++)
		{
			for (int j = y1; j < y2; j++)
			{
				arr[i][j] = true;
			}
		}
	}

	findArea(0, 0, true);

	sort(v.begin(), v.end(), less<int>());

	printf("%d\n", _count);
	for (int i = 0; i < _count; i++)
	{
		printf("%d ", v[i]);
	}
}