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

int n, m;
int x, y;
int k;
int _map[20][20];
int arr_dice[7] = { 0 };
int dice_top = 1; // 시작은 1
int dice_n = 2; // north
int dice_e = 3; // east

void moveTheDice(int move_dir);

int main(void)
{
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			scanf("%d", &temp);
			_map[i][j] = temp;
		}
	}
	queue<int> q;
	for (int i = 0; i < k; i++)
	{
		int temp;
		scanf("%d", &temp);
		q.push(temp);
	}

	while (!q.empty())
	{
		int dir = q.front();
		q.pop();

		int dx, dy;
		switch (dir)
		{
		case 1: // 동
			dx = 0;
			dy = 1;
			break;
		case 2: // 서
			dx = 0;
			dy = -1;
			break;
		case 3: // 북
			dx = -1;
			dy = 0;
			break;
		case 4: // 남
			dx = 1;
			dy = 0;
			break;
		}

		if (x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < m)
		{
			x += dx;
			y += dy;

			moveTheDice(dir);

			if (_map[x][y] == 0)
				_map[x][y] = arr_dice[7 - dice_top];
			else
			{
				arr_dice[7 - dice_top] = _map[x][y];
				_map[x][y] = 0;
			}

			printf("%d\n", arr_dice[dice_top]);
		}
	}
}

void moveTheDice(int move_dir)
{
	int top = 0;
	int east = 0;
	int west = 0;
	int north = 0;
	int south = 0;

	switch (move_dir)
	{
	case 1: // 동
		top = dice_top;
		west = 7 - dice_e;
		dice_top = west;
		dice_e = top;
		break;
	case 2: // 서
		top = dice_top;
		east = dice_e;
		dice_top = east;
		dice_e = 7 - top;
		break;
	case 3: // 북
		top = dice_top;
		south = 7 - dice_n;
		dice_top = south;
		dice_n = top;
		break;
	case 4: // 남
		top = dice_top;
		north = dice_n;
		dice_top = north;
		dice_n = 7 - top;
		break;
	}
}