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

int height, width, t;
int arr[51][51];
int temp_arr[51][51];
int top = 0;
int down = 0;

void diffusion();
void air_cycle();

int main(void)
{
	memset(arr, 0, sizeof(arr));
	memset(temp_arr, 0, sizeof(temp_arr));
	scanf("%d %d %d", &height, &width, &t);
	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			int temp;
			scanf("%d", &temp);
			arr[i][j] = temp;
			if (temp == -1)
			{
				if (top == 0)
				{
					top = i;
					down = i + 1;
				}
			}
		}
	}
	int dt = 0;
	while (dt < t)
	{
		diffusion();
		air_cycle();
		dt++;
	}

	int answer = 0;
	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			answer += arr[i][j];
		}
	}
	printf("%d", answer + 2);
}

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void diffusion()
{
	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			if (arr[i][j] == -1)
				continue;

			int temp_count = 0;
			for (int k = 0; k < 4; k++)
			{
				int x = i + dx[k];
				int y = j + dy[k];
				if (x >= 1 && x <= height && y >= 1 && y <= width)
				{
					if (arr[x][y] != -1)
					{
						temp_arr[x][y] += arr[i][j] / 5;
						temp_count++;
					}
				}
			}
			if (temp_count != 0)
			{
				temp_arr[i][j] -= (arr[i][j] / 5) * temp_count;
			}
		}
	}

	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			if (arr[i][j] != -1)
			{
				arr[i][j] += temp_arr[i][j];
				if (arr[i][j] < 0)
					arr[i][j] = 0;

				temp_arr[i][j] = 0;
			}
		}
	}
}

void air_cycle()
{
	int x = top;
	int y = 2;
	int cur_dust = 0;
	int moving_dust = arr[x][y];
	while (arr[x][y] != -1)
	{
		if (x == top)
		{
			if (y != width)
			{
				cur_dust = arr[x][y + 1];
				arr[x][y + 1] = moving_dust; // 오른쪽으로 이동
				moving_dust = cur_dust;
				y++;
			}
			else
			{
				cur_dust = arr[x - 1][y];
				arr[x - 1][y] = moving_dust; // 위쪽으로 이동
				moving_dust = cur_dust;
				x--;
			}
		}
		else if (x == 1)
		{
			if (y != 1)
			{
				cur_dust = arr[x][y - 1];
				arr[x][y - 1] = moving_dust; // 왼쪽으로
				moving_dust = cur_dust;
				y--;
			}
			else
			{
				cur_dust = arr[x + 1][y];
				arr[x + 1][y] = moving_dust; // 아래쪽으로
				moving_dust = cur_dust;
				x++;
			}
		}
		else
		{
			if (y == width) // 오른쪽 끝
			{
				cur_dust = arr[x - 1][y];
				arr[x - 1][y] = moving_dust; // 위쪽으로 이동
				moving_dust = cur_dust;
				x--;
			}
			else
			{
				cur_dust = arr[x + 1][y];
				if (cur_dust == -1) // 청정기 위치
					break;
				arr[x + 1][y] = moving_dust; // 아래쪽으로
				moving_dust = cur_dust;
				x++;
			}
		}
	} // 청정기가 위치한 좌표에서 out -> 청정기 바로 오른쪽 좌표는 0으로 변경
	arr[x + 1][y + 1] = 0;

	x = down;
	y = 2;
	cur_dust = 0;
	moving_dust = arr[x][y];
	while (arr[x][y] != -1)
	{
		if (x == down)
		{
			if (y != width)
			{
				cur_dust = arr[x][y + 1];
				arr[x][y + 1] = moving_dust; // 오른쪽으로 이동
				moving_dust = cur_dust;
				y++;
			}
			else
			{
				cur_dust = arr[x + 1][y];
				arr[x + 1][y] = moving_dust;
				moving_dust = cur_dust;
				x++;
			}
		}
		else if (x == height)
		{
			if (y != 1)
			{
				cur_dust = arr[x][y - 1];
				arr[x][y - 1] = moving_dust; // 왼쪽으로
				moving_dust = cur_dust;
				y--;
			}
			else
			{
				cur_dust = arr[x - 1][y];
				arr[x - 1][y] = moving_dust; // 아래쪽으로
				moving_dust = cur_dust;
				x--;
			}
		}
		else
		{
			if (y == width) // 오른쪽 끝
			{
				cur_dust = arr[x + 1][y];
				arr[x + 1][y] = moving_dust;
				moving_dust = cur_dust;
				x++;
			}
			else
			{
				cur_dust = arr[x - 1][y];
				if (cur_dust == -1) // 청정기 위치
					break;
				arr[x - 1][y] = moving_dust;
				moving_dust = cur_dust;
				x--;
			}
		}
	} // 청정기가 위치한 좌표에서 out -> 청정기 바로 오른쪽 좌표는 0으로 변경
	arr[x - 1][y + 1] = 0;
}