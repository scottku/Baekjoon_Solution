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
int arr[65][65];

void isAllSame(int _x, int _y, int _range)
{
	int temp;
	bool b_temp = true;
	for (int i = _x; i < _x + _range / 2; i++) // 2사분면
	{
		if (!b_temp)
			break;

		for (int j = _y; j < _y + _range / 2; j++)
		{
			if (!b_temp)
				break;

			if (i == _x && j == _y)
				temp = arr[i][j];
			else
			{
				if (temp != arr[i][j])
					b_temp = false;
			}
		}
	}

	if (!b_temp) // 숫자가 동일하지 않다면
	{
		printf("%c", '(');
		isAllSame(_x, _y, _range / 2); // 왼쪽 위를 기준으로 다시 4등분 함
		printf("%c", ')');
	}
	else
	{
		printf("%d", temp);
	}

	b_temp = true;
	for (int i = _x; i < _x + _range / 2; i++) // 1~33 // 1사분면
	{
		if (!b_temp)
			break;

		for (int j = _y + _range / 2; j < _y + _range; j++) // 33 ~ 65
		{
			if (!b_temp)
				break;

			if (i == _x && j == _y + _range / 2)
				temp = arr[i][j];
			else
			{
				if (temp != arr[i][j])
					b_temp = false;
			}
		}
	}

	if (!b_temp) // 숫자가 동일하지 않다면
	{
		printf("%c", '(');
		isAllSame(_x, _y + _range / 2, _range / 2);
		printf("%c", ')');
	}
	else
	{
		printf("%d", temp);
	}

	b_temp = true;
	for (int i = _x + _range / 2; i < _x + _range; i++) // 1~33 // 3사분면
	{
		if (!b_temp)
			break;

		for (int j = _y; j < _y + _range / 2; j++) // 33 ~ 65
		{
			if (!b_temp)
				break;

			if (i == _x + _range / 2 && j == _y)
				temp = arr[i][j];
			else
			{
				if (temp != arr[i][j])
					b_temp = false;
			}
		}
	}

	if (!b_temp) // 숫자가 동일하지 않다면
	{
		printf("%c", '(');
		isAllSame(_x + _range / 2, _y, _range / 2);
		printf("%c", ')');
	}
	else
	{
		printf("%d", temp);
	}

	b_temp = true;
	for (int i = _x + _range / 2; i < _x + _range; i++) // 4사분면
	{
		if (!b_temp)
			break;

		for (int j = _y + _range / 2; j < _y + _range; j++)
		{
			if (!b_temp)
				break;

			if (i == _x + _range / 2 && j == _y + _range / 2)
				temp = arr[i][j];
			else
			{
				if (temp != arr[i][j])
					b_temp = false;
			}
		}
	}

	if (!b_temp) // 숫자가 동일하지 않다면
	{
		printf("%c", '(');
		isAllSame(_x + _range / 2, _y + _range / 2, _range / 2);
		printf("%c", ')');
	}
	else
	{
		printf("%d", temp);
	}
}

int main(void)
{
	memset(arr, 0, sizeof(arr));
	scanf("%d", &n);

	int _all = 0;
	bool b_all = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int temp;
			scanf("%1d", &temp);
			arr[i][j] = temp;

			if (!b_all)
				continue;

			if (i == 1 && j == 1)
				_all = temp;
			else
			{
				if (_all == temp)
					continue;
				else
					b_all = false;
			}
		}
	}

	if (b_all)
	{
		printf("%d", _all);
	}
	else
	{
		printf("%c", '(');
		isAllSame(1, 1, n);
		printf("%c", ')');
	}
}