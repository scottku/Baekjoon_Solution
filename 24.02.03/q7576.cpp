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

int M, N;
int arr[1001][1001];
bool visit[1001][1001];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int _total = 0;
int _count = 0;
int _day = -1;

int main(void)
{
	memset(arr, 0, sizeof(arr));
	memset(visit, false, sizeof(visit));
	scanf("%d %d", &M, &N); // 가로, 세로
	queue<pair<pair<int, int>, int>> q;
	for (int i = 1; i <= N; i++) // 세로
	{
		for (int j = 1; j <= M; j++) // 가로
		{
			int temp;
			scanf("%d", &temp);
			arr[i][j] = temp;
			if (temp != -1)
				_total++;
			else
				visit[i][j] = true;

			if (temp == 1)
			{
				visit[i][j] = true;
				q.push({ {i,j},0 });
			}
		}
	}

	while (!q.empty())
	{
		int h = q.front().first.first;
		int w = q.front().first.second;
		int num = q.front().second;
		if (_day < num)
			_day = num;
		q.pop();
		_count++;

		for (int i = 0; i < 4; i++)
		{
			int _dw = w + dx[i];
			int _dh = h + dy[i];
			if (_dw >= 1 && _dw <= M && _dh >= 1 && _dh <= N && !visit[_dh][_dw])
			{
				visit[_dh][_dw] = true;
				q.push({ {_dh, _dw}, num + 1 });
			}
		}
	}

	if (_count != _total)
		printf("%d", -1);
	else
		printf("%d", _day);
}