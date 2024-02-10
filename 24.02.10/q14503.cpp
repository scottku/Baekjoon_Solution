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

int N, M;
int x, y, d;
int dx[4] = { -1, 0, 1, 0 }; // 행
int dy[4] = { 0, 1, 0, -1 }; // 열
int arr[50][50];

int main(void)
{
	memset(arr, 0, sizeof(arr));
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &x, &y, &d);
	for (int i = 0; i < N; i++)
	{
		for (int _j = 0; _j < M; _j++)
		{
			int temp;
			scanf("%d", &temp);
			arr[i][_j] = temp;
		}
	}

	int answer = 0;
	while (true)
	{
		if (arr[x][y] == 0) // 0 = 청소 안한곳
		{
			answer++; // 청소한 칸 갯수 추가
			arr[x][y] = -1; // 청소 한 곳으로 변경
		}
		bool b = false;
		int tc = 0;
		int d_temp = d;
		while (tc < 4)
		{
			d_temp -= 1;
			if (d_temp < 0)
				d_temp = 3;

			int _dx = x + dx[d_temp];
			int _dy = y + dy[d_temp];
			if (_dx >= 0 && _dx < N && _dy >= 0 && _dy < M)
			{
				if (arr[_dx][_dy] == 0)
				{
					b = true;
					break;
				}
			}
			tc++;
		}

		if (b)
		{
			d = d_temp;
			x += dx[d];
			y += dy[d];
		}
		else
		{
			int back_d = d - 2;
			if (back_d < 0)
				back_d += 4;
			x += dx[back_d];
			y += dy[back_d];
			if (x < 0 || x >= N || y < 0 || y >= M || arr[x][y] == 1)
				break;
		}
	}
	printf("%d", answer);
}